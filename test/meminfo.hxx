/*************************************************
 * Copyright © 2015, afr-consulting GmbH         *
 *                                               *
 * See the file COPYING for copying permissions. *
 *************************************************/

#include <cxxtest/TestSuite.h>

#include <cxxutils/meminfo.hxx>
#include <cxxutils/config.hxx>

class meminfo_test : public CxxTest::TestSuite
{
public:
    void test_physmem()
    {
        TS_ASSERT_DIFFERS(cxxutils::meminfo::phys_total(), 0);
        TS_ASSERT_DIFFERS(cxxutils::meminfo::phys_avail(), 0);
    }
    
    void test_virtmem()
    {
#if defined(CXXUTILS_WIN32) || defined(CXXUTILS_LINUX)
        TS_ASSERT_DIFFERS(cxxutils::meminfo::virt_total(), 0);
        TS_ASSERT_DIFFERS(cxxutils::meminfo::virt_avail(), 0);
#else
        TS_SKIP("Cannot determine virtual memory on platforms other than Windows or Linux.");
#endif
    }
};
