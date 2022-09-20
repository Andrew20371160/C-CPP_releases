#include<stdio.h>
#include<stdlib.h>
struct node {
int data ;
struct node * next ;

};

struct node * add_at_empty(int d ){
struct node * head = malloc(sizeof(struct node ));
head ->data  =d   ;
head->next = NULL ;
return head ;
};

struct node *add_at_end(int d ,struct node * head ){
if(head ==NULL){
    head = add_at_empty(d) ;
}
else if(head ->next == NULL){
    struct node * temp = add_at_empty(d) ;
    temp->next =  NULL ;
    head->next  = temp ;

}
else {
    struct node * ptr=  head ;
    struct node * temp  = add_at_empty(d) ;
    while(ptr->next !=NULL){
        ptr  =ptr->next ;
    }
temp->next = NULL ;
ptr->next= temp ;

}
return head ;
};
void show(struct node * head){
printf("\n");
if(head ==NULL){
    printf("\n list is empty ");
    return ;
}
struct node * ptr= head ;
while(ptr !=NULL){
    printf("%d ",ptr->data ) ;
    ptr = ptr->next ;
}


}
int list_size(struct node * head ){
int s = 0 ;
while(head!=NULL){
    s++;
    head = head->next ;
}

return s ;
}
void split_list(struct node ** head,struct node **left ,struct node **right ){
struct node * ptr = (*head) ;
int mid  = list_size(*head) /2 ;
for(int i = 0 ; i <=mid  ;i++){
    *left =add_at_end((ptr->data),(*left))  ;
   ptr = ptr->next ;
}
for(int i = mid ; i<list_size(*head) ; i++){
*right = add_at_end((ptr->data), (*right )) ;
ptr = ptr->next ;
if(ptr ==NULL){
    break ;
}
}


}

int main(){

struct node * head = NULL ;
 head=  add_at_end(1,head) ;
 head=  add_at_end(2,head) ;
 head=  add_at_end(6,head) ;
 head=  add_at_end(300,head) ;
 head=  add_at_end(3,head) ;
 head=  add_at_end(10,head) ;
 head=  add_at_end(38,head) ;
 head=  add_at_end(20,head) ;
 head=  add_at_end(-6,head) ;



struct node * left = NULL;
struct node * right = NULL ;
 split_list(&head,&left,&right)  ;
 show(head) ;
 show(left) ;
 show(right) ;

return 0 ;

}
