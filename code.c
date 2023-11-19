//BST tree

#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode) {
        newNode->data = data;
        newNode->left = newNode->right = NULL;
    }
    return newNode;
}
struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}
struct TreeNode* findMin(struct TreeNode* node) {
    struct TreeNode* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}
struct TreeNode* deleteNode(struct TreeNode* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {

        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        struct TreeNode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct TreeNode* root){
        if(root!=NULL){
                printf("%d ",root->data);
                preorderTraversal(root->left);
                preorderTraversal(root->right);
        }
}

void postorderTraversal(struct TreeNode* root){
        if(root!=NULL){
                postorderTraversal(root->left);
                postorderTraversal(root->right);
                printf("%d ",root->data);
        }
}

struct TreeNode* search(struct TreeNode* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

int main() {
    struct TreeNode* root = NULL;
    int choice, data;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display(In-order traversal)\n4. Display(Pre-order traversal) \n5.Display(Post-order traversal) \n6. Search\n7. Find Min\n8. Find Max\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                if(root){
                    printf("Enter data to delete: ");
                scanf("%d", &data);

                if (search(root, data)) {
                    root = deleteNode(root, data);
                }else{
                    printf("Data not found in the tree.\n");
                }
                }else{
                    printf("Tree is empty\n");
                }
                break;
            case 3:
                if(root){
                    printf("In-order Traversal: ");
                inorderTraversal(root);
                printf("\n");
                }else{
                    printf("Tree is empty\n");
                }
                break;
            case 4:

        if(root){
            printf("Pre-order Traversal: ");
        preorderTraversal(root);
        printf("\n");
        }else{
            printf("Tree is empty ");
        }
                break;
            case 5:
        if(root){
            printf("post-order Traversal:");
        postorderTraversal(root);
        printf("\n");
        }else{
            printf("tree is empty.");
        }
                break;
            case 6:
                if(root){
                    printf("Enter data to search: ");
                scanf("%d", &data);
                if (search(root, data)) {
                    printf("Data found in the tree.\n");
                }else{
                    printf("Data not found in the tree.\n");
                }
                }else{
                    printf("Tree is empty.\n");
                }
                break;
            case 7:
                if (root) {
                    struct TreeNode* minNode = findMin(root);
                    printf("Minimum value in the tree: %d\n", minNode->data);
                } else {
                    printf("Tree is empty.\n");
                }
                break;
            case 8:
                if (root) {
                    struct TreeNode* maxNode = root;
                    while (maxNode->right != NULL) {
                        maxNode = maxNode->right;
                    }
                    printf("Maximum value in the tree: %d\n", maxNode->data);
                } else {
                    printf("Tree is empty.\n");
                }
                break;
            case 9:
                exit(0);break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
