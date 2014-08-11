#ifndef CXXUTILS_SINGLETON_HXX
#define CXXUTILS_SINGLETON_HXX

#include "noncopyable.hxx"
#include "macros.hxx"

#include <stdexcept>
#include <string>
#include <mutex>

namespace cxxutils
{
    class singleton_error
        : public std::runtime_error
    {
    public:
        explicit singleton_error(std::string const & what_arg);
        explicit singleton_error(char const * what_arg);
    };

    template <typename Derived>
    class singleton
        : private noncopyable
    {
    public:
        typedef Derived derived_type;

        singleton()
        {
            std::lock_guard<std::mutex> lock(mutex_);
            CXXUTILS_UNUSED(lock);

            if (instance_ != nullptr)
                throw singleton_error("A singleton instance already exists.");

            instance_ = static_cast<Derived *>(this);
        }

        virtual ~singleton()
        {
            std::lock_guard<std::mutex> lock(mutex_);
            CXXUTILS_UNUSED(lock);

            if (instance_ == nullptr)
                throw singleton_error("Something really bad and unexplanable happened.");

            instance_ = nullptr;
        }

        static derived_type * instance_ptr()
        {
            return instance_;
        }

        static derived_type & instance()
        {
            std::lock_guard<std::mutex> lock(mutex_);
            CXXUTILS_UNUSED(lock);

            if (instance_ == nullptr)
                throw singleton_error("Trying to access non-existent singleton instance.");
        }

        static std::unique_lock<std::mutex> acquire_lock()
        {
            std::unique_lock<std::mutex> lock(mutex_, std::defer_lock);
            lock.lock();
            return lock;
        }

    private:
        static derived_type * instance_;
        static std::mutex mutex_;
    };
}

#define CXXUTILS_SINGLETON_IMPLEMENTATION(name) \
    template <> name * cxxutils::singleton<name>::instance_ = nullptr; \
    template <> std::mutex cxxutils::singleton<name>::mutex_ {};

#endif // CXXUTILS_SINGLETON_HXX
