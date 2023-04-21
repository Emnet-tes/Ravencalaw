//A program that allows bank transactions of up to 100 users and managment.
#include <iostream>
#include <cstdlib>
#include<cstring>
#include<iomanip>
#include <string>
#include<cmath>

using namespace std;
int main()
{

//this whole code is inside this gaint while loop which keeps it from terminating and losing data until the boss decides to end it all.

  string data [100][5];
  int numberOfacc =0;
  int short logInFormat; // this variable stores the choice of the user.
  int iC =1;
  data [0][0] = {"NAME"};
  data [0][1] ={"FATHER NAME"};
  data [0][2] ={"ACCOUNT NUMBER"};
  data [0][3] ={"PIN NUMBER"};
  data [0][4] ={"BALANCE"};


//front page for prompting the user to pick a log in format.
a:

cout <<"\t\t\t\t_____WELCOME_____\n"<<endl;
cout<<"Please choose a log-in format."<<endl;
cout<<"\t1) Log-in in to an existing account."<<endl;
cout<<"\t2) Creat a new accout (Transaction 'o' or 'O')."<<endl;
cout<<"\t3) I am the manager."<<endl;

cin>>logInFormat;

    if (logInFormat < 1 || logInFormat > 3) // if the user entered the wrong input.
         {
            cout<<"You have entered a wrong character please try again."<<endl;
            goto a;
         }

   if (logInFormat == 1)
   {
      string lname;
      int unsigned pin1;
     int unsigned account_num;
      int j =0; //searching variable
h:
      cout<<"Enter your name: ";
      cin>>lname;
      cout<<"\nEnter your account number: ";
      cin>>account_num;
      string tempAcc;
      tempAcc = to_string(account_num);

         ++j;
         if (tempAcc == data[j][2])
         {
            cout<<"Account found!"<<endl;
g:            cout<<"Enter the PIN: ";
            cin>>pin1;
            string tempPin;
            tempPin = to_string(pin1);


            if(tempPin == data[j][3])
            {
b:
               cout<<"Welcome "<<data[j][0]<<" "<<data[j][1]<<endl;
               cout<<"You have successfully entered your account"<<endl;

               cout<<"\nWhich transaction do you want to make."<<endl;
                    cout <<"1.Balance inquiry(B)\n";
                    cout <<"2.Deposit(D)\n";
                    cout <<"3.Withdrawal(W)\n";
                    cout <<"4.Close account(C)\n";
                    cout <<"\nEnter the charcters in bracket to choose trasaction type: ";
                    char type;
                    cin >>type;

               if(type == 'b' || type == 'B')
                    {
                     double display = stoi(data[j][4]);
                     display +=0.001;
                     double tdisplay;
                     tdisplay = round(display*100.0)/100.0;

                     cout<<"Your current balance is: "<< display<<" Birr"<<endl;
                     cout<<"Thank you for choosing our bank.\n";
 d:                  cout<<"\nIf you want to return to the front page enter [E/e]\n";
                     cout<<"If you want to return to the previous page enter [P/p]\n";

                     char finish;
                     cin>>finish;

                     if (finish == 'E' || finish == 'e')
                     {
                        goto a;
                     }
                     else if(finish == 'P' || finish == 'p')
                     {
                        goto b;

                     }
                     else
                     {
                        cout<<"you have entered the wrong character please tyr again";
                        goto d;
                     }

                    }
               else if ( type == 'd' || type == 'D')
                  {
                     cout<<"Enter the amout you want to deposite: ";
                     int unsigned depo;
                     cin>>depo;

                     double temp = stoi(data [j][4]);
                     temp += depo;
                     data [j][4] = to_string(temp);
                     temp+=0.0001;
                     double ttemp;
                     ttemp = round (temp*100.0)/100.0;

                     cout<<"Your account has been recharged!"<<endl;
                     cout<<"\nYour new amount is "<<ttemp<<" Birr"<<endl;

                     cout<<"Thank you for choosing our bank.\n";
e:                     cout<<"\nIf you want to return to the front page enter [E/e]\n";
                     cout<<"If you want to return to the previous page enter [P/p]\n";

                     char finish;
                     cin>>finish;

                     if (finish == 'E' || finish == 'e')
                     {
                        goto a;
                     }
                     else if(finish == 'P' || finish == 'p')
                     {
                        goto b;

                     }
                     else
                     {
                        cout<<"you have entered the wrong character please try again";
                        goto e;
                     }
                  }
               else if ( type == 'w' || type == 'W')
                  {
                     cout<<"Enter the amout you want to withdraw: ";
                     int unsigned with;
                     cin>>with;

                     double temp = stoi(data [j][4]);
                     temp -= with;
                     data [j][4] = to_string(temp);
                     temp +=0.0001;
                     double ttemp;
                     ttemp= round(temp*100.0)/100.0;

                     cout<<"Your account has been debited!"<<endl;
                     cout<<"\nYour new amount is "<<ttemp<<" Birr"<<endl;

                     cout<<"Thank you for choosing our bank.\n";
 f:                  cout<<"\nIf you want to return to the front page enter [E/e]\n";
                     cout<<"If you want to return to the previous page enter [P/p]\n";

                     char finish;
                     cin>>finish;


                     if (finish == 'E' || finish == 'e')
                     {
                        goto a;
                     }
                     else if(finish == 'P' || finish == 'p')
                     {
                        goto b;

                     }
                     else
                     {
                        cout<<"you have entered the wrong character please tyr again";
                        goto f;
                     }
                  }
               else if ( type == 'c' || type == 'C')
                  {
                     cout<<"Are you sure you want to close this account"<<endl;
                     cout<<"This will cause in permanent loss of data!"<<endl;
                     cout<<"Enter [y/Y] to confirm: ";
                     char del;

                     while (del != 'y' && del != 'Y')
                     {
                        cout<<"you have entered the wrong character operation has been aborted";
                        goto b;
                     }

                     if (del == 'y' || del == 'Y')
                     {
                        for (int i = j;i<= numberOfacc; ++i)
                        {
                           for (int k =0; k<=4; ++k)
                           {
                              data[i][k] = data[i+1][k];
                           }
                        }

                        cout<<"You have successfully deleted your account!"<<endl;
                        cout<<"If you want to creat a new one enter [n/N] ";
                        char reop;
                        cin>>reop;

                        while (reop != 'n' || reop != 'N')
                           {
                            cout<<"you have entered the wrong character. ";
                            goto a;

                           }
                        if (reop == 'n' || reop == 'N')
                        {
                           goto c;

                        }

                     }

                  }
                else
                {
                     cout<<"you have entered the wrong character please tyr again";
                     goto b;
                }
            }
            else
            {
               cout<<"You have entered the wrong PIN!"<<endl;
               cout<<"if you want try again enter [t/T]: ";
               char again;
               cin>>again;

                     while (again != 'T' && again != 't')
                     {
                        cout<<"you have entered the wrong character";
                        goto a;
                     }

                     if (again == 'T' || again == 't')
                     {
                        goto g;
                     }

            }
         }

         else
         {
            cout<<"Account has not been found!"<<endl;
            cout<<"Please try again.";
            goto h;
         }



    goto a;
   }

   else if (logInFormat == 2)
   {
c:

        string name,fname;
        int unsigned pin;


        cout<<"Enter your name: ";
        cin>>name;
        cin.ignore();
        data[iC][0] = name;

        cout<<"Enter your fathers name: ";
        cin>>fname;
        cin.ignore();
        data[iC][1] = fname;

         int account_no = 100100 + numberOfacc;
         cout<<"Your account number is: "<<account_no<<endl;
         cout<<"Enter a PIN for your account: ";
         cin>>pin;
         data[iC][2] =to_string(account_no);
         data[iC][3] =to_string(pin);
i:
         double amount;
         cout<<"Enter an initial deposite: ";
         cin>>amount;

          if (amount <= 25.0)
             {
               char token;
               cout <<"your intial deposit is less than than the minimum amount allowed\n to start again enter Y: ";
               cin >>token;

               while (token != 'y' || token != 'Y')
               {
                  cout<<"You have entered the wrong character operation aborted";
                  goto a;
               }
                if(token=='y'||token=='Y')
                      {
                         goto i;
                       }

             }


            amount += 0.0001;
            double tamount;
            tamount = round(amount*100.0)/100.0;
            cout<<"\nYour account has been charged"<<endl;
            cout<<"Your new balance is: "<< tamount <<" Birr."<<endl;
            cout<<"\nBe sure to remember your account number "<<data[iC][2]<<endl;
            cout<<"And your pin "<<data[iC][3];
            data[iC][4] = to_string(tamount);
            numberOfacc += 1;
            iC++;
           goto a;
   }

   else if (logInFormat == 3)
   {
      string spin;
 y:
      cout <<"enter special pin to inter the transaction S: ";
      cin >>spin;

      if(spin=="BEEEEE")
         {
 x:
            cout<<"\t\t\t_______WELCOME BOSS!! the bank is now open.________";
            char token;
            cout <<"\n\nchoose the transaction type from the menu below\n";
            cout <<"1.compute interest(I)\n";
            cout <<"2.print all accounts and amount(P)\n";
            cout <<"3.Close all accounts (E)\n";
            cin>>token;

           if (token == 'i' || token == 'I')
           {

             double iRate;
             int time;

               cout<<"Enter the interest rate in fraction: ";
               cin>>iRate;
               cout<<"\nEnter the time in a year format: ";
               cin>>time;


            for(int i = 1; i<= numberOfacc; ++i)
            {
                int temp = stoi( data [i][4]);
               cout<<data[i][2]<<" Has interest of "<<(temp* iRate*time)/100.0<<" birr per year."<<endl;
            }
           }

         else if (token == 'p' || token =='P')
           {
            for(int i= 0; i=0;++i)
            {
               for(int j=0; j<=4; ++j)
               {
                  cout<<data[i][j]<<setw(4)<<" ";
               }
               cout<<endl;
            }

            for (int i=1; i<=numberOfacc; ++i)
            {
               for (int j= 0; j<=4; ++j)
               {
                  cout<<data[i][j]<<setw(10)<<" ";
               }
               cout<<endl;
            }

           }
          else if (token == 'E' || token =='e')
          {
            cout<<"Are you sure you want to close the bank!!\n";
            cout<<"ALL DATA WILL BE DELETED!"<<endl;
            cout<<"Enter [y/Y] to confirm: ";
            char gbye;

            if (gbye == 'y' || gbye == 'Y')
            {
               goto z;

            }
            else
            {
               cout<<"Wrong input operation aborted.";
               goto y;
            }

          }

          else
          {
            cout<<"Wrong input try again.";
            goto x;
          }

   }
   else
   {
      cout<<"THAT IS THE WRONG PIN!\n";
      goto y;
   }
  goto a;
}

z:

return 0;
}
