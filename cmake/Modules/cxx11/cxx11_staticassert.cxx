/*************************************************
 * Copyright © 2015, afr-consulting GmbH         *
 *                                               *
 * See the file COPYING for copying permissions. *
 *************************************************/

int main()
{
    static_assert(sizeof(char) == 1, "a character ALWAYS has the size 1");
    return 0;
}
