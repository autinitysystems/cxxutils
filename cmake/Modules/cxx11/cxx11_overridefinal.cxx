/*************************************************
 * Copyright © 2015, afr-consulting GmbH         *
 *                                               *
 * See the file COPYING for copying permissions. *
 *************************************************/

struct foo
{
    virtual int bar() = 0;
};

struct baz : foo
{
    virtual int bar() override final
    {
        return 0;
    }
};

int main()
{
    baz b;
    return b.bar();
}
