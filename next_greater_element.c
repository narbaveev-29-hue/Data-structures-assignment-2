// ALGORITHM:

// 1.Start
// 2.Read the number of elements len
// 3.Input the array elements
// 4.Traverse the array from left to right
// 5.Maintain a stack of indices
// 6.If the current element is greater than the element at the stack top, assign it as the next greater element
// 7.Pop the index from stack and continue checking
// 8.Push the current index into the stack
// 9.For remaining indices in stack, assign -1 as next greater element
// 10.Print each element and its next greater element
// 11.Stop

// CODE:

#include<stdio.h>
#define Max 101

int top = -1;
int stack[Max];

// push value into stack
void push(int value)
{
    if(top == Max - 1)
        return;
    stack[++top] = value;
}

// pop value from stack
int pop()
{
    if(top == -1)
        return -2;
    return stack[top--];
}

// find next greater element
void nextGreater(int array[], int n)
{
    int result[Max];
    int indexStack[Max];
    int top2 = -1;

    for(int i = 0; i < n; i++)
    {
        while(top2 != -1 && array[indexStack[top2]] < array[i])
        {
            result[indexStack[top2]] = array[i];
            top2--;
        }
        indexStack[++top2] = i;
    }

    while(top2 != -1)
    {
        result[indexStack[top2]] = -1;
        top2--;
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d -> %d\n", array[i], result[i]);
    }
}

int main()
{
    int array[101];
    int len;

    printf("Enter the no.of values in the array: ");
    scanf("%d", &len);

    for(int i = 0; i < len; i++)
    {
        printf("Enter the value for %dith value: ", i);
        scanf("%d", &array[i]);
    }

    nextGreater(array, len);

    return 0;
}

// SAMPLE OUTPUT:

// Enter the no.of values in the array: 5
// Enter the value for 0ith value: 4
// Enter the value for 1ith value: 5
// Enter the value for 2ith value: 2
// Enter the value for 3ith value: 10
// Enter the value for 4ith value: 8

// 4 -> 5
// 5 -> 10
// 2 -> 10
// 10 -> -1
// 8 -> -1