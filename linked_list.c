#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void printNodes(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void insertNode(struct node *head, int a)
{
    while (head != NULL)
    {
        if (head->next->data > a)
        {
            struct node *p = (struct node *)malloc(sizeof(struct node));
            p->data = a;
            //先将新增结点的后继指针 指向当前结点的后继指针所指向的结点
            p->next = head->next;
            //当前结点的后继指针指向新增结点
            head->next = p;
            return;
        }
        head = head->next;
    }
}

void main()
{
    int n = 5;
    int data[] = {1, 2, 3, 5, 6};

    struct node *head, *tail, *p;
    int i;
    head = NULL;

    for (i = 0; i < n; i++)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = data[i];
        p->next = NULL;

        if (head == NULL)
            head = p;
        else
            tail->next = p; //末尾的后继指针 指向当前节点

        //末尾指向当前节点
        tail = p;
    }

    printNodes(head);

    insertNode(head, 4);
    printNodes(head);
}