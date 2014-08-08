#include <cxxutils/benchmark.hxx>
#include <cxxutils/macros.hxx>

namespace cxxutils
{
    benchmark::benchmark(const std::string &what, const std::function<void (const std::string &, benchmark::duration_type)> &callback)
        : what_(what)
        , callback_(callback)
        , start_(std::chrono::high_resolution_clock::now())
    {
    }

    benchmark::~benchmark()
    {
        static std::mutex mutex;
        std::lock_guard<std::mutex> lock(mutex);
        CXXUTILS_UNUSED(lock);

        callback_(what_,
            std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - start_).count()
        );
    }
}
