#include <stdio.h>
#include <stdlib.h>
struct node {
int exponent  ;
float coeffient  ;
struct node * next  ;

};
struct node * add_at_empty(float  coef,int exp){
struct node * head  = malloc(sizeof(struct node));
head->next = NULL ;
head ->coeffient = coef ;
head->exponent = exp ;
return head ;

};
struct node * add_at_beg(int exp ,float coef,struct node * head ){
struct node * newp = add_at_empty(coef,exp);
newp->next =  head ;
head =  newp ;
return head ;

};
struct node *add_at_end(int exp , float coef , struct node * head){
struct node * newp = add_at_empty(coef,exp ) ;
struct node *ptr = head ;
while(ptr->next !=NULL ){
    ptr= ptr->next ;
}
newp->next =NULL;
ptr ->next  = newp ;
return head ;

};
struct node * add_in_decend(int exp,float coef ,struct node * head ){
if(head == NULL){
    head =add_at_empty(coef,exp) ;
    return head ;
}
else if(head->next ==NULL ){
    if(exp < head->exponent) {
        head =add_at_end(exp,coef,head) ;
        return head    ;
    }
    else
    {
        head =add_at_beg(exp,coef,head) ;
    }



}
else {
    struct node * ptr = head ;
    struct node * temp =add_at_empty(coef,exp) ;
    if(ptr->exponent < temp->exponent){
        head=add_at_beg(exp,coef,head) ;

        return head  ;
    }
    else {

    while(ptr->next !=NULL ){
        if(ptr->next->exponent < temp->exponent )  {

                temp->next = ptr->next ;
                ptr->next = temp ;
                return head ;
            }
ptr = ptr->next ;

        }

}
head =add_at_end(exp,coef,head);

}
return head ;


};



struct node * create(struct node * head ){
int exp ; float coef ;
int n ;
printf("\n enter number of terms ") ;
scanf("%d",&n);
for(int i =0 ; i <n ; i++){
        printf("\n enter the coeffient for term number:%d ",i+1) ;
        scanf("%f",&coef);
        printf("\n enter the exponent for term number:%d ",i+1) ;
        scanf("%d",&exp) ;
        head =add_in_decend(exp,coef,head ) ;

}

return head ;

};

struct node * add_poly(struct node * head1,struct node * head2){
struct node * newhead  =NULL ;
struct node * ptr1 =head1 ;
struct node * ptr2 =head2 ;
while(ptr1!=NULL){
    newhead=add_in_decend(ptr1->exponent,ptr1->coeffient,newhead);
    ptr1 = ptr1->next ;
}

while(ptr2!=NULL){
    newhead=add_in_decend(ptr2->exponent,ptr2->coeffient,newhead);
    ptr2 = ptr2->next ;
}
struct node *sum = NULL ;
ptr1 = newhead ;
ptr2 = newhead->next ;
while(ptr2->next!=NULL){
    if(ptr1->exponent==ptr2->exponent){
        sum =add_in_decend(ptr1->exponent,ptr1->coeffient+ptr2->coeffient,sum) ;
        ptr1=ptr1->next->next ;
        ptr2=ptr1->next ;
    }
    else{
        sum =add_in_decend(ptr1->exponent,ptr1->coeffient,sum) ;
        ptr1=ptr1->next;
        ptr2=ptr1->next ;
    }

}
if(ptr1->exponent==ptr2->exponent){
    sum =add_in_decend(ptr1->exponent,ptr1->coeffient+ptr2->coeffient,sum);

return sum ;

}
else {
    sum =add_in_decend(ptr1->exponent,ptr1->coeffient,sum) ;
    sum =add_in_decend(ptr2->exponent,ptr2->coeffient,sum) ;
return sum ;
}


return sum;
};
void show(struct node * head ){
struct node * ptr = head ;
printf("\n ") ;
while(ptr!=NULL ){

    printf("%.1f x%d ",ptr->coeffient,ptr->exponent) ;
    if(ptr->next!=NULL){
        printf(" + ");

    }
    else{
        printf("\n ");
    }

    ptr= ptr->next;

}

}


int main()
{
struct node * zero = add_at_empty(0,0) ;
struct node * head = NULL ;
head =create(head) ;
head = add_poly(head,zero) ; //if poly has like terms this fix the error
struct node * head2 = NULL ;
head2=create(head2) ;
head2 = add_poly(head2,zero) ; //if poly has like terms this fix the error
struct node * head3 =NULL;
head3 =add_poly(head,head2) ;
show(head) ;
show(head2) ;
show(head3) ;

return 0;

}
