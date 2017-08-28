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

struct node *insertNode(struct node *head, int a)
{

    if (head == NULL)
        return head;

    if (head->data > a)
    {
        struct node *p = (struct node *)malloc(sizeof(struct node));
        p->data = a;
        p->next = head;
        head = p;
        return head;
    }

    struct node *cursor = head;
    while (cursor != NULL)
    {
        if (cursor->next == NULL || cursor->next->data > a)
        {
            struct node *p = (struct node *)malloc(sizeof(struct node));
            p->data = a;
            //先将新增结点的后继指针 指向当前结点的后继指针所指向的结点
            p->next = cursor->next;
            //当前结点的后继指针指向新增结点
            cursor->next = p;
            break;
        }
        cursor = cursor->next;
    }

    return head;
}

void main()
{
    int n = 5;
    int data[] = {2, 3, 5, 6, 7};

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

    head = insertNode(head, 1);
    printNodes(head);

    head = insertNode(head, 4);
    printNodes(head);

    head = insertNode(head, 8);
    printNodes(head);
}