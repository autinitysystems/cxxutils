/*************************************************
 * Copyright © 2015, afr-consulting GmbH         *
 *                                               *
 * See the file COPYING for copying permissions. *
 *************************************************/

int main()
{
    int foo[] = { 42, 23, 1337 };
    int sum = 0;
    for (int n : foo)
        sum += n;
    return (sum != 1402);
}
