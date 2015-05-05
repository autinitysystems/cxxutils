/*************************************************
 * Copyright © 2015, afr-consulting GmbH         *
 *                                               *
 * See the file COPYING for copying permissions. *
 *************************************************/

unsigned long long int operator "" _square(unsigned long long int n)
{
    return (n * n);
}

int main()
{
    return (3_square + 4_square) - 5_square;
}
