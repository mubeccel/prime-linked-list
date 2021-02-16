#include <stdio.h> 
#include <stdlib.h> 
  
struct node { 
    int data; 
    struct node* next; 
}; 

int i,num;

//functions:
void mid();
void insert();
int prime();
void printList();

void mid(struct node* head)  //find the middle element
{ 
    int count = 0; 
    struct node* mid = head; 
  
    while (head != NULL) { 
        if (count & 1) 
            mid = mid->next; 
        ++count; 
        head = head->next; 
    } 
    if (mid != NULL) 
        printf("Middle Element Is: %d\n", mid->data); 
} 
  
void insert(struct node** head_ref, int new_data) 
{ 
    struct node* new_node 
        = (struct node*)malloc(sizeof(struct node)); 
    new_node->data = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
} 

void printList(struct node* ptr) //function for printing the list
{ 
    printf("LinkedList: ");
	while (ptr != NULL) { 
        printf("%d-> ", ptr->data); 
        ptr = ptr->next; 
    } 
    printf("NULL\n"); 
} 
    
int prime(){   
	num =  rand() % 100; //get random integer
	int flag = 0, i ;
	
	//check if the integer is prime
    for( i = 2; i <= num/2; i++) {
       	if(num % i == 0) {
        flag = 1;
        break;
        }
    } 
    if(flag == 0){
      	//num is prime
      	prime();
    }
    else
    	//num is not prime
    	return num;
	}
  
int main() 
{ 
    struct node* head = NULL; 
    int j; 
  
    for (j=0; j<5; j++) { 
        insert(&head, prime());    
    } 
    
    printList(head); //prints the list
    mid(head); //the middle element
    return 0; 
}
