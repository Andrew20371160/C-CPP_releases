#include <stdio.h>
#include <stdlib.h>
struct node {
char data ;
struct node * next ;
};
int isempty(struct node *top );
struct node * add_at_empty(char ch){
struct node * top = malloc(sizeof(struct node )) ;
top->next = NULL;
top->data =ch ;
return top ;
};
void push(char ch ,struct node **top){
if(isempty(*top)) {
    *top =add_at_empty(ch) ;
    return ;
}
else {
    struct node * temp = add_at_empty(ch) ;
    temp->next = (*top) ;
    (*top) = temp ;
    return ;
}

}
char pop(struct node **top){
char val = (*top)->data ;
struct node * temp = (*top);
(*top) = (*top)->next ;
free(temp) ;
return val ;
}
int isempty(struct node *top){
return(top==NULL);
}

void show(struct node *top){
struct node * ptr = top;
if(isempty(top)) {
    printf("\n list is empty ") ;
    return ;
}
printf("\n ");
while(ptr){
    printf(" %d ",ptr->data) ;
    ptr = ptr->next ;
}
}
int is_clean_brackets(char * str ){
struct node * top =NULL ;
while(*str){
    if((*str == '(' ) || (*str== '<')||(*str =='[')||( *str =='{')){
        push(*str,&top) ;
        str++ ;

}
else if((*str == ')' ) || (*str== '>')||(*str ==']')||( *str =='}')){
if(isempty(top) ){
    printf("\n left brackets are less than right brackets") ;
    return 0 ;
}
switch(*str){
case ')' :if(pop(&top)=='(') ;str++;break ;
case '>' :if(pop(&top)=='<') ;str++;break ;
case ']' :if(pop(&top)=='[') ;str++;break ;
case '}' :if(pop(&top)=='{') ;str++;break ;
default : printf("\n invalid expression ") ; return 0 ;

}

}
else
    str++;
}
if(isempty(top)){
    printf("\n brackets are well balanced ");
    return 1 ;
}
else
    return 0  ;

}
int main()
{
char str[30]  ;
char ch  ; 
printf("\n enter brackets ") ;
scanf("%s",str) ;
int n = is_clean_brackets(str) ;
printf((n==1)? "TRUE":"FALSE") ;
scanf("%c",&ch) ;

    return 0;
}
