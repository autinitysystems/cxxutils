/*************************************************
 * Copyright © 2015, afr-consulting GmbH         *
 *                                               *
 * See the file COPYING for copying permissions. *
 *************************************************/

struct foo
{
    explicit operator bool () const
    {
        return true;
    }
};

int main()
{
    return 0;
}
