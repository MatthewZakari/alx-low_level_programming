#include "main.h"

/**
 * print_alphabet_x10 - Make alphabet inversely from z to a ten times
 *
 * return: always 0
 */
void print_alphabet_x10(void)
{

char ch;
int i = 0;

while (i < 10)
{
for (ch = 'a'; ch <= 'z'; ch++)
{
_putchar(ch);
}
_putchar('\n');
i++;
}


}
