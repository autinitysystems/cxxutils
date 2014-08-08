#include <cxxtest/TestSuite.h>

#include <cxxutils/none.hxx>

class none_test : public CxxTest::TestSuite
{
public:
    void test_native_types()
    {
        using cxxutils::none;

        bool b = none;
        TS_ASSERT_EQUALS(b, false);

        char c = none;
        TS_ASSERT_EQUALS(c, '\0');

        short s = none;
        TS_ASSERT_EQUALS(s, 0);

        int i = none;
        TS_ASSERT_EQUALS(i, 0);

        long l = none;
        TS_ASSERT_EQUALS(l, 0l);

        long long ll = none;
        TS_ASSERT_EQUALS(ll, 0ll);

        float f = none;
        TS_ASSERT_EQUALS(f, .0f);

        double d = none;
        TS_ASSERT_EQUALS(d, .0);
    }
};
