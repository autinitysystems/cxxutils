/*************************************************
 * Copyright © 2015, afr-consulting GmbH         *
 *                                               *
 * See the file COPYING for copying permissions. *
 *************************************************/

#include <cxxutils/noncopyable.hxx>

#include <type_traits>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(NonCopyable, IsNonCopyable)
{
    using ::testing::Eq;

    EXPECT_THAT(std::is_copy_assignable<cxxutils::noncopyable>::value, Eq(false));
    EXPECT_THAT(std::is_copy_constructible<cxxutils::noncopyable>::value, Eq(false));
}

TEST(NonCopyable, MakesChildClassesNonCopyable)
{
    using ::testing::Eq;

    struct dummy
        : private cxxutils::noncopyable
    {
    };

    EXPECT_THAT(std::is_copy_assignable<dummy>::value, Eq(false));
    EXPECT_THAT(std::is_copy_constructible<dummy>::value, Eq(false));
}
