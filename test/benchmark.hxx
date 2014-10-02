#include <cxxtest/TestSuite.h>

#include <cxxutils/benchmark.hxx>

#include <thread>
#include <chrono>

class benchmark_test : public CxxTest::TestSuite
{
public:
    void test_callback()
    {
        bool callback_has_been_called = false;
        CXXUTILS_BENCHMARK([&callback_has_been_called](std::string const &, cxxutils::benchmark::duration_type){
            callback_has_been_called = true;
        })
        {
        }

        TS_ASSERT(callback_has_been_called);
    }

    void test_accuracy()
    {
        CXXUTILS_BENCHMARK([](std::string const &, cxxutils::benchmark::duration_type duration){
            TS_ASSERT_DELTA(duration, 200000000, 1000000);
        })
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        }
    }
};
