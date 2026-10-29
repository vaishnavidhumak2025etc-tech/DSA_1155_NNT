#include <stdio.h>
#include <ctype.h>

int stack[50];
int top = -1;

void push(int x)
{
    top++;
    stack[top] = x;
}

int pop()
{
    int x;
    x = stack[top];
    top--;
    return x;
}

int main()
{
    char postfix[50];
    int i, a, b, result;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    for(i = 0; postfix[i] != '\0'; i++)
    {
        if(isdigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else
        {
            b = pop();
            a = pop();

            switch(postfix[i])
            {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    result = a / b;
                    break;
            }

            push(result);
        }
    }

    result = pop();

    printf("Result = %d", result);

    return 0;
}
