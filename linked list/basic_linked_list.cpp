#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insert(Node *&list, int k)
{
    if (list == NULL)
    {
        list = new Node(k);
        return;
    }
    else
    {
        Node *t = list;

        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = new Node(k);
    }
}

void printLinkedList(Node *list)
{
    while (list)
    {
        cout << list->data << " -- ";
        list = list->next;
    }
    return;
}

int length(Node *list)
{
    int count = 0;
    while (list)
    {
        count++;
        list = list->next;
    }
    return count;
}

void insertAtHead(Node *&list, int k)
{
    if (!list)
    {
        list = new Node(k);
        return;
    }
    Node *newNode = new Node(k);
    newNode->next = list;
    list = newNode;

    return;
}

void insertInMiddle(Node *&list, int k)
{
    if (!list)
    {
        list = new Node(k);
    }
    int count = length(list);
    int j = 0;
    Node *temp = list;
    Node *prev = list;
    while (j < count / 2)
    {
        prev = temp;
        temp = temp->next;
        j++;
    }
    Node *newNode = new Node(k);
    newNode->next = temp;
    prev->next = newNode;

    return;
}

// void deleteElement(Node*& list, int k)
// {
//     Node* tempPrev = list;
//     Node* temp = list->next;
//     // base case delete element 1
//     if(list->data == k){

//     }
// }

Node *reverseLL(Node *list)
{
    if (!list or !list->next)
    {
        return list;
    }
    Node *lastElement = reverseLL(list->next);
    list->next->next = list;
    list->next = NULL;

    return lastElement;
}

Node *reverseLLGroupK(Node *list, int k)
{
    Node *temp = list;
    int count = 0;
    while (temp && count < k)
    {
        temp = temp->next;
        count++;
    }
    if (count < k)
        return list; // not enough nodes to reverse, so return the list as-is.

    // Reverse k nodes.
    Node *current = list;
    Node *prev = nullptr;
    Node *nextNode = nullptr;
    count = 0;
    while (current && count < k)
    {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
        count++;
    }

    // Now, head is the last node in the reversed segment.
    // Recursively reverse the remaining list and attach it.
    if (nextNode != nullptr)
        list->next = reverseLLGroupK(nextNode, k);

    // prev is the new head of the reversed segment.
    return prev;
}

Node *midPoint(Node *list)
{
    Node *slowPtr = list;
    Node *fastPtr = list->next;

    while (slowPtr && fastPtr && fastPtr->next)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }
    return slowPtr;
}

Node *merge(Node *a, Node *b)
{
    if (!a)
    {
        return b;
    }
    if (!b)
    {
        return a;
    }
    Node *c = NULL;
    if (a->data <= b->data)
    {
        c = a;
        c->next = merge(a->next, b);
    }
    else
    {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

Node *mergeSort(Node *list)
{
    if (!list || !list->next)
    {
        return list;
    }

    Node *mid = midPoint(list);
    Node *a = list;
    Node *b = mid->next;
    // Break the list before joining it
    mid->next = NULL;

    a = mergeSort(a);
    b = mergeSort(b);

    Node *c = merge(a, b);
    return c;
}

int main()
{
    Node *list = new Node(10);
    insert(list, 9);
    insert(list, 129);
    insert(list, 39);
    insert(list, 29);
    insert(list, 89);
    insertAtHead(list, 19);
    insertInMiddle(list, 99);
    printLinkedList(list);
    cout << endl;
    // Reverse entire list and update pointer.
    list = reverseLL(list);
    printLinkedList(list);
    list = reverseLL(list);
    cout << endl;

    // Now reverse in groups of k on the correctly updated list.
    list = reverseLLGroupK(list, 3);
    printLinkedList(list);
    cout << endl;

    list = mergeSort(list);
    printLinkedList(list);
    cout << endl;
    cout << length(list);

    cout << endl;

    return 0;
}