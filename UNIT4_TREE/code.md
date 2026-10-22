#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* createNode(int value) {
    Node* n = new Node;
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

bool identical(Node* a, Node* b) {
    if (a == NULL && b == NULL)
        return true;

    if (a == NULL || b == NULL)
        return false;

    return (a->data == b->data &&
            identical(a->left, b->left) &&
            identical(a->right, b->right));
}

bool subtree(Node* mainTree, Node* subTree) {
    if (subTree == NULL)
        return true;

    if (mainTree == NULL)
        return false;

    if (identical(mainTree, subTree))
        return true;

    return subtree(mainTree->left, subTree) ||
           subtree(mainTree->right, subTree);
}

int main() {
    Node* T1 = createNode(1);
    T1->left = createNode(2);
    T1->right = createNode(3);
    T1->left->left = createNode(4);
    T1->left->right = createNode(5);

    Node* T2 = createNode(1);
    T2->left = createNode(2);
    T2->right = createNode(3);
    T2->left->left = createNode(4);
    T2->left->right = createNode(5);

    Node* T3 = createNode(2);
    T3->left = createNode(4);
    T3->right = createNode(5);

    cout << "Backup Verification Application\n";

    if (identical(T1, T2))
        cout << "Trees are identical.\n";
    else
        cout << "Trees are not identical.\n";

    if (subtree(T1, T3))
        cout << "T3 is a subtree of T1.\n";
    else
        cout << "T3 is not a subtree of T1.\n";

    return 0;
}
