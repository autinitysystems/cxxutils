#include <cxxtest/TestSuite.h>

#include <cxxutils/meminfo.hxx>

class meminfo_test : public CxxTest::TestSuite
{
public:
    void test_functions()
    {
        /* if any of these returns 0 this is either an error or the operating system is not supported */
        TS_ASSERT_DIFFERS(cxxutils::meminfo::phys_total(), 0);
        TS_ASSERT_DIFFERS(cxxutils::meminfo::phys_avail(), 0);
        TS_ASSERT_DIFFERS(cxxutils::meminfo::virt_total(), 0);
        TS_ASSERT_DIFFERS(cxxutils::meminfo::virt_avail(), 0);
    }
};
