/*************************************************
 * Copyright © 2015, afr-consulting GmbH         *
 *                                               *
 * See the file COPYING for copying permissions. *
 *************************************************/

#include <cxxutils/singleton.hxx>

#include <type_traits>
#include <string>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace test
{
    class singleton
        : public cxxutils::singleton<singleton>
    {
    public:
        singleton()
        {
        }

        virtual ~singleton()
        {
        }
    };
}

CXXUTILS_SINGLETON_IMPLEMENTATION(test::singleton)

TEST(Singleton, IsNonCopyable)
{
    using ::testing::Eq;

    EXPECT_THAT(std::is_copy_assignable<test::singleton>::value, Eq(false));
    EXPECT_THAT(std::is_copy_constructible<test::singleton>::value, Eq(false));
}

TEST(Singleton, WorksWithOneInstance)
{
    EXPECT_NO_THROW({ test::singleton instance; });
}

TEST(Singleton, ThrowsWithMoreInstance)
{
    EXPECT_THROW({
        test::singleton instance1;
        test::singleton instance2;
    }, cxxutils::singleton_error);
}

TEST(Singleton, ThrowsWhenAccessingNullByRef)
{
    EXPECT_THROW(test::singleton::instance(), cxxutils::singleton_error);
}

TEST(Singleton, ReturnNullWhenAccessingNullByPtr)
{
    using ::testing::Eq;

    EXPECT_NO_THROW(test::singleton::instance_ptr());
    EXPECT_THAT(test::singleton::instance_ptr(), Eq(nullptr));
}

TEST(Singleton, WorksWhenAccessingValid)
{
    using ::testing::Eq;

    test::singleton instance;

    EXPECT_NO_THROW(test::singleton::instance());
    EXPECT_THAT(test::singleton::instance_ptr(), Eq(std::addressof(instance)));
}
