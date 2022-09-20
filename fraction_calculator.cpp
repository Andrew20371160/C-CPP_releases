#include <iostream>
using namespace std;
class fraction{
private:
    int num ,den ;
    char op ;
public:
    fraction(){
    num = 0 ; den = 1 ;}
    fraction(int n , int d){
        num = n ; den = d ;
    }
    void putdata(){
        char ch ;
    cout<<"enter the fraction "<<endl ;
    cin>>num>>ch>>den;
    }
    void showdata(){
    cout<<num<<"/"<<den<<endl;

    }


    void putop(fraction ff1 ,fraction ff2){
    cout<<" put the operator ";
    cin>>op ;



switch(op){
    case '+':  num = (ff1.num*ff2.den +ff1.den *ff2.num) ;
    den = (ff1.den * ff2.den); break ;
    case '-' : num = (ff1.num*ff2.den -ff1.den *ff2.num) ; den = (ff1.den * ff2.den); break ;
    case'*' : num = (ff1.num *ff2.num ); den = ff1.den *ff2.den ; break ;
    case '/' : num = ff1.num *ff2.den ; den = ff1.den *ff2.num ; break ;
    cout<<num<<"/" <<den ;
    default : cout<<"wrong operator "; break ;
    }

}




};
int main()
{

char ch ;    
do{
fraction f1 ,f2 ,f3 , f4 ;
f1.putdata();
f2.putdata();
f3.putop(f1,f2);
f3.showdata();
cout<<endl<<"again?(y/n)";
cin>>ch;
}while(ch!='n');
    return 0;
}
