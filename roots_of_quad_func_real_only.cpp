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

int main()
{
char ch  ;
while(ch!='n'){

float a,b,c ;
roots r1 ;
cout<<"enter a , b and c ";
cin>>a>>b>>c ;
r1 = quad_sol_real_only(a,b,c) ;
cout<<"\n X1 = "<<r1.x1<<" X2 = "<<r1.x2;
cout<<"\n again ?(y/n) ";
cin>>ch ;
}
  return 0;
}
