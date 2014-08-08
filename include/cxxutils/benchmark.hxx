#ifndef CXXUTILS_BENCHMARK_HXX
#define CXXUTILS_BENCHMARK_HXX

#include <mutex>
#include <functional>
#include <chrono>
#include <string>

namespace cxxutils
{
    class benchmark
    {
    public:
        typedef std::chrono::nanoseconds::rep duration_type;

        benchmark(std::string const & what, std::function<void (std::string const &, duration_type)> const & callback = [](std::string const &, duration_type){});
        ~benchmark();

        explicit operator bool() const { return true; }

    private:
        std::string what_;
        std::function<void (std::string const &, duration_type)> callback_;
        std::chrono::high_resolution_clock::time_point start_;
    };
}

#define CXXUTILS_BENCHMARK_HELPER(what, callback) if (::cxxutils::benchmark const & bm = ::cxxutils::benchmark(#what, callback))
#define CXXUTILS_BENCHMARK_NAME(what, callback) CXXUTILS_BENCHMARK_HELPER(what, callback)
#define CXXUTILS_BENCHMARK(callback) CXXUTILS_BENCHMARK_NAME(__func__, callback)

#endif // CXXUTILS_BENCHMARK_HXX
