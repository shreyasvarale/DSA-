#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

int main()
{
    Node* head = NULL;
    Node* temp = NULL;
    Node* newNode = NULL;

    int n, key, position = 1;

    cout << "Enter number of nodes: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid number of nodes!" << endl;
        return 0;
    }

    // Create linked list
    for (int i = 0; i < n; i++)
    {
        newNode = new Node;

        cout << "Enter element: ";
        cin >> newNode->data;

        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    // Search for the element
    cout << "Enter element to search: ";
    cin >> key;

    temp = head;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            cout << "Element found at position "
                 << position << endl;
            break;
        }

        temp = temp->next;
        position++;
    }

    if (temp == NULL)
    {
        cout << "Element not found!" << endl;
    }

    // Free allocated memory
    temp = head;

    while (temp != NULL)
    {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    return 0;
}
