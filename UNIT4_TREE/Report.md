## Introduction
A backup verification application is used to check whether two backup structures contain the same data and whether one backup structure exists as a part of another. Binary trees are used to represent the backup structures, where each node stores data and has at most two children. The application uses tree comparison and subtree checking techniques to verify backups efficiently and identify matching structures

## Problem Statement
To develop a C++ application using binary trees that verifies whether two backup structures are identical and whether one backup structure is a subtree of another. The application compares the nodes and their arrangement to ensure the correctness and consistency of backup data

## Objective
To represent backup structures using binary trees.

To check whether two binary trees are identical in data and structure.

To determine whether one binary tree is a subtree of another.

To display appropriate verification results.

To understand the practical application of binary tree operations in data backup systems.

## Algorithm

Step 1: Start the program.

Step 2: Create two binary trees representing the backup structures.

Step 3: Compare the two trees using a recursive function. If their node values and structures match, they are identical.

Step 4: Check whether the second tree is a subtree of the first tree by comparing it with each suitable node of the first tree.

Step 5: Display whether the trees are identical and whether the subtree exists.

Step 6: Stop the program.

## Flowchaert
 
    <img width="883" height="1600" alt="WhatsApp Image 2026-10-22 at 11 50 24 AM" src="https://github.com/user-attachments/assets/1b25a5df-5f16-4c2a-898f-a6ed0cb06f4c" />


## code

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

## Output
<img width="1600" height="956" alt="WhatsApp Image 2026-10-22 at 11 29 32 AM" src="https://github.com/user-attachments/assets/e3e76a35-3cd6-424c-86b0-57861d94b3c4" />

## Conclusion
The project demonstrates the use of binary trees and recursion for backup verification. It helps identify identical backup structures and detect subtrees, ensuring data consistency and improving the reliability of backup systems.

## Result
The Backup Verification Application was successfully developed using binary trees in C++. It checks whether two backup structures are identical and whether one structure is a subtree of another. The application displays the appropriate verification results.

