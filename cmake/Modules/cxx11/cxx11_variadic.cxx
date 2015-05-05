/*************************************************
 * Copyright © 2015, afr-consulting GmbH         *
 *                                               *
 * See the file COPYING for copying permissions. *
 *************************************************/

template <int... Types>
int size()
{
    return sizeof...(Types);
}

int main()
{
    return size<1, 2, 3, 4>() - 4;
}
