/*
This program has features on linked list as following.
1. feature for adding item including 
   - add func 
   - create_newNode func
2. feature for showwing including
   - show func
3. feature for exitting
Moreover, there's menu func for display the menu to user.
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int item;
    struct node *next;
}stNode;//use typedef for substitute "struct node" to "stNode"
stNode *head=NULL, *newNode=NULL;

char menu(void){
    printf("Menu: 1.Add item 2.Display data 3.Exit\n");
    printf("Enter menu: ");
    return(getchar());
}
//func for create newNode.
stNode *create_newNode(int newItem){
    stNode *newNode;//newNode in this func is local var.
    newNode = (stNode*)malloc(sizeof(stNode));
    newNode->item = newItem;
    newNode->next = NULL;
    return(newNode);
}
//func for add item.
void add(){
    //newNode in this func is global var.
    int newItem;
    printf("Enter add item: ");
    scanf("%d", &newItem);
    newNode = create_newNode(newItem);
    newNode->next = head;
    head = newNode;
}
void show(){
    stNode *currNode;//"currNode" stands for "currentNode"
    currNode = head;
    while(currNode != NULL){
        printf("%d[%p]", currNode->item, currNode->next);
        currNode = currNode->next;
        if(currNode != NULL){
            printf(" -> ");
        }
    }
    printf("\n");
}

void main()
{   char menuVar;
    bool loop = true;

    while(loop){
        printf("------------------------------------------------------\n");
        menuVar = menu();
        while(getchar() != '\n');
        printf("------------------------------------------------------\n");
        
        switch(menuVar){
            case '1':
                add(); 
                while(getchar() != '\n');
                break;
            case '2': 
                if(head != NULL){
                    show();    
                }else{
                    printf("Linked list is empty.\n");
                }
                break;
            case '3': 
                loop = false;
                break;
            default: 
                printf("Your choise is out of menu, pleace enter menu again.\n");
                break;
        }
    }
    printf("Program is exited.");
}