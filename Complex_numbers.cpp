#include <iostream>

using namespace std;
class comp {
private:
    float real , imaginery ;
    char op ,ch ;
public :
    comp(){ real = 0 ; imaginery = 0; }
    void putdata(){
    cout<<"\n enter the complex number in this form(x+iy) and if y is negative please type(x+-yi)";

    cin>>real>>op>>imaginery>>ch ;

    }
    void showdata(){
    cout<<real<<"+"<<imaginery<<"i";

    }
    void operations(comp cc1 ,comp cc2  ){
    char oper ;
    cout<<"\n enter the operator " ;
    cin>>oper ;
    switch(oper){
    case '+' : real = cc1.real +cc2.real ; imaginery = cc1.imaginery + cc2.imaginery ;break;
    case '-' :  real = cc1.real -cc2.real ; imaginery = cc1.imaginery - cc2.imaginery ;break;
    case '*' : real =( cc1.real *cc2.real )+( cc1.imaginery *cc2.imaginery*(-1 )) ;imaginery = (cc1.real *cc2.imaginery +cc2.real *cc1.imaginery );break;
    case '/' : real = ((cc1.real*cc2.real)-(cc1.imaginery*cc2.imaginery*(-1)))/((cc2.real *cc2.real)-(cc2.imaginery*cc2.imaginery*(-1))) ; 
    imaginery = ((cc1.real*cc2.imaginery *(-1))+(cc1.imaginery *cc2.real ))/((cc2.real*cc2.real )-(cc2.imaginery *cc2.imaginery *(-1))) ;break ;

    cout<<real<<"+"<<imaginery<<"i";


    }




    }





};





int main()
{
char ch ; 
comp c1,c2,c3 ;

do{

c1.putdata();
c2.putdata();
c3.operations(c1,c2 );
c3.showdata();

 
cin>>ch ; 
}while(ch != 'n') ; 

    return 0;
}
