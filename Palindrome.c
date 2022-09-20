#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
char data ;
struct node * next  ;
};
struct node * add_at_empty(char ch ){
struct node * top = malloc(sizeof(struct node)) ;
top ->data = ch ;
top->next  =NULL ;
return top  ;
};
int isempty(struct node * top ){
return (top ==NULL );
}
struct node * push(char ch , struct node * top ){
if(isempty(top)){
    top =add_at_empty(ch) ;
    return top ;
}
struct node * temp = add_at_empty(ch) ;
temp->next = top ;
top = temp ;
return top ;
};
char  pop(struct node **top ){
if(isempty(*top)){
    printf("\n underflow");
    return 'x' ;
}
else if((*top)->next == NULL){
    char val= (*top)->data  ;
    free(*top) ;
    *top = NULL ;
    return val ;
}
else {
    struct node *temp = (*top) ;
    char val = (*top)->data ;
    (*top) = (*top)->next ;
    free(temp) ;
    temp =NULL;
    return val ;
}

}

void show(struct node * top ){
if(isempty(top)){
    printf("\n string is empty ");
    return ;
}
struct node * ptr = top ;
while(ptr!=NULL){
    printf("%c", ptr->data);
    ptr =ptr->next ;
}

}

void create(struct node**top ){
char str[30];
printf("\n enter a string with , in the middle ") ;
scanf("%s",str);

for(int i  = 0; i <strlen(str)+1 ;i++){
   *(top) = push(str[i],(*top));
}
}
int str_size(struct node *top ){
if(isempty(top)){
    printf("\n list is empty ") ;
    return 0 ;
 }
int size = 0 ;
struct node * ptr = NULL ;
ptr = top ;
while(ptr !=NULL ){
    size++ ;
    ptr =ptr->next ;
}

return size  ;

}
int ispalindrome(struct node *top ){
struct node * top2 = NULL ;
 while(top->data !=','){
    top2=push(pop(&top),top2 );
}


top =top->next ;
while(top){
    if(top ->data != pop(&top2)){
        return 0 ;
    }
else {
    top =top->next ;
}
}
return 1;
}

int main (){
struct node * top =NULL ;
create(&top)  ;
int num =ispalindrome(top) ;
printf((num==1)?"\n palindrome":"\n not a palindrome" );

return 0 ;

}
