#include<iostream>
#include<string.h>
#define MAX 30
using namespace std ;
struct node {
int acc_num ,rec ;
char  name[MAX] ;
node * left ;
node * right ;
};
node * get_node(int acc_num , int rec ,char * name  ){
node * root = new node ;

root->acc_num = acc_num ;
root->rec = rec ;
strcpy(root->name ,name) ;
root->left = NULL ;
root->right = NULL ;
return root ;
}
node * insert_node(int acc_num,int rec , char * name , node * root ){
if(root ==NULL){
    root = get_node(acc_num,rec,name);
    return root ;
}
else if (acc_num ==root->acc_num){
    cout<<"\n account number "<<acc_num<<" already in use \n";
    return root;
}
else if (acc_num >root->acc_num){
root->right =insert_node(acc_num,rec,name,root->right) ;
}

else if (acc_num <root->acc_num){
  root->left = insert_node(acc_num,rec,name,root->left) ;
}

}
node * find_max(node * root ){
if(root ==NULL){
    return NULL ;

}
else if (root ->right==NULL){
    return root ;
}
return find_max(root->right) ;
}
node * del_node(int acc_num,node * root ){
if(root==NULL){
        cout<<"system is empty ";
    return root ;
}
else if (acc_num >root->acc_num){
    root->right = del_node(acc_num,root->right) ;
}

else if (acc_num <root->acc_num){
    root->left = del_node(acc_num,root->left) ;
}
else {
    if(root->left ==NULL && root->right ==NULL){
        delete[]root ;
        root =NULL ;
    }
    else if (root ->left == NULL){
        node * temp = root ;
        root = root->right ;
        delete[]temp ;
        temp = NULL ;
    }
    else if (root ->right == NULL){
        node * temp = root ;
        root = root->left ;
        delete[]temp ;
        temp = NULL ;
    }
    else {
        node * temp = find_max(root->left) ;
        root->acc_num = temp->acc_num ;
        root->rec= temp ->rec ;
        strcpy(root->name,temp->name) ;
        del_node(temp->acc_num,root->left) ;
    }
    return root ;
}
}
node * search_node(int n , node * root ){
if(root ==NULL){
    return root ;
}
else if (root ->acc_num ==n){
cout<<endl<<root->acc_num;
cout<<endl<<root->name;
cout<<endl<<root->rec<<endl;
return root;
}
else if (n>root->acc_num){
    return search_node(n,root->right) ;
}
else {
    return search_node(n,root->left) ;
}
}
void show_nodes(node * root ){
if(root ==NULL){
    return;
}
show_nodes(root->left);
cout<<endl<<root->acc_num;
cout<<endl<<root->name;
cout<<endl<<root->rec<<endl;
show_nodes(root->right) ;
}

node * enter_acc_via_user(node * root ){
int acc_num,rec ;
char name[MAX] ;
cout<<"\n enter the account number ";
cin>>acc_num ;
cout<<endl<<"enter the name " ;

cin.getline(name,MAX,'&');
cout<<endl<<"enter the record ";
cin>>rec;
return insert_node(acc_num,rec,name,root);
}
void interface(node * root ){

cout<<"\n---BANK-INFORMATION-SYSTEM----";
while(1){
int n ;

cout<<endl<<"1---Insert an account\n2---Search for an account\n3---Delete an account\n4---show all accounts (that's just for fun :) )\n5---quit";
cin>>n ;
switch(n){
case 1 :{
root =enter_acc_via_user(root);
}break ;
case 2 :{
int n  ;
cout<<endl<<"enter the account number ";
cin>>n ;
node * view =NULL ;
view = search_node(n,root);
}break ;
case 3 :{
int n ;
cout<<"\n enter the account number " ;
cin>>n ;
node * del= NULL ;
del = del_node(n,root) ;
}break ;
case 4 :show_nodes(root) ; break ;

case 5 : cout<<"\n Software was made possible by Andrew karam :) " ;system("pause"); exit(0);
}
}
}
int main (){

node * root = NULL ;
interface(root) ;

return 0 ;
}
