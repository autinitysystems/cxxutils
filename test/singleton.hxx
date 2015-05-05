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
#ifdef CXX11_FEATURE_DEFAULTDELETE
        TS_ASSERT_EQUALS(std::is_copy_assignable<test::singleton>::value, false);
        TS_ASSERT_EQUALS(std::is_copy_constructible<test::singleton>::value, false);
#else // !CXX11_FEATURE_DEFAULTDELETE
        TS_SKIP("noncopyable tests don't work with private functions");
#endif // CXX11_FEATURE_DEFAULTDELETE
    }

    void test_construction()
    {
        auto construct_once = [](){
            test::singleton instance;
            CXXUTILS_UNUSED(instance);
        };

        TS_ASSERT_THROWS_NOTHING(construct_once());

        auto construct_twice = [](){
            test::singleton instance1;
            CXXUTILS_UNUSED(instance1);
            test::singleton instance2;
            CXXUTILS_UNUSED(instance2);
        };

        TS_ASSERT_THROWS_EQUALS(construct_twice(), cxxutils::singleton_error const & err, err.what(), cxxutils::singleton_error::already_exists);
    }

    void test_access()
    {
        TS_ASSERT_THROWS_EQUALS(test::singleton::instance(), cxxutils::singleton_error const & err, err.what(), cxxutils::singleton_error::access_non_existent);
        TS_ASSERT_THROWS_NOTHING(test::singleton::instance_ptr());
        TS_ASSERT_EQUALS(test::singleton::instance_ptr(), nullptr);

        test::singleton instance;
        CXXUTILS_UNUSED(instance);

        TS_ASSERT_THROWS_NOTHING(test::singleton::instance());
        TS_ASSERT_DIFFERS(test::singleton::instance_ptr(), nullptr);
        TS_ASSERT_EQUALS(test::singleton::instance_ptr(), std::addressof(instance));
    }
};
