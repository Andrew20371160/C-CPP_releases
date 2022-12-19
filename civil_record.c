//btw you know how c sucks in taking multiple string input so if you test it you will find weird output
//but the data structure itself is functioning well feel free to develop it the way you see it better :)

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 30
struct date{
int day , month,year;
};
//numerical data
struct numerical{
int nat_num ;
struct date bdate;
};
//text data
struct text{
char full_name[max] ;
char  mom_name[max];
char  address[max] ;
};
//tree structure
struct node{
struct numerical  ndata ;
struct text tdata ;
struct node * right ;
struct node * left ;
};
// copy functions
void cpy_numer(struct numerical * dest , struct numerical * src ){
dest->nat_num = src->nat_num;
dest->bdate.day = src->bdate.day ;
dest->bdate.month=src->bdate.month ;
dest->bdate.year = src->bdate.year ;

}
void cpy_text(struct text * dest , struct text * src){
strcpy(dest->address,src->address) ;
strcpy(dest->full_name,src->full_name) ;
strcpy(dest->mom_name,src->mom_name) ;
}
//occupy data for root function
struct node * get_data(struct numerical num_src,struct text text_src){
struct node * root = malloc(sizeof(struct node ));
cpy_numer(&root->ndata,&num_src) ;
cpy_text(&root->tdata,&text_src) ;
root->right = NULL ;
root->left = NULL ;
return root ;
}
//insert func
struct node * insert(struct node * root ,struct numerical ndata , struct text tdata ){
if(root ==NULL){
    root = get_data(ndata,tdata) ;
        return root ;

}
else if(ndata.nat_num==root->ndata.nat_num){
printf("National number already exist ") ;
return root ;
}

else if(ndata.nat_num>root->ndata.nat_num){
    root->right = insert(root->right,ndata,tdata);
}

else if(ndata.nat_num<root->ndata.nat_num){
    root->left = insert(root->left,ndata,tdata);
}

};
//search func
struct node * search(int nat_num,struct node *root ){
if(root ==NULL){
    return root ;
}
else if(nat_num==root->ndata.nat_num){
printf("\nNational Number : %d",root->ndata.nat_num);
printf("\nFull Name: %s",root->tdata.full_name);
printf("\nMother's Name : %s",root->tdata.mom_name);
printf("\nDate of birth : %d/%d/%d",root->ndata.bdate.day,root->ndata.bdate.month,root->ndata.bdate.year);
printf("\nAddress : %s",root->tdata.address);
return root ;
}
else if (nat_num>root->ndata.nat_num){
    return search(nat_num,root->right) ;
}
else if (nat_num<root->ndata.nat_num){
    return search(nat_num,root->left) ;
}

}

void insert_data_via_user(struct node ** root ){
struct numerical ndata  ;
struct text tdata  ;
//getting Numerical data
printf("Enter national number : ");
scanf("%d",&ndata.nat_num) ;
printf("Enter date of birth as follows(day month year)(hit space-bar after each number ): ");
scanf("%d",&ndata.bdate.day);
scanf("%d",&ndata.bdate.month);
scanf("%d",&ndata.bdate.year) ;
//getting text data
printf("Enter Full Name : ");
fgets(tdata.full_name,max,stdin) ;
getc(stdin);
printf("Enter Mother's Name : ");
fgets(tdata.mom_name,max,stdin) ;
getc(stdin);
printf("Enter address : ");
fgets(tdata.address,max,stdin) ;
getc(stdin);

(*root) = insert(*root,ndata,tdata) ;

}

int main(){
struct node * root =NULL ;
printf("\n");
insert_data_via_user(&root) ;

root =search(12,root);
free(root) ;
root = NULL ;
system("pause");
return 0 ;
}
