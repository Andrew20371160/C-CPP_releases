#include <iostream>
#include<cmath>
using namespace std;

struct roots{
float x1 =0.0,x2 =0.0 ;
};
roots quad_sol_real_only(float a , float b , float c ){
roots quad_roots ;
if( (b*b -4*a*c) <0 ){
    cout<<"\n can't calculate hence (b*b -4*a*c) <0 " ;
    return quad_roots ;
}
else {
    quad_roots.x1  =  (-1*b - sqrt(b*b-4*a*c)) /(2*a) ;
        quad_roots.x2  =  (-1*b + sqrt(b*b-4*a*c)) /(2*a) ;
        return quad_roots ;
}

}
roots quad_sol_real_only_loss_significance(float a , float b , float c ){
roots quad_roots ;
if( (b*b -4*a*c) <0 ){
    cout<<"\n can't calculate hence (b*b -4*a*c) <0 " ;
    return quad_roots ;
}
else {
   if(b>0 ){
    quad_roots.x1 = -2*c/(b+b) ;
    quad_roots.x2 = (-2*b) /(2*a) ;
    return quad_roots ;
   }

}
    return quad_roots ;

}

roots quad_sol_Complex_numbers(float a , float b , float c ){
roots quad_roots ;
if( (b*b -4*a*c) >0 ){
 quad_roots = quad_sol_real_only(a,b,c) ;
 return quad_roots ;
}
else {
   quad_roots.x1 = (-1*b)/(2*a)  ;
   quad_roots.x2 = -1*sqrt(-1*(b*b-4*a*c))/(2*a) ;
   return quad_roots ;

}
return quad_roots ;
}
int main()
{
char ch ;
int choice ;

while(ch!='n'){

float a,b,c ;
roots r1 ;
cout<<"enter a , b and c ";
cin>>a>>b>>c ;
cout<<"\n  1-real roots only without significance loss \n 2-real roots only with significance loss \n 3-the roots are complex";
cin>>choice ;
switch(choice){
case 1 : r1 = quad_sol_real_only(a,b,c);  cout<<"X1 = "<<r1.x1<<"     X2 = "<<r1.x2 ;break ;

case 2 : r1 = quad_sol_real_only_loss_significance(a,b,c) ;  cout<<"X1 = "<<r1.x1<<"     X2 = "<<r1.x2 ;break ;
case 3 :r1 = quad_sol_Complex_numbers(a,b,c) ;cout<<"X1 = "<<r1.x1<<"     X2 = "<<r1.x2 <<"i";break ;
default: cout<<"wrong answer "; break;

}
cout<<"\n again ?(y/n)";
cin>>ch ;
}
  return 0;
}
