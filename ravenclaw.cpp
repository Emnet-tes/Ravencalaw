#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
int option,decimal,num,i=0,base,remainder,digit,converted[100],j;
long octal [100];
char hexadecimalNumber[100];
bool isBinary=true,isOctal=true,isDecimal=true,isHex=true;

cout <<"\t\t\t\t_____welcome_____\n";
cout <<"select an option \n";
cout << "1. Convert decimal to any base\n";
cout << "2.convert binary to decimal\n";
cout << "Enter your choice: ";
cin  >> option;

switch(option){

case 1:
  cout <<"enter number: ";
  cin >>num;
 if(isDecimal==true){
    cout <<"enter the base you want to change into: ";
    cin >>base;
    int i = 0,j;
   if(base==16){
            while(num>0){
             int remainder = num % 16;
        if (remainder < 10)
            hexadecimalNumber[i] = remainder + 48;
        else
            hexadecimalNumber[i] = remainder + 55;
        num = num/ 16;
        i++;
            }
        for (int j = i - 1; j >= 0; j--)
    cout<<hexadecimalNumber[j];
    }
    else{while (num > 0) {
        converted[i] = num % base;
        num/= base;
        i++;
    }
        for (int j = i - 1; j >= 0; j--)
        cout << converted[j];
    }
          }
   else{
    cout<<"invalid input";
}
   break;

case 2:
  cout <<"enter number: ";
  cin >>num;
 while (num != 0) {
        remainder = num % 10;
        num /= 10;
        decimal += remainder * pow(2, i);
        i++;}
        cout <<decimal;
    break;
default :
    cout <<"invalid input";

}}
