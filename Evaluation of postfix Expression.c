#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void push(int);
int pop();
void display();

int s[25] = {0};
int top = -1;
int ch;

int main()
{
    char postfix[25] = {'\0'}, ele;
    int i, num1, num2, ans;
    printf("Enter the Postfix Expression: \n");
    scanf("%s", postfix);
    printf("Postfix Expression is: %s\n", postfix);
    i = 0;
    while(i<=strlen(postfix)-1)
    {
        ele = postfix[i];
        if(isdigit(ele))
        {
            push(ele - '0');
        }
        else{
            num1 = pop();
            num2 = pop();
            switch(ele)
            {
                case '^':
                ans = pow(num2,num1);
                break;

                case '/':
                ans = num2/num1;
                break;

                case '*':
                ans = num2*num1;
                break;

                case '+':
                ans = num2+num1;
                break;

                case '-':
                ans = num2-num1;
                break;
            }
            push(ans);
        }
        i++;
    }
    printf("ans = %d", pop());
}

void push(int ele)
{
    if(top==24)
    printf("Stack Overflow\n");
    else
    {
        top++;
        s[top] = ele;
    }
}

int pop()
{
    if(top == -1)
    printf("Stack Underflow\n");
    else
    {
        ch = s[top];
        top--;
    }
    return ch;
}

void display()
{
    int i;
    printf("Stack S= ");
    for(i=0; i<=top; i++)
    printf("%d", s[i]);
}