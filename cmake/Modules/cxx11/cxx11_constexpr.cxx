/*************************************************
 * Copyright © 2015, afr-consulting GmbH         *
 *                                               *
 * See the file COPYING for copying permissions. *
 *************************************************/

constexpr int square(int n)
{
    return (n * n);
}

int main()
{
    int values[square(1)] = { 0 };
    return values[0];
}
