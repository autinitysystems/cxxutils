#include <cxxtest/TestSuite.h>

#include <cxxutils/noncopyable.hxx>

#include <type_traits>

class noncopyable_test : public CxxTest::TestSuite
{
public:
    void test_noncopyable()
    {
#ifdef HAS_CXX11_DEFAULTDELETE
        TS_ASSERT_EQUALS(std::is_copy_assignable<cxxutils::noncopyable>::value, false);
        TS_ASSERT_EQUALS(std::is_copy_constructible<cxxutils::noncopyable>::value, false);

        struct dummy
            : private cxxutils::noncopyable
        {
        };

        TS_ASSERT_EQUALS(std::is_copy_assignable<dummy>::value, false);
        TS_ASSERT_EQUALS(std::is_copy_constructible<dummy>::value, false);
#else // !HAS_CXX11_DEFAULTDELETE
        TS_SKIP("noncopyable tests don't work with private functions");
#endif // HAS_CXX11_DEFAULTDELETE
    }
};
