// ALGORITHM:

// 1.Start
// 2.Initialize top = -1 and flag = 0
// 3.Read the expression
// 4.Traverse each character of the expression
// 5.If opening bracket → push into stack
// 6.If closing bracket → pop and check matching
// 7.If not matching → set flag = 1
// 8.After traversal, check flag
// 9.If flag == 0 → Valid Expression
// 10.Else → Invalid Expression
// 11.Stop

// CODE:

#include<stdio.h>
#include<string.h>

#define Max 10001

char stack[Max];
int top = -1;

// push element into stack
void push(char no)
{
    if(top == Max - 1)
    {
        printf("Overflow");
    }
    else
    {
        stack[++top] = no;
    }
}

// pop element from stack
char pop()
{
    if(top == -1)
    {
        printf("Underflow");
        return '\0';
    }
    return stack[top--];
}

// check matching brackets
int ismatching(char no1, char no2)
{
    if(no1=='{' && no2=='}') return 1;
    if(no1=='(' && no2==')') return 1;
    if(no1=='[' && no2==']') return 1;
    if(no1=='<' && no2=='>') return 1;
    return 0;
}

int main()
{
    int flag = 0;
    char exp[1001];

    printf("Enter the expression: ");
    fgets(exp, sizeof(exp), stdin);

    for(int i = 0; i < strlen(exp); i++)
    {
        if(exp[i]=='{' || exp[i]=='[' || exp[i]=='(' || exp[i]=='<')
        {
            push(exp[i]);
        }
        else if(exp[i]=='}' || exp[i]==']' || exp[i]==')' || exp[i]=='>')
        {
            if(ismatching(pop(), exp[i]))
                flag = 0;
            else
                flag = 1;
        }
    }

    if(flag == 0 && top == -1)
        printf("Valid Expression");
    else
        printf("Invalid Expression");

    return 0;
}

// SAMPLE OUTPUT:

// Case 1 (Valid)
// Enter the expression: {a+(b*c)}
// Valid Expression

// Case 2 (Invalid)
// Enter the expression: {a+(b*c]
// Invalid Expression