#include <stdio.h>
#include <stdlib.h>
struct node  {
int expo ;
float coef ;
struct node * next ;

};
struct node * add_at_empty(int exponent ,float coefficient ){
struct node * head =  malloc(sizeof(struct node));
head->coef=coefficient;
head->expo = exponent ;
head->next = NULL ;
return head ;

};
struct node * add_at_beg(int expo ,float coef,struct node * head){
struct node * temp = add_at_empty(expo,coef) ;
temp->next = head ;
head = temp  ;
return head ;

};
struct node * add_at_end(int expo , float coef , struct node * head) {
struct node * temp = add_at_empty(expo,coef) ;
struct node * ptr = head ;
while(ptr->next !=NULL ){
    ptr = ptr->next ;
}
ptr->next = temp ;
temp->next = NULL;
return head ;
};
struct node * add_indecend (int expo , float coef ,struct node * head){
if(head == NULL ){
    head =add_at_empty(expo,coef);
    return head ;
}
else if (head ->next  == NULL ){
    if(expo >head->expo){
        head = add_at_beg(expo,coef,head) ;
        return head ;
    }
    else {
        head = add_at_end(expo,coef,head);
        return head ;
    }
}
else {
struct node * ptr = head ;
struct node * temp = add_at_empty(expo,coef) ;
    if(ptr->expo < expo ){
        head = add_at_beg(expo ,coef,head);
        return head ;
    }
    else{
        while(ptr->next !=NULL ){
            if(expo >ptr->next ->expo ){
                temp->next = ptr->next ;
                ptr->next  = temp ;
                return head  ;
            }
ptr= ptr->next ;
}

head = add_at_end(expo,coef,head) ;

    }
return head ;

}


};

struct node * create(struct node * head){
int n ;
int expo= 0  ; float coef =0.0 ;
printf("\n enter number of terms :");
scanf("%d",&n) ;
for(int i=0 ; i <n ; i++){
printf("\n enter coefficient for term %d :",i+1) ;
scanf("%f",&coef) ;
printf("\n enter exponent for term %d :",i+1) ;
scanf("%d",&expo) ;
head = add_indecend(expo,coef,head)  ;

}
return head ;


};
struct node * adjust (struct node * head ){
if(head->next== NULL  ){

return head ;

}
else if (head->next->next ==NULL){
    if(head->expo ==head->next ->expo){
      struct node *newhead = NULL;
      newhead=add_indecend(head->expo,head->coef+head->next->coef,newhead) ;
      return newhead ;
    }
    else{
        return head ;
    }

}
struct node * ptr1  = head ;
struct node * ptr2  = head->next ;
struct node * newhead  =NULL ;
while(ptr2->next->next !=NULL ){
    if(ptr1->expo == ptr2->expo){
        newhead =add_indecend(ptr1->expo,ptr1->coef+ptr2->coef ,newhead) ;
        ptr1 =ptr1->next->next ;
        ptr2 =ptr1->next;
    }
    else {
        newhead= add_indecend(ptr1->expo,ptr1->coef,newhead) ;
        ptr1=ptr1->next ;
        ptr2 = ptr1->next  ;
    }

}
if(ptr1->expo == ptr2->expo){
    newhead=add_indecend(ptr1->expo,ptr1->coef+ptr2->coef ,newhead) ;
    newhead =add_indecend(ptr2->next->expo,ptr2->next->coef,newhead) ;
}

else{
if(ptr2 ==NULL){
    newhead = add_indecend(ptr1->expo,ptr1->coef,newhead) ;
    return newhead;
}
else{
    newhead = add_indecend(ptr1->expo,ptr1->coef,newhead) ;
    newhead = add_indecend(ptr2->expo,ptr2->coef,newhead) ;
    newhead = add_indecend(ptr2->next->expo,ptr2->next->coef,newhead) ;


    return newhead ;

}
}


return newhead;
};
struct node * mult_poly(struct node * head1 ,struct node * head2){
struct node * ptr1 = head1;
struct node * ptr2 = head2;
struct node * sum = NULL ;
while(ptr1!=NULL ){
ptr2=head2 ;

while(ptr2!=NULL){
sum = add_indecend(ptr1->expo+ptr2->expo,ptr1->coef*ptr2->coef,sum) ;
ptr2=ptr2->next ;

}
ptr1=ptr1->next ;

}
return sum ;
};

void show(struct node * head ){
struct node * ptr = head ;
while(ptr!=NULL ){
    printf("%.1f x%d ",ptr->coef,ptr->expo) ;
    ptr = ptr->next ;
    if(ptr!=NULL){
        printf("+");
    }
    else{
        printf("\n");
    }
}

}

int main()
{
struct node * head1  = NULL ;
struct node * head2  = NULL ;
struct node * head3  = NULL ;
head1=create(head1) ;
head1=adjust(head1) ;
head2 =create(head2) ;
head2 = adjust(head2) ;
head3 = mult_poly(head1,head2) ;
head3 = adjust(head3) ;
show(head1);

show(head2) ;

show(head3);
    return 0;
}
