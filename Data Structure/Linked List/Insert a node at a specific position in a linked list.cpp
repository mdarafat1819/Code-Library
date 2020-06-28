#include <bits/stdc++.h>

using namespace std;

typedef struct node Node;

struct node
{
    int data;
    Node *next;
};

void append(Node *head, int data)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node -> data = data;
    new_node -> next = NULL;
    while(head -> next != NULL) head = head -> next;
    head -> next = new_node;
}

void prepend(Node *head, int data)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node -> data = data;
    new_node -> next = head -> next;
    head -> next = new_node;
}

void insert_nth_pos(Node *head, int pos, int data)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node -> data = data;
    new_node -> next = NULL;
    while((head -> next != NULL) && pos)
    {
        head = head -> next;
        pos--;
    }
    new_node -> next = head -> next;
    head -> next = new_node;
}

void print(Node *head)
{
    while(head -> next != NULL)
    {
        cout<<head -> next -> data<<" ";
        head = head -> next;
    }
    cout<<endl;
}

int main()
{
    Node *head = (Node*)malloc(sizeof(Node));
    head -> next = NULL;

    append(head, 1);
    append(head, 2);
    prepend(head, 4);
    print(head);
    insert_nth_pos(head, 1, 10);
    print(head);

    return 0;
}
