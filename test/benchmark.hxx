#include <cxxtest/TestSuite.h>

#include <cxxutils/benchmark.hxx>

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
};
