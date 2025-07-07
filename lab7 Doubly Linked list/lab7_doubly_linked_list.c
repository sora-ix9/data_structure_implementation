//lab7 singly linked list (with data insertion and deletion)
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int item;
  struct node *next;
}node;
node *head=NULL, *newNode=NULL;

node *create_newNode(int newItem){
    node *newNode;//newNode in this func is local var.
    newNode = (node*)malloc(sizeof(node));
    newNode->item = newItem;
    newNode->next = NULL;
    return newNode;
}
char menu(){
    printf("Menu: 1.Add 2.Display 3.Insert 4.Delete 5.Exit\n");
    printf("Enter your choice: ");
    return getchar();
}
void add(){
    //head and newNode in this funce is global var.
    int intItem;
    printf("Enter integer item: ");
    scanf("%d", &intItem);
    while(getchar() != '\n');
    newNode = create_newNode(intItem);
    if(head != NULL){
        newNode->next = head;
        head = newNode;
    }
    else{
        head = newNode;
    }
}
void display(){
    //head in this func is global var.
    if(head != NULL){
        node *currNode = head;//"currNode" stands for "currentNode"
        while(currNode != NULL){
            printf("%d[%p]", currNode->item, currNode->next);
            currNode = currNode->next;
            if(currNode != NULL){
                printf(" -> ");
            }
        }
        printf("\n");
    }
    else{
        printf("Linked list is empty.\n");
    }
}
void insert(){
    //if integer != NULL then we can conclude that linled list is not empty.
    if(head != NULL && head->next != NULL){
        //head and newNode in this func is global var.
        int searchItem;
        int insertItem;
        display();
        printf("Enter search item: ");
        scanf("%d", &searchItem);
        while(getchar() != '\n');
        printf("Enter insert item(int): ");
        scanf("%d", &insertItem);
        while(getchar() != '\n');
		newNode = create_newNode(insertItem);
        
        //linked list traversal for insert a new item.
        //the purpose of exist's currNode in this traversal is for point at search item.
        node *currNode = head;
        node *prev;
        while(currNode->next != NULL || currNode->item == searchItem){
            if(currNode->item == searchItem){
                newNode->next = currNode;
                prev->next = newNode;
                break;
            }
            else{
                prev = currNode;
                currNode = currNode->next;
            }
        }
    }
    else{
        printf("Linked list in this moment can't insert a new item \nbut can add a new item. Please enter your need as followings option:\n");
        printf("1.Need to add item Else.No need to add item.\n");
        printf("Enter your desire: ");
        if(getchar() == '1'){
            while(getchar() != '\n');
            add();
        }else{
            while(getchar() != '\n');
        }
    }
}
void del(){
	if(head != NULL){
		int delItem;
		display();
		printf("Enter delete item: ");
		scanf("%d", &delItem);
		while(getchar() != '\n');
		
		//linked list traversal for delete an item.
	    //the purpose of exist's currNode in this traversal is for point at delete item.
	    node *currNode = head;
	    node *prev;	
	    while(currNode->next != NULL || currNode->item == delItem){
	    	if(currNode->item == delItem && delItem != head->item){
				prev->next = currNode->next;
	    		break;
			}
			else if(delItem == head->item && head->next == NULL){
				head = NULL;
				break; 
			}
			else if(delItem == head->item && head->next != NULL){
				head = currNode->next;
				break;
			}
			else{
				prev = currNode;
				currNode = currNode->next;
			}
		}
	}
	else{
		printf("Linked list is empty.");
	}	
}

int main(){
    char choice;
    while(1){
        printf("-------------------------------------------------------------------------\n");
        choice = menu();
        printf("-------------------------------------------------------------------------\n");
        while(getchar() != '\n');
        
        if(choice == '1'){
            add();
        }
        else if(choice == '2'){
            display();
        }
        else if(choice == '3'){
            insert();
        }
        else if(choice == '4'){
        	del();
		}
        else if(choice == '5'){
            break;
        }
        else{
            printf("Your choice is out of range, please enter again!\n");
        }
    }
    printf("Program exited.");
	return 0;
}