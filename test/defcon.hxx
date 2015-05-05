/*************************************************
 * Copyright © 2015, afr-consulting GmbH         *
 *                                               *
 * See the file COPYING for copying permissions. *
 *************************************************/

#include <cxxtest/TestSuite.h>

#include <cxxutils/defcon.hxx>

#include <string>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <unordered_map>
#include <array>

class none_test : public CxxTest::TestSuite
{
public:
    void test_native_types()
    {
        using cxxutils::defcon;

        bool b = defcon;
        TS_ASSERT_EQUALS(b, false);

        char c = defcon;
        TS_ASSERT_EQUALS(c, '\0');

        short s = defcon;
        TS_ASSERT_EQUALS(s, 0);

        int i = defcon;
        TS_ASSERT_EQUALS(i, 0);

        long l = defcon;
        TS_ASSERT_EQUALS(l, 0l);

        long long ll = defcon;
        TS_ASSERT_EQUALS(ll, 0ll);

        float f = defcon;
        TS_ASSERT_EQUALS(f, .0f);

        double d = defcon;
        TS_ASSERT_EQUALS(d, .0);
    }

    void test_stl_types()
    {
        using cxxutils::defcon;

        // this one does not work with every compiler
        // then again std::string (or just string) is actually short enough
#if 0
        std::string s = defcon;
        TS_ASSERT(s.empty());
#endif // 0

        std::vector<int> vi = defcon;
        TS_ASSERT(vi.empty());

        std::map<int, int> mii = defcon;
        TS_ASSERT(mii.empty());

        std::list<int> li = defcon;
        TS_ASSERT(li.empty());

        std::deque<int> di = defcon;
        TS_ASSERT(di.empty());

        std::unordered_map<int, int> umii = defcon;
        TS_ASSERT(umii.empty());

        std::array<int, 10> ai10 = defcon;
        for (auto i : ai10)
            TS_ASSERT_EQUALS(i, 0);
    }
};
