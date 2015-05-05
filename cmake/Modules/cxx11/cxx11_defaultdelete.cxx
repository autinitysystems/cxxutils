/*************************************************
 * Copyright © 2015, afr-consulting GmbH         *
 *                                               *
 * See the file COPYING for copying permissions. *
 *************************************************/

struct foo
{
    foo() = default;
    ~foo() = default;
    foo(foo const &) = delete;
    foo & operator = (foo const &) = delete;
};

int main()
{
    return 0;
}
