#include <cxxtest/TestSuite.h>

#include <cxxutils/singleton.hxx>

#include <type_traits>
#include <string>

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

class singleton_test : public CxxTest::TestSuite
{
public:
    void test_noncopyable()
    {
        TS_ASSERT_EQUALS(std::is_copy_assignable<test::singleton>::value, false);
        TS_ASSERT_EQUALS(std::is_copy_constructible<test::singleton>::value, false);
    }

    void test_construction()
    {
        auto construct_twice = [](){
            test::singleton instance1;
            CXXUTILS_UNUSED(instance1);
            test::singleton instance2;
            CXXUTILS_UNUSED(instance2);
        };

        TS_ASSERT_THROWS_EQUALS(construct_twice(), cxxutils::singleton_error const & err, err.what(), std::string("A singleton instance already exists."));
    }
};
