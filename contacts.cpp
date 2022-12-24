#include <iostream>
#include<cstring>
using namespace std;
struct node {
char* number;
char * name ;
node * right ;
node * left ;
};
// the number is in char type to allow a more advanced search type of function (search_by_number(node * root , char * number))
//make memory and insertion functions
node * get_node(char* number , char * name ){
node * newnode = new node ;
newnode->number = new char[strlen(number)+1];
strcpy(newnode->number,number);
newnode->name = new char[strlen(name)+1];
strcpy(newnode->name,name) ;
newnode->left = NULL;
newnode->right = NULL;
return newnode ;
}
node * insert_node(node * root , char* number , char * name ){
if(root==NULL){
    root = get_node(number,name);
    return root ;
}
else if(strcmp(name,root->name)<=0){
    root->left =insert_node(root->left ,number ,name);
}
else {
    root->right = insert_node(root->right,number,name) ;
}
}
//search functions
void show_node(node * root){
if(root==NULL){
return ;
}
cout<<endl<<"Name : "<<root->name<<endl;
cout<<endl<<"Number : "<<root->number<<endl;
}
void search_by_name(node* root,char *name){
if(root==NULL){
    return ;
}
//this line if user sends a full correct name it's faster that way to find the contact wanted
else if(strcmp(root->name,name)==0){
show_node(root);
}
else {
//explanation of the following lines of codes is in search_by_number function
int s = strlen(name);
char * portion = new char[s];
for(int i = 0 ; i<s;i++){
    *(portion+i) = *(root->name+i);
}
*(portion+s)= NULL;
if(strcmp(portion,name)==0){
    show_node(root);
}
}
search_by_name(root->left,name);
search_by_name(root->right,name) ;
}
void search_by_number(node*root,char*number){
if(root==NULL){
    return ;
}
else if(strcmp(root->number,number)==0){
show_node(root);
}
else {

//here we want to check if the portion the user gives us is exactly as the portion of the number in the current node (both of the same size)
//meaning if user sends "22" then we compare it with first 2 digits of the number in the node and so on
int s = strlen(number);
char * portion = new char[s];
for(int i = 0 ; i<s;i++){
    *(portion+i) = *(root->number+i);
}
//don't forget to put null at last character to prevent bugs of having some joker sticker in the end of the (portion) string
*(portion+s)= NULL;
//we compare that portion and then magic happens :)
if(strcmp(portion,number)==0){
    show_node(root);
}
}
search_by_number(root->left,number);
search_by_number(root->right,number) ;
}
void inorder(node * root){
if(root==NULL){
    return ;
}
inorder(root->left);
show_node(root) ;
inorder(root->right) ;
}
//deletion functions
node * find_min(node * root){
if(root->left==NULL){
    return root ;
}
return find_min(root->left);
}
node * del_node(node * root, char*name){
if(root==NULL){
    return root ;
}
else if(strcmp(name,root->name)<0){
    root->left = del_node(root->left ,name);
}
else if (strcmp(name,root->name)>0) {
   root->right = del_node(root->right,name) ;
}
else{
if(root->left==NULL&&root->right ==NULL){
    delete[]root ;
    root=NULL;
}
else if(root->left==NULL){
    node*temp = root;
    root =root->right ;
delete[]temp ;
}
else if(root->right==NULL){
    node*temp = root;
    root =root->left ;
    delete[]temp;
}
else {
    node*temp = find_min(root->right) ;
    root->name = new char[strlen(temp->name)+1];
    strcpy(root->name,temp->name);
    root->number = temp->number ;
    root->right = del_node(root->right,temp->name);

}

}
return root ;
}

node *del_all(node*root){
if(root==NULL){
    return root ;
}
root = del_node(root,root->name);
}
int main()
{
node*root = NULL ;
char *names[6] = {"andrew","peter","andy","james","mark","ashe"};
char * numbers[6] = {"1122","3568","7922","9871","1547","1988"};
for(int i= 0 ; i <6 ;i++){
    root = insert_node(root,numbers[i],names[i]);
}
cout<<"1st test \n";
search_by_name(root,"a") ;
cout<<"2nd test \n";
search_by_name(root,"an") ;
cout<<"3rd test \n";
search_by_name(root,"and") ;
cout<<"last test \n";
search_by_name(root,"andr");
del_all(root);
//same applies for search_by_number function
system("\npause");
    return 0;
}
