/// ** In the name of ALLAH ** ///

#include <bits/stdc++.h>
using namespace std;

// Structure to represent a Node in the binary search tree
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int x) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// Function to insert an element into the BST
struct Node* insertElement(struct Node *root, int x) {
    if (root == NULL) { // When the tree is empty
        return createNode(x);
    }
    if (root->data >= x) { // Value to be inserted is smaller or equal
        root->left = insertElement(root->left, x);
    } else { // Value to be inserted is larger
        root->right = insertElement(root->right, x);
    }
    return root;
}

// Function to find the minimum value node in a subtree
struct Node* FindMin(Node *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the BST
struct Node* Delete(struct Node *root, int data) {
    if (root == NULL) {
        return root; // Base case: the tree is empty
    }
    if (data < root->data) {
        root->left = Delete(root->left, data);
    } else if (data > root->data) {
        root->right = Delete(root->right, data);
    } else {
        // Node to be deleted found

        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
        // Case 2: One child
        else if (root->left == NULL) {
            struct Node *temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == NULL) {
            struct Node *temp = root;
            root = root->left;
            delete temp;
        }
        // Case 3: Two children
        else {
            struct Node *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

// Inorder traversal
void inorder(struct Node *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Preorder traversal
void preorder(struct Node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal
void postorder(struct Node *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Main function
int main() {
    struct Node *root = NULL;

    // Insert elements into the BST
    root = insertElement(root, 8);
    root = insertElement(root, 10);
    root = insertElement(root, 3);
    root = insertElement(root, 1);
    root = insertElement(root, 6);
    root = insertElement(root, 14);
    root = insertElement(root, 7);

    // Traversals
    cout << "Inorder   : ";
    inorder(root);
    cout << endl;

    cout << "Preorder  : ";
    preorder(root);
    cout << endl;

    cout << "Postorder : ";
    postorder(root);
    cout << endl;

    // Delete a node and show the updated inorder traversal
    root = Delete(root, 3);
    cout << "Inorder after deletion of 3: ";
    inorder(root);
    cout << endl;

    return 0;
}

/*
Insertion Order : 8 10 3 1 6 14 7

        8
      /   \
     3     10
    / \       \
   1   6       14
        \
         7
*/
