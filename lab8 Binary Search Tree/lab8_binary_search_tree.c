#include<stdio.h>
#include<stdlib.h>

typedef struct nodeTree{
    int item;
    struct nodeTree *left, *right;
}node;

node *create_newNode(int item){
    node *newNode;
    newNode = (node*)malloc(sizeof(node));
    newNode->item = item;
    newNode->left = newNode->right = NULL;
    return newNode;
}

node *insertItem(node *currNode, int item){
    if(currNode == NULL)
        return create_newNode(item);
    else if(item < currNode->item)
        currNode->left = insertItem(currNode->left, item);
    else if(item > currNode->item)
        currNode->right = insertItem(currNode->right, item);
    
    return currNode; //return the (unchange) node pointer.
}

node *get_inorderSuccessor(node *currNode){
    //find inorderSuccessor which's the smallest value of right subtree.
    
    if(currNode == NULL)
        return currNode;
    while(currNode && currNode->left!=NULL)
        currNode = currNode->left;
    return currNode;
}

node *delNode(node *currNode, int item){
    if(currNode == NULL)
        return currNode;
    else if(item < currNode->item)
        currNode->left = delNode(currNode->left, item);
    else if(item > currNode->item)
        currNode->right = delNode(currNode->right, item);
    else{
        //this else block will work when currNode equivalent to delete node.

        if(currNode->left == NULL){
            /* this if block and the below else if block will work 
               when delete node has only one child or no child. */
            // tempNode point to a node that going to be concatenate node.   
            // then return tempNode for link concatenate node.
            
            node *tempNode = currNode->right; 
            free(currNode);
            return tempNode; 
        }
        else if(currNode->right == NULL){
            node *tempNode = currNode->left;
            free(currNode);
            return tempNode;
        }
        
        //this below code will work when delete node has 2 children.
        //line 58 perform the copy inorderSuccessor to delete node.
        //line 59 perform the delete inorderSuccessor.
        node *inorderSuccessor = get_inorderSuccessor(currNode->right);
        currNode->item = inorderSuccessor->item; 
        currNode->right = delNode(currNode->right, inorderSuccessor->item);
    }
    return currNode;
}

void preorder(node *currNode){
    if(currNode != NULL){
        printf(" %d", currNode->item);
        preorder(currNode->left);
        preorder(currNode->right);
    }
}

void inorder(node *currNode){
    if(currNode != NULL){
        inorder(currNode->left);
        printf(" %d", currNode->item);
        inorder(currNode->right);
    }
}

void postorder(node *currNode){
    if(currNode != NULL){
        postorder(currNode->left);
        postorder(currNode->right);
        printf(" %d", currNode->item);
    }
}

int *inputNumber(){
    static int numberArr[7];
    for(int i=1; i<=7; i++){
        printf("Enter data(%d) insert: ", i);
        scanf("%d", &numberArr[i-1]);
    }
    return numberArr;
}

void main(){
    int delItem;
    node *root = NULL;
    int *numberArrPtr = inputNumber();
    
    for(int i=1; i<=7; i++){
        if(root != NULL)
            insertItem(root, numberArrPtr[i-1]);
        else
            root = insertItem(root, numberArrPtr[i-1]);
    }
    
    printf("-----------------------------------------\n");
    printf("Preorder:");
    preorder(root);
    printf("\nInorder:");
    inorder(root);
    printf("\nPostorder:");
    postorder(root);
    printf("\n-----------------------------------------");
    printf("\nEnter a data to delete: ");
    scanf("%d", &delItem);
    root = delNode(root, delItem);
    printf("-----------------------------------------\n");
    printf("Preorder:");
    preorder(root);
    printf("\nInorder:");
    inorder(root);
    printf("\nPostorder:");
    postorder(root);
    printf("\n-----------------------------------------");
    
}