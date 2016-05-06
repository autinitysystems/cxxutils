/*************************************************
 * Copyright © 2015, afr-consulting GmbH         *
 *                                               *
 * See the file COPYING for copying permissions. *
 *************************************************/

#include <cxxutils/meminfo.hxx>
#include <cxxutils/config.hxx>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(MemInfo, PhysMemIsNotZero)
{
    using ::testing::Ne;

    EXPECT_THAT(cxxutils::meminfo::phys_total(), Ne(0));
    EXPECT_THAT(cxxutils::meminfo::phys_avail(), Ne(0));
}

#if defined(CXXUTILS_WIN32) || defined(CXXUTILS_LINUX)
TEST(MemInfo, VirtMemIsNotZero)
{
    using ::testing::Ne;

    EXPECT_THAT(cxxutils::meminfo::virt_total(), Ne(0));
    EXPECT_THAT(cxxutils::meminfo::virt_avail(), Ne(0));
}
#endif
