// ALGORITHM:

// 1.Start
// 2.Initialize front = NULL and rear = NULL
// 3.Display menu options (Enqueue, Dequeue, Display)
// 4.Read user choice
// 5.If choice = 1 → Insert element at rear (enqueue)
// 6.If choice = 2 → Delete element from front (dequeue)
// 7.If choice = 3 → Display all elements
// 8.If queue becomes empty → set rear = NULL
// 9.Stop

// CODE:

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

// insert into queue
void enqueue()
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter the value: ");
    scanf("%d", &temp->data);
    temp->next = NULL;

    if(rear == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }

    printf("Document entered successfully!!\n");
}

// delete from queue
void dequeue()
{
    if(front == NULL)
    {
        printf("Underflow!!!\n");
        return;
    }

    struct node *temp = front;
    front = front->next;
    free(temp);

    if(front == NULL)
        rear = NULL;

    printf("Document deleted successfully!!\n");
}

// display queue
void display()
{
    if(front == NULL)
    {
        printf("Queue empty!!\n");
        return;
    }

    struct node *temp = front;

    while(temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice;

    printf("1. Enqueue\n2. Dequeue\n3. Display\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}

// Case 1 (Enqueue)

// 1. Enqueue
// 2. Dequeue
// 3. Display
// Enter your choice: 1
// Enter the value: 10
// Document entered successfully!!

// Case 2 (Display)

// 1. Enqueue
// 2. Dequeue
// 3. Display
// Enter your choice: 3
// 10 <-> 20 <-> 30

// Case 3 (Dequeue)

// 1. Enqueue
// 2. Dequeue
// 3. Display
// Enter your choice: 2
// Document deleted successfully!!