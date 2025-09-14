#include<stdio.h>
#include<stdlib.h>

// Define the structure for a node in the binary tree
struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

// Inorder Traversal (Left -> Root -> Right)
void inorder(struct Node* root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->data);  // Added space for readability
		inorder(root->right);
	}
}

// Preorder Traversal (Root -> Left -> Right)
void preorder(struct Node* root) {
	if (root != NULL) {
		printf("%d ", root->data);  // Added space for readability
		preorder(root->left);
		preorder(root->right);
	}
}

// Postorder Traversal (Left -> Right -> Root)
void postorder(struct Node* root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);  // Added space for readability
	}
}

int main() {
    // Creating the tree
    //        4
    //      /   \
    //     2     6     
    //    / \   / \
    //   1   3  5  7

    struct Node* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(5);
    root->right->right = createNode(7);
    
    // Perform tree traversal
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");     

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");
    
    return 0;
}

