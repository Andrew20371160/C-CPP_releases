#include<iostream>
using namespace std ;
struct node {
int data ;
node*next ;
node*prev ;
};
node * get_node(int d ){
node *newnode = new node ;
newnode ->data = d ;
newnode->next = newnode ;
newnode->prev = newnode ;
return newnode ;
}
node * add_at_beg(int d , node * tail ){
if(tail ==NULL){
    tail = get_node(d) ;
}
else {
node * newnode = get_node(d);
newnode->next = tail->next ;
newnode->prev = tail ;
tail->next->prev = newnode ;
tail->next = newnode ;
}
return tail ;
}
node * add_at_end(int d , node * tail ){
if(tail ==NULL){
    tail = get_node(d) ;
}
else {
node * newnode = get_node(d);
newnode->prev = tail ;
newnode->next = tail ->next ;
tail->next->prev = newnode ;
tail->next = newnode ;
tail  = newnode ;
}
return tail ;
}

node * insert_while_sorting(int d , node * tail ){
if(tail ==NULL){
    tail  =get_node(d) ;
    return tail ;
}
    if(d<tail->next->data){
        tail =add_at_beg(d,tail);
}

    else if(d>tail->data){
        tail = add_at_end(d,tail) ;
    }


else{
node * newnode = get_node(d);
node * curr= tail ->next ;
while(newnode->data>curr->data){
curr=curr->next ;
}
newnode->next= curr;
newnode->prev =curr->prev ;
curr->prev->next = newnode;
curr->prev = newnode ;
}
return tail;
}
void show(node*tail){
if(tail==NULL){
    return ;
}
cout<<endl;
node * curr  =tail ->next;
do{
cout<<curr->data<<" " ;
curr=curr->next;
}while(curr !=tail->next);
}

int main (){
node * tail = NULL ;
tail = insert_while_sorting(5,tail) ;
tail = insert_while_sorting(7,tail) ;
tail = insert_while_sorting(-3,tail) ;
tail = insert_while_sorting(0,tail) ;
tail = insert_while_sorting(5,tail) ;
tail = insert_while_sorting(-5,tail) ;
tail = insert_while_sorting(500,tail) ;
tail = insert_while_sorting(-3,tail) ;
tail = insert_while_sorting(78,tail) ;
tail = insert_while_sorting(100,tail) ;
tail = insert_while_sorting(-5,tail) ;
tail = insert_while_sorting(-1,tail) ;
tail = insert_while_sorting(3,tail) ;
tail = insert_while_sorting(8,tail) ;
tail = insert_while_sorting(59,tail) ;

show(tail);
system("pause");
delete[]tail;

return 0 ;
}
