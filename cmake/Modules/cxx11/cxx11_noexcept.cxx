/*************************************************
 * Copyright © 2015, afr-consulting GmbH         *
 *                                               *
 * See the file COPYING for copying permissions. *
 *************************************************/

int foo_does_not_throw() noexcept // specifier
{
    return 0;
}

int main()
{
    if (noexcept(foo_does_not_throw)) // operator
        return foo_does_not_throw();
    else
        return 0;
}
