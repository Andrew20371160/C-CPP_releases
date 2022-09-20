#include <stdio.h>
#include <stdlib.h>
#include<string.h>
char postfix[100];

struct node {
char data  ;
struct node * next ;
};
int precedence(char op){
switch(op){
case '+' :
case '-' :
return 1 ;
case '*':
case '/':
return 2;
case '^':
    return 3;
default :return 0 ;
}

}


unsigned int power(int num   ,int pow){
if(pow ==0){
    return 1 ;
}
else
    return num *power(num,--pow) ;

}

int isempty(struct node *top ){
return (top==NULL );
};
struct node *add_at_empty(char data ){
struct node * top = malloc(sizeof(struct node));
top->data =data ;
top->next =NULL ;
return top ;
};
void push(char  ch ,struct node **top){
if(isempty(*top)){
    (*top ) =add_at_empty(ch ) ;
    return ;
}
struct node * temp = add_at_empty(ch) ;
temp->next = (*top)  ;
(*top) = temp ;
};
char pop(struct node **top ){
struct node * temp = (*top)  ;
char val = temp->data ;
(*top) = (*top)->next ;
free(temp) ;
return val ;
}
float post_value(){
struct node *top = NULL ;
int a,b ;
for(int i =0 ; i <strlen(postfix);i++){
    if(postfix[i] >='0'&&postfix[i]<='9' ){
        push(postfix[i]-'0',&top)  ;
    }
    else{
    a =pop(&top);
    b = pop(&top) ;
    switch(postfix[i]){
    case'+': push(b+a,&top);break;
    case'-': push(b-a,&top);break;
    case'*': push(b*a,&top);break;
    case'/': push(b/a,&top);break;
    case'^': push(power(b,a),&top);break;



}


    }
}
return pop(&top) ;
}

void show (struct node *top ){
if(isempty(top)){
    printf("\n list is empty ") ;
    return ;
}


struct node *ptr = top ;
printf("\n") ;
while(ptr!=NULL){
    printf("%c ",ptr->data) ;
    ptr = ptr->next ;
}
}
int rest_div (int num ){
if(num<10){
    return num ;
}
else
    return num* rest_div(num%10);

}
int str_to_int(char *str ){
int j = 0;
int result = 0 ;
int arr[100] ;
while(*str){
    arr[j++] =(*(str)-'0');
str++ ;
}

for(int i= 0 ; i <j;i++){
    result+=arr[i]*power(10,j-1-i);
}
return result ;
}


void infix_to_postfix(char* infix ){
struct node * top = NULL ;
char symbol ,next ;
int j = 0 ;
for(int i =  0 ; i <strlen(infix);i++){
symbol = infix[i] ;
switch(symbol){
case '(' :push(symbol,&top) ; break  ;
case ')' :while((next =pop(&top))!='('){
postfix[j++] = next ;
}break ;
case '+' :
case '-' :
case '*' :
case '/' :
case '^' :
    while(!isempty(top)&&precedence(top->data)>= precedence(symbol)){
        postfix[j++]=pop(&top);
    }
push(symbol,&top) ;break  ;
default: postfix[j++] = symbol ;break  ;
}
}
while(top!=NULL ){
    postfix[j++] = pop(&top)  ;
}
postfix[j+1] = '\0';


}

int main()
{
char str[100] ; 
scanf("%s",str) ; 
infix_to_postfix(str) ;
post_value()  ;

    return 0;
}
