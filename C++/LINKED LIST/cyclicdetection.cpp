#include <iostream>
using namespace std;
#define INT_MIN (-2147483647 - 1)

struct Node
{
    int val;
    Node *next;

    Node(int data)
    {
        val = data;
        next = nullptr;
    }
};

void insert(Node *&head, int value)
{
    Node *newNode = new Node(value);
    Node *temp = head;
    if (!head)
    {
        head = newNode;
        return;
    }

    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

int cyclePoint(Node *&head)
{
    if (!head)
    {
        return INT_MIN;
    }
    Node *slow = head, *fast = head;

    bool check = false;
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            check = true;
            break;
        }
    }

    if (!check)
        return INT_MIN;

    fast = head;
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return fast->val;
}

void display(Node *head)
{
    while (head != nullptr)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL\n";
}
int main()
{
    Node *ll = NULL;
    // for (int i = 0; i < 10; i++)
    // {
    //     insert(ll, i);
    // }

    insert(ll, 1);
    insert(ll, 2);
    insert(ll, 3);
    insert(ll, 4);
    insert(ll, 5);
    insert(ll, 6);
    insert(ll, 7);

    ll->next->next->next->next->next->next->next = ll->next->next->next->next;
    cout << cyclePoint(ll) << endl;

    // display(ll);
    return 0;
}