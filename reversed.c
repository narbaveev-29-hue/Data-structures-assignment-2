// ALGORITHM:

// 1.Start
// 2.Initialize top = -1
// 3.Read the input string
// 4.Remove newline character
// 5.Push all characters into stack
// 6.Pop characters one by one into another array
// 7.Add null character at the end
// 8.Print reversed string
// 9.Stop

// CODE:

#include<stdio.h>
#include<string.h>

#define Max 101

char stack[Max];
int top = -1;

// push string into stack
void push(char *ptr)
{
    for(int i = 0; *(ptr + i) != '\0'; i++)
    {
        if(top == Max - 1)
            return; // stack full
        stack[++top] = *(ptr + i);
    }
}

// pop character from stack
char pop()
{
    if(top == -1)
        return '\0'; // stack empty
    return stack[top--];
}

int main()
{
    char string[101], reverse[101];

    printf("Enter the string: ");
    fgets(string, sizeof(string), stdin);

    // remove newline
    string[strcspn(string, "\n")] = '\0';

    // push characters
    push(string);

    int len = strlen(string);

    // pop to reverse
    for(int i = 0; i < len; i++)
    {
        reverse[i] = pop();
    }

    reverse[len] = '\0';

    printf("Reversed string: %s", reverse);

    return 0;
}

// SAMPLE OUTPUT:

// Enter the string: hello
// Reversed string: olleh