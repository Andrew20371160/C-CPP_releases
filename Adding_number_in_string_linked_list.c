#include <stdio.h>
#include <stdlib.h>
struct node {
int data ;
struct node * next ;
};
struct node * add_at_empty(int d ){
struct node * head = malloc(sizeof(struct node));
head->data =d ;
head->next = NULL ;
return head ;


};
struct node * add_at_beg(int d , struct node * head){
struct node * temp = add_at_empty(d) ;
temp->next = head ;
head =temp ;
return head ;

};
struct node * add_at_end(int d , struct node * head){
if(head==NULL ){
    head =add_at_empty(d) ;

}
else if(head->next == NULL ){
    struct node * temp = add_at_empty(d);
    temp->next = NULL;
    head->next = temp ;
    return head ;


}
else {
    struct node * temp = add_at_empty(d);
    struct node * ptr = head ;
    while(ptr->next !=NULL ){
        ptr = ptr->next ;
    }
temp->next =NULL;
ptr->next = temp ;
}
return head ;

};
int power(int d,int p){
if(p ==0 ){
    return 1;
}
else{
    return d*power(d,--p);
}
};
int rest_div(int d ){
if(d<10 ){
    return d ;
}
else {
    return rest_div(d%10) ;
}
}
struct node * create(struct node* head){
int num ; int data ;
int n ;
printf("\n enter number of digits : ") ;
scanf("%d",&n);
printf("\n enter number :") ;
scanf("%d",&num);
for(int i = 1 ;  i<=n ;  i++){
    data = rest_div(num/(power(10,n-i))) ;
    head =add_at_beg(data,head) ;
}
return head ;



};
int num_size(struct node * head){
int size = 0 ;
struct node * ptr = head ;
while(ptr!=NULL){
    size++;
    ptr = ptr->next ;
}
return size ;

}

void show(struct node * head);

struct node * add_number(struct node * head1 ,struct node * head2 ){
struct node * ptr1 = head1 ;
struct node * ptr2 = head2 ;
struct node * sum = NULL;
int s1 = num_size(head1) ;
int s2= num_size(head2) ;
if(s1<s2){
    for(int i =  0 ; i<s2-s1 ; i++){
        head1 =add_at_end(0,head1) ;
    }
}
else {
    for(int i =  0;i<s1-s2 ; i++){
        head2 =add_at_end(0,head2) ;
    }
}
while(ptr1!=NULL ){
sum =add_at_beg(ptr1->data +ptr2->data,sum) ;
if(sum->data >=10){
    sum->data-=10 ;
    int rest = 1;
    if(ptr1->next == NULL ){
      sum = add_at_beg(rest,sum);
      break ;
    }
else{
    ptr1->next->data +=1 ;
}
}
ptr1= ptr1->next ;
ptr2=ptr2->next ;
}
return sum ;
};


void show(struct node * head){
printf("\n");
struct node * ptr =  head ;
while(ptr!=NULL){
    printf("%d",ptr->data);
        ptr =ptr->next ;
}
}
int main()
{
struct node * head1 = NULL;
head1 =create(head1) ;
struct node * head2  =  NULL ;
head2 = create(head2) ;
struct node * head3 = add_number(head1,head2) ;
show(head3);
    return 0;
}
