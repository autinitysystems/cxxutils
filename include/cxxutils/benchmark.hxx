/*************************************************
 * Copyright © 2015, afr-consulting GmbH         *
 *                                               *
 * See the file COPYING for copying permissions. *
 *************************************************/

#ifndef CXXUTILS_BENCHMARK_HXX
#define CXXUTILS_BENCHMARK_HXX

/**
  \file benchmark.hxx

  \brief The benchmark class.

  This file contains a class that can be used to benchmark the performance of scopes.
 */

// Internal
#include <cxxutils/macros.hxx>

// Standard library
#include <mutex>
#include <functional>
#include <chrono>
#include <string>

namespace cxxutils
{
    /**
     *  \brief Class enabling you to benchmark a certain scope of code.
     *
     *  This class can be used to benchmark the performance of a certain scope of code.
     *  It is basically a RAII class which takes the start time in its constructor
     *  and the end time in its destructor.
     */
    class benchmark
    {
    public:
        /**
         *  \brief An integral type used to represent the duration measured.
         *
         *  duration_type is used to store number of nanoseconds measured. It is an integral type with atleast 64 bits.
         *  \see std::chrono::nanoseconds::rep
         */
        typedef std::chrono::nanoseconds::rep duration_type;

        /**
         *  \brief The constructor.
         *
         *  The constructor stores the start time so it can be used in the destructor.
         *
         *  \param [in] what A descriptive name for the scope that is benchmarked.
         *  \param [in] callback A function being called in the destructor. It is given the measured duration and the \a what parameter.
         */
        benchmark(std::string const & what, std::function<void (std::string const &, duration_type)> const & callback = [](std::string const &, duration_type){});

        /**
         *  \brief The destructor.
         *
         * The destructor uses the stored start time and the current time to measure the duration
         * a scope of code took to execute. It then calls \a callback with \a name and the measured \a duration.
         */
        ~benchmark();

    private:
        std::string what_;
        std::function<void (std::string const &, duration_type)> callback_;
        std::chrono::high_resolution_clock::time_point start_;
    };
}


#define CXXUTILS_BENCHMARK_HELPER(what, callback) CXXUTILS_WITH(::cxxutils::benchmark bm(#what, callback))
/**
 *  \def CXXUTILS_BENCHMARK_NAME(what, callback)
 *
 *  \brief Benchmark the following statement/scope.
 *
 *  \param what A descriptive name for the statement/scope being benchmarked.
 *  \param callback A callable thing (function pointer, functor, lamba expression) which is called after the time has been measured.
 *
 *  This macro allows you to benchmark the following statement/scope.
 *  It is equivalent to calling CXXUTILS_BENCHMARK_NAME with the name of the current function.
 */
#define CXXUTILS_BENCHMARK_NAME(what, callback) CXXUTILS_BENCHMARK_HELPER(what, callback)
/**
 *  \def CXXUTILS_BENCHMARK(callback)
 *
 *  \brief Benchmark the following statement/scope.
 *
 *  \param callback A callable thing (function pointer, functor, lamba expression) which is called after the time has been measured.
 *
 *  This macro allows you to benchmark the following statement/scope.
 *  It is equivalent to calling CXXUTILS_BENCHMARK_NAME with the name of the current function.
 */
#define CXXUTILS_BENCHMARK(callback) CXXUTILS_BENCHMARK_NAME(__func__, callback)

#endif // CXXUTILS_BENCHMARK_HXX
