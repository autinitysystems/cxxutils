/*************************************************
 * Copyright © 2015, afr-consulting GmbH         *
 *                                               *
 * See the file COPYING for copying permissions. *
 *************************************************/

#include <cxxutils/benchmark.hxx>

#include <thread>
#include <chrono>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(Benchmark, CallsCallback)
{
    using ::testing::Eq;

    bool callback_has_been_called = false;
    CXXUTILS_BENCHMARK([&callback_has_been_called](std::string const &, cxxutils::benchmark::duration_type){
        callback_has_been_called = true;
    })
    {
    }

    EXPECT_THAT(callback_has_been_called, Eq(true));
}

TEST(Benchmark, IsAccurate)
{
    CXXUTILS_BENCHMARK([](std::string const &, cxxutils::benchmark::duration_type duration){
        using ::testing::Gt;

        // the measured time can never be shorter than the time the code took to run
        EXPECT_THAT(duration, Gt(200000000));
    })
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}
