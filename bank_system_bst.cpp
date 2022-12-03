#include <iostream>
#include<cstring>
#define MAX 35
using namespace std;
struct node {
char full_name[MAX];
int acc_num ;
float rec ;
node * left ;
node * right ;
};

class bank_system{
    public:
     node* root  ;

    bank_system(){
    root =NULL ;
    }
    node * add_at_empty(int  , char * ,float  ) ;
    node * insert_acc(int ,float , char * , node *) ;
    node * search_acc(int num , node * root ) ;
    node * del_acc(int acc_num, node * root );
    node * find_max(node * ) ;
    node * update_acc(int n ,node *root );
    void bank_gui() ;



};
node * bank_system ::add_at_empty(int acc_num , char * name ,float rec ){
root  = new node ;
root ->acc_num  = acc_num ;
root->rec= rec ;
strcpy(root->full_name,name) ;
root->left = NULL ;
root->right = NULL ;
return root ;
}
node * bank_system::insert_acc(int acc_num , float rec , char * name ,node * root ){
if(root ==NULL){
    root =add_at_empty(acc_num,name,rec) ;
}
else if (acc_num==root->acc_num){
    cout<<"\n account number already int use" ;

}
else if (acc_num<root->acc_num){
    root->left = insert_acc(acc_num,rec,name,root->left ) ;
}
else if(acc_num>root->acc_num){
    root->right = insert_acc(acc_num,rec,name,root->right );
}
    return root ;

}
node * bank_system:: search_acc(int num , node * root ) {
if(root ==NULL ){
    cout<<"\n not found or system is empty" ;
    return root ;
}
else if (num == root->acc_num){
    cout<<endl<<"Full name :"<<root->full_name ;
    cout<<endl<<"Account number :"<<root->acc_num ;
    cout<<endl<<"Record :"<<root->rec ;
    return root ;
}
else if (num<root->acc_num){
    return search_acc(num , root ->left ) ;

}
else if (num>root->acc_num){
    return  search_acc(num , root ->right ) ;

}

return root ;
}
node * bank_system ::find_max(node * root ){
if(root ==NULL){
    cout<<"\n no accounts " ;
    return root ;
}
else if (root ->right ==NULL){
    return root ;
}
else {
find_max(root->right ) ;
}

}
node * bank_system:: del_acc(int n , node * root ){
if(root ==NULL){
cout<<"\n system has no records " ;
return root ;
}
else if (n <root->acc_num){
    root->left = del_acc(n,root->left ) ;
}
else if (n>root->acc_num){
    root ->right = del_acc(n,root->right )  ;
}
else {
if(root->left ==NULL && root->right ==NULL){
    delete[]root ;
    root = NULL ;
}
else if (root ->left ==NULL){
    node * temp = root ;
    root = root ->right ;
    delete[]temp ;
    temp = NULL ;
}

else if (root ->right  ==NULL){
    node * temp = root ;
    root = root ->left  ;
    delete[]temp ;
    temp = NULL ;
}
else {
node * temp = find_max(root->left ) ;
root ->acc_num = temp->acc_num ;
strcpy(root->full_name,temp->full_name) ;
root ->rec = temp ->rec ;
root->left= del_acc(temp->acc_num,root->left ) ;
}

}
return root ;
};
node *bank_system:: update_acc(int n ,node *root ){
(root )= search_acc(n,root )  ;
if(root  ==NULL){
return root ;
}
int choice ;
cout<<endl<<"\n Please choose what you want to update : \n " ;
cout<<endl<<"1--Name \n 2--record \n 3-Back to main menu";
cin>>choice ;
switch(choice){
case 1: {cout<<"\n enter the name ";
cout<<endl ;
cin.getline((root)->full_name,MAX,'&') ;
cout<<endl ;
bank_gui() ;
} ; break ;

case 2 : {
cout<<"\n enter new record ";
cin>>(root )->rec;
bank_gui() ;
};break ;

case 3: bank_gui() ; break ;
}
return root ;
}

void bank_system::bank_gui(){
while(true){
int n ;
cout<<"\n 1--Insert an account into the system ";
cout<<"\n 2--Search for an account in the system ";
cout<<"\n 3--Delete an account from the system ";
cout<<"\n 4--Update an account name or record ";
cout<<"\n 5--Update account number or whole account data ";
cout<<"\n 6--quit ";
cin>>n ;
switch(n){
case 1 : {int acc_n ; float rec ; char name[MAX];
cout<<"\n enter the account number ";
cin>>acc_n ;
cout<<endl;
cout<<"\n enter the full name ";
cin.getline(name,MAX,'&') ;
cout<<endl;
cout<<"\n enter the account record ";
cin>>rec ;
root = insert_acc(acc_n,rec,name,root) ;
bank_gui() ;
};break ;
case 2:{
int n ;
cout<<"\n enter the account number you want to search for : " ;
cin>>n ;
root = search_acc(n,root) ;
bank_gui() ;
};break ;
case 3 :{
int n ;
cout<<"\n enter the account number you want to delete : " ;
cin>>n ;
root= del_acc(n,root) ;
bank_gui() ;
}; break ;
case 4 :{
cout<<"\n enter the account number you want to update : " ;
cin>>n ;
root = update_acc(n,root) ;
bank_gui() ;
}break ;
case 5 :{

int num , choice ;
cout<<"\n Enter the account number you want to update ";
cin>>num ;
root = search_acc(num,root) ;
cout<<"\n Please choose wisely what you want yo update \n  1----Account number only \n 2---whole account data ";
cin>>choice ;
switch(choice){
case 1 :{
int new_num ;
int old_num = root->acc_num ;
float rec = root->rec ;
char str[MAX] ;
 strcpy(str ,root->full_name) ;
cout<<"\n enter the new account number " ;
cin>>new_num;
root = insert_acc(new_num,rec,str,root) ;
root = del_acc(old_num,root) ;
bank_gui() ;
};break ;
case 2 :{
int acc_n ;
float rec ;
char name[MAX];
int old_num = root->acc_num ;
cout<<"\n enter the account number ";
cin>>acc_n ;
cout<<endl;
cout<<"\n enter the full name ";
cin.getline(name,MAX,'&') ;
cout<<endl;
cout<<"\n enter the account record ";
cin>>rec ;
root = insert_acc(acc_n,rec,name,root) ;
 del_acc(old_num,root) ;
bank_gui() ;
 }break ;

 default :{cout<<"\n wrong choice ";bank_gui() ;
}break ;
}
bank_gui();
};break;
case 6 :exit(0) ;
}
}

}
int main()
{
bank_system b1 ;
b1.bank_gui() ;

    return 0;
}

