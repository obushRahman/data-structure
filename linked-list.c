

#include <stdio.h>
void create();
void display();
void insertAtBegin();
void insertAtEnd();
void inserAtPos();
void deleteAtBegin();
void deleteAtEnd();
void deleteAtPos();

struct Node {
    int data;
    struct Node * link;
}* head = NULL;

int main(){
    int choice;
    while(1){
        
        printf("----------Menu------------");
        printf("\n1.Create.");
        printf("\n2.Display");
        printf("\n3.insertAtBegin");
        printf("\n4.insertAtEnd");
        printf("\n5.inserAtPos");
        printf("\n6.deleteAtBegin");
        printf("\n7.deleteAtEnd");
        printf("\n8.deleteAtPos");
        printf("\n9.Exit");
        printf("\n---------------------------\n");
        
        printf("\nEnter your choice= \t");
        scanf("%d",&choice);
        switch(choice){
                case 1:
                    create();
                    break;
                case 2:
                    display();
                    break;
                case 3:
                    insertAtBegin();
                    break;
                case 4:
                    insertAtEnd();
                    break;
                case 5:
                    inserAtPos();
                    break;
                case 6:
                    deleteAtBegin();
                    break;
                case 7:
                    deleteAtEnd();
                    break;
                case 8:
                    deleteAtPos();
                    break;
                case 9:
                    exit(0);
                    break;
                default:
                    printf("\nYou have enter the wring option :) :)\n");
        }
        
    }
    
    return 0;
}

void create(){
    struct  Node * temp,*newNode;
    newNode =(struct Node * ) malloc (sizeof(struct Node));
    
    printf("\nEnter the data of newNode= \t");
    scanf("%d",&newNode -> data);
    
    newNode -> link = NULL;
    
    if(head==NULL){
            head = newNode;
            temp = head;
    }
    else{
        temp=head;
        while(temp -> link !=NULL){
            temp = temp -> link;
        }
        temp-> link=newNode;

    }
}

void display(){
    struct Node * temp;
    if(head == NULL){
        printf("\nLinked List is empty.\n");
    }else{
        temp = head;
        printf("\nLinked List is. \n");
        while(temp != NULL){
            printf("%d ->",temp -> data);
            temp = temp -> link;
        }
        printf("NULL.\n");
    }
    
}
void insertAtBegin(){
    
    struct Node * newNode,*temp;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    
    printf("\n Enter the data of the node=");
    scanf("%d",&newNode -> data);
    
    temp=head;
    newNode->link=temp;
    head=newNode;
    
}
void insertAtEnd(){
    
    struct Node * newNode,*temp;
    
    newNode=(struct Node * )malloc(sizeof(struct Node));
    printf("Enter the data of the node=");
    scanf("%d",&newNode->data);
    
    newNode -> link =NULL;
    
    temp=head;
    
    while( temp->link != NULL){
        temp = temp -> link;
    }
    temp -> link = newNode;
    
}
void inserAtPos(){
    
    int i,pos;
    struct Node * newNode,*temp;
    
    printf("\nEnter the position =");
    scanf("%d",&pos);
    
    if(pos==1){
        insertAtBegin();
    }else{
        
        newNode=(struct Node * )malloc(sizeof(struct Node));
        printf("Enter the data of the node=");
        scanf("%d",&newNode->data);
    
        newNode -> link =NULL;
        
        temp=head;
        for(i=1;i<pos;i++){
            temp=temp -> link;
        }
        newNode -> link = temp -> link;
        temp -> link = newNode;
    }
    
}
void deleteAtBegin(){
    struct Node * temp;
    temp = head;
    head = temp -> link;
    
    free(temp);
}
void deleteAtEnd(){
    struct Node * temp;
    temp = head;
    while(temp -> link -> link!= NULL){
        temp = temp -> link;
    }
    temp -> link = NULL;
    
}
void deleteAtPos(){
    struct Node * temp;
    temp = head;
    int i,pos;
    printf("\nEnter the position=");
    scanf("%d",&pos);
    if(pos==1){
        deleteAtBegin();
    }
    else{
        for(i=1;i<pos-1;i++){
            temp=temp -> link;
        }
        temp -> link = temp -> link -> link;
    }
}

