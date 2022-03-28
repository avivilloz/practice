#include <stdio.h>

int IsClosingParentheses(char p)
{
    return (p == ')' || p == ']' || p == '}');
}

char GetClosingParentheses(char p)
{
    switch(p)
    {
        case '(':
            return ')';
        case '[':
            return ']';
        case '{':
            return '}';
        default:
            return 0; 
    }
}

const char *CheckBalance(const char *str)
{
    if ('\0' == *str || IsClosingParentheses(*str))
    {
        return str;
    }
    
    const char *closing_parentheses = CheckBalance(str + 1);
    if (*closing_parentheses == GetClosingParentheses(*str))
    {
        return CheckBalance(closing_parentheses + 1);
    }

    return str;
}

int AreParenthesesBalanced(const char *str)
{
    if ('\0' == *CheckBalance(str))
    {
        return 1;
    }

    return 0;
}

int main(void)
{
    printf("%d\n", AreParenthesesBalanced("{}[]"));
    printf("%d\n", AreParenthesesBalanced("{{[[(())]]}}"));
    printf("%d\n", AreParenthesesBalanced("{[}]"));
    printf("%d\n", AreParenthesesBalanced("{{}"));

    return 0;
}