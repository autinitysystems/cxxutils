#ifndef CXXUTILS_SINGLETON_HXX
#define CXXUTILS_SINGLETON_HXX

/**
 *  \file singleton.hxx
 *
 *  \brief Parent class for singletons.
 *
 *  This file contains the singleton class template.
 *  Other classes become singletons when deriving from it.
 */

// Internal
#include <cxxutils/noncopyable.hxx>
#include <cxxutils/macros.hxx>

// Standard library
#include <stdexcept>
#include <string>
#include <mutex>

namespace cxxutils
{
    /**
     *  \brief The exception class used by \a singleton.
     *
     *  This class is thrown when something is wrong with a singleton.
     */
    class singleton_error
        : public std::runtime_error
    {
    public:
        static std::string const already_exists; ///< The message used when a second singleton instance is being constructed.
        static std::string const unexpected; ///< The message used when no instance exists but the destructor is called somehow...
        static std::string const access_non_existent; ///< The message used when the singleton instance shall be accessed but there is none.

        // Basically the constructors from std::runtime_error
        explicit singleton_error(std::string const & what_arg);
        explicit singleton_error(char const * what_arg);
    };

    /**
     *  \brief The singleton class template.
     *
     *  A class can derive from this class template to become a singleton.
     *
     *  \tparam Derived The inheriting class.
     *
     *  \see GoF: Singleton Pattern
     *
     *  \warning The singleton pattern is highly criticized and often considered an anti-pattern.
     *  So only use it when you are absolutely sure about it and use it with care.
     */
    template <typename Derived>
    class singleton
        : private noncopyable
    {
    public:
        typedef Derived derived_type; ///< The inheriting class type.

        /**
         *  \brief The default constructor.
         *
         *  The constructor ensures there can be only one instance of the singleton
         *  at any given time.
         *
         *  \throw cxxutil::singleton_error If a singleton instance already exists the message is cxxutils::singleton_error::already_exists.
         */
        singleton()
        {
            std::lock_guard<std::mutex> lock(mutex_);
            CXXUTILS_UNUSED(lock);

            if (instance_ != nullptr)
                throw singleton_error(singleton_error::already_exists);

            instance_ = static_cast<Derived *>(this);
        }

        /**
         *  \brief The destructor.
         *
         *  The destructor allows a new singleton instance to be created later.
         *
         *  \throw cxxutil::singleton_error In an extremely unlikely situation the message is cxxutils::singleton_error::unexpected.
         */
        virtual ~singleton()
        {
            std::lock_guard<std::mutex> lock(mutex_);
            CXXUTILS_UNUSED(lock);

            if (instance_ == nullptr)
                throw singleton_error(singleton_error::unexpected);

            instance_ = nullptr;
        }

        /**
         *  \brief Access the singleton instance.
         *
         *  This function gives access to the singleton instance.
         *  If there is none it simply returns a \a nullptr.
         *
         *  \return A pointer to the singleton instance or \a nullptr.
         */
        static derived_type * instance_ptr()
        {
            return instance_;
        }

        /**
         *  \brief Access the singleton instance.
         *
         *  This function gives access to the singleton instance.
         *  If there is none a cxxutil::singleton_error is thrown.
         *
         *  \return A reference to the singleton instance.
         *
         *  \throw cxxutil::singleton_error If no singleton instance exists the message is cxxutils::singleton_error::access_non_existent.
         */
        static derived_type & instance()
        {
            std::lock_guard<std::mutex> lock(mutex_);
            CXXUTILS_UNUSED(lock);

            if (instance_ == nullptr)
                throw singleton_error(singleton_error::access_non_existent);

            return (*instance_);
        }

        /**
         *  \brief Access the singleton's mutex.
         *
         *  This function returns a reference to the internal mutex.
         *  It can be used if you need to lock the mutex manually.
         *
         *  \return A reference to the singleton's mutex.
         */
        static std::mutex & mutex()
        {
            return mutex_;
        }

    private:
        static derived_type * instance_; ///< The unique singleton instance.
        static std::mutex mutex_; ///< The singleton's mutex for thread safety.
    };
}

/**
 *  \def CXXUTILS_SINGLETON_IMPLEMENTATION(name)
 *
 *  \brief Macro to define the static template member variables.
 *
 *  This macro can be used to define the static member variables \a instance_ and \a mutex_.
 *  Without defining them you will face "undefined reference" errors.
 *
 *  \param name The name of your singleton class.
 */
#define CXXUTILS_SINGLETON_IMPLEMENTATION(name) \
    template <> name * cxxutils::singleton<name>::instance_ = nullptr; \
    template <> std::mutex cxxutils::singleton<name>::mutex_ {};

#endif // CXXUTILS_SINGLETON_HXX
