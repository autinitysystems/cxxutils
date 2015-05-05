/*************************************************
 * Copyright © 2015, afr-consulting GmbH         *
 *                                               *
 * See the file COPYING for copying permissions. *
 *************************************************/

enum class foo : int
{
    FOO = 0
};

int main()
{
    return static_cast<int>(foo::FOO);
}
