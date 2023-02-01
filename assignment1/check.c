#define BUFSIZE 1000
#include <string.h>
static char buf[BUFSIZE]; // buffeer for opening symbols

static int bufp; // next free position in buf

void push(char c)
{
    buf[bufp] = c;
    bufp++;
}

char pop(void)
{
    if (is_empty())
        return '\0';
    bufp--;
    return buf[bufp];
}

char peek(void)
{
    return buf[bufp - 1];
}

int is_empty()
{
    return !bufp;
}

int size()
{
    return bufp;
}

int is_opening_symbol(char c)
{ // linear search
    extern char opening_symbol[];
    int len = strlen(opening_symbol);
    for (int i = 0; i < len; i++)
        if (c == opening_symbol[i])
            return 1;
    return 0;
}

int is_closing_symbol(char c)
{ // linear search
    extern char closing_symbol[];
    int len = strlen(closing_symbol);
    for (int i = 0; i < len; i++)
        if (c == closing_symbol[i])
            return 1;
    return 0;
}

int is_matched(char open, char close)
{
    if (is_opening_symbol(open) == 1 && is_closing_symbol(close) == 1)
    {
        if (open == '(' && close == ')')
        {
            return 1;
        }
        else if (open == '[' && close == ']')
        {
            return 1;
        }
        else if (open == '{' && close == '}')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

int check(char input[])
{
    extern char opening_symbol[];
    extern char closing_symbol[];
    // CODE HERE:
    printf("Checking %s\n", input);
    bufp = 0; // empty out the stack!
    int len = strlen(input);

    for (int i = 0; i < len; i++)
    {
        if (is_opening_symbol(input[i]))
            push(input[i]);
        else if (is_closing_symbol(input[i]))
        {
            char c = pop();
            for (int j = 0; j < len; j++)
                if (c == input[j])
                    return 1;
            return 0;
        }
        else
        {
            continue;
        }
    }

    /*switch (input[i])
    {
    case '(':
    case '[':
    case '{':
        push(input[i]);
        break;
    case ')':
        if (pop() != '(')
            return 0; // unbalanced
        break;
    case ']':
        if (pop() != '[')
            return 0; // unbalanced
        break;
    case '}':
        if (pop() != '{')
            return 0; // unbalanced
        break;
    default:;
    }*/

    return is_empty();
}
