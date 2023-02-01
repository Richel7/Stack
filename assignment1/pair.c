char opening_symbol[51];
char closing_symbol[51];
#include <string.h>

void pair(char list[])
{
    // e.g. list = "(,) [,] {,} a,b"
    int i; // counter for opening and closing symbols...
    int j; // countr for the chars stored in array list
    int len = strlen(list);

    for (i = 0, j = 0; j < len; i++, j += 4)
    {
        opening_symbol[i] = list[j];
        closing_symbol[i] = list[j + 2];
    }
    opening_symbol[i] = closing_symbol[i] = '\0';
}
