#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
int book_number ;
int price ;
char *book_name ;
char *author  ;
struct node * left ;
struct node * right ;
};
struct node * action = NULL ;
struct node * horror = NULL ;
struct node *comedy =NULL ;
struct node *romance = NULL ;

struct node * get_empty(int bnum,int price ,char * author,char *bname){
struct node * book = malloc(sizeof(struct node )) ;
book->book_number = bnum ;
book->price = price ;
book->book_name = (char *) malloc(sizeof(strlen(bname)+1)) ;
strcpy(book->book_name,bname) ;

book->author = (char *) malloc(sizeof(strlen(author)+1)) ;
strcpy(book->author ,author ) ;

book->right = NULL ;
book->left = NULL;
return book ;
};
struct node * insert(struct node * root ,int bnum ,int price ,char * author,char*bname ){
if(root ==NULL){
    root =get_empty(bnum,price,author,bname ) ;
}
else if(strcmp(bname,root->book_name)<=0){
root->left =insert(root->left ,bnum,price,author,bname) ;
}
else{
root->right =insert(root->right,bnum,price,author,bname) ;
}

return root ;
};
void choose_category_for_insertion(int cat,int bnum,int price ,char * author,char *bname ){
switch(cat){
case 1 :action =insert(action,bnum,price,author,bname); break ;
case 2 :romance =insert(romance,bnum,price,author,bname); break ;
case 3 :horror =insert(horror,bnum,price,author,bname); break ;
case 4 :comedy =insert(comedy,bnum,price,author,bname); break ;
default : printf("\n wrong choice") ;return ;
}
}
void search_book(char*bname,struct node*root) ;
void choose_category_forsearch(int cat ,char * str ){
switch(cat){
case 1 :search_book(str,action); break ;
case 2 :search_book(str,romance); break ;
case 3 :search_book(str,horror); break ;
case 4 :search_book(str,comedy); break ;
default : printf("\n wrong choice") ;return;
}


}


void search_book (char * bname ,struct node *root ){
if(root ==NULL){
    printf("\n Book not found") ;
    return ;
}
else if (strcmp(bname,root->book_name)<0){
   search_book(bname,root->left) ;
}

else if (strcmp(bname,root->book_name)>0){
     search_book(bname,root->right) ;
}
else if(strcmp(bname,root->book_name)==0){
printf("\n Book name :%s\n",root->book_name) ;
printf("\n Book author:%s\n",root->author) ;
printf("\n Book number:%d\n",root->book_number) ;
printf("\n Book price :%d\n",root->price) ;

}
}
void inorder_category(struct node * root ){
if(root==NULL){
    return ;
}
inorder_category(root->left) ;
{printf("\n Book name :%s\n",root->book_name) ;
printf("\n Book author:%s\n",root->author) ;
printf("\n Book number:%d\n",root->book_number) ;
printf("\n Book price :%d\n",root->price) ;
}
inorder_category(root->right) ;
}

void library(){

while(1){
int cat,choice ;
printf("\n 1-insert a book into the library\n") ;
printf("\n 2-search for a book in the library \n") ;
printf("\n 3-show category books\n") ;
printf("\n 4-quit\n") ;
scanf("%d",&choice);
switch(choice){
case 1 :{
int bnum, price ;
char  bname[30] ; char  author[30];
printf("\n Book name :") ;
fgets(bname,30,stdin) ;
printf("\n Book author ") ;
fgets(author,30,stdin) ;
printf("\n Book number ") ;
scanf("%d",&bnum) ;
printf("\n Book price ") ;
scanf("%d",&price) ;
printf(" \n please choose the category :\n 1-action\n 2-romance\n 3-horror\n 4-comedy \n ");
scanf("%d",&cat) ;

choose_category_for_insertion(cat,bnum,price,author,bname) ;
}break;
case 2 :{

char str[30] ;
fgets(str,30,stdin) ;
printf("\n enter book name\n");

scanf("%d",&cat) ;
printf(" \n please choose the category :\n 1-action\n 2-romance\n 3-horror\n 4-comedy \n ");

choose_category_forsearch(cat,str) ;

}break ;
case 3:{

printf(" \n please choose the category :\n 1-action\n 2-romance\n 3-horror\n 4-comedy \n ");
scanf("%d",&cat) ;

switch(cat){
case 1 :inorder_category(action); break ;
case 2 :inorder_category(romance); break ;
case 3 :inorder_category(horror) ;break ;
case 4 :inorder_category(comedy); break ;
default : printf("\n wrong choice") ; break ;
}

}break;
case (4): exit(0) ;
}

}
}
int main(){

action =insert(action,1,10,"james","the killer");
action = insert(action,2,15,"mark","the shadow of a spy");
action = insert(action,3,10,"andrew","demon in you");
romance = insert(romance,4,10,"ahmed saad","ktab hyany");
romance = insert(romance,5,15,"abdelbaset hamoda","bosy kat");
romance = insert(romance,6,20,"hamdy zrzor ","kitkat");
horror = insert(horror,7,10,"sayd","the the") ;
horror = insert(horror,8,10,"lambart ","the 5 *6 !=30") ;
comedy = insert(comedy,9,10,"abdelbasset hamoda ","hya elodnya")  ;
comedy = insert(comedy,10,10,"abdelbasset 2tota","tona now ya b8law")  ;
comedy = insert(comedy,11,10,"andrew abdelbaset hamoda", "el e3agz weltfser fe bet elkber") ;
library();
return  0;

}
