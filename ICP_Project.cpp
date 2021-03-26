#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

char choice;
int secret_pin;
int person;
int due[10]={0,0,0,0,0,0,0,0,0,0};
long long mob_num[10]={9713716557,7357974302,9425794225,9977107105,7089973646,7015935333,8295243455,7894561230,110022334447,9876543210};
long long balance[10]={50000,100500,5000,55000,1000,789,1522,252,19822,17000};
string name[10]={"Ankit Sharma","Anshul Ghanghoria","Ankur Goud","Anshul Singh Tomar","Ansh Saxena","Rohan Shukla","Maruf Qureshi","Aman Dubey","Aditya Nema","Gaurav Tiwari"};
int pin[10]={2103,1835,7892,1937,4468,5586,6456,9982,8511,7081};

int intro();
void end();
void withdrawal(int a);
void account_balance(int a);
void deposit_amount(int a);
void transfer_amount(int a);
void account_details(int a);
void change_pin(int a);

int main(){

    A: int process;
    process = intro();
    if(process<1 || process>7){
        cout<<"Please Choose From The Given Choices."<<endl;
        system("pause");
        system("cls");
        goto A;
    }else if(process==7){
        goto E;
    }else{
        int wrong=0;
        B: int count = 0;
        cout<<"Please Enter Your Secret PIN: ";
        cin>>secret_pin;
        system("cls");
        for(int i=0;i<10;i++){
            if(secret_pin == pin[i]){
                cout<<"Account Holder Name: "<<name[i]<<endl;
                person = i;
                system("pause");
                cout<<endl;
                break;
            }else{
                count++;
            }
        }
        if(count==10){
            if(wrong<2){
                cout<<"You Enter an invalid PIN."<<endl;
                cout<<"Please Try Again."<<endl;
                system("pause");
                system("cls");
                wrong++;
                goto B;
            }else{
                cout<<"You Enter an Invalid PIN 3 Times."<<endl;
                cout<<"Please Try Again After 8 Hours."<<endl;
                system("pause");
                system("cls");
                goto E;
            }
        }
        switch(process){
            case 1: withdrawal(person);
                    break;
            case 2: account_balance(person);
                    break;
            case 3: deposit_amount(person);
                    break;
            case 4: transfer_amount(person);
                    break;
            case 5: account_details(person);
                    break;
            case 6: change_pin(person);
                    break;
        }

        if(choice == 'Y'){
            system("cls");
            goto A;
        }else if(choice == 'N'){
            system("cls");
        }else{
            system("cls");
            cout<<"Please Choose From The Given Choices."<<endl;
            end();
        }
    }
    

    E:cout<<"--------------------Thank You!!-----------------"<<endl<<endl;

return 0;
}

int intro(){
    int x;
    cout<<"----------------------------------------------------WELCOME TO ATM----------------------------------------------------"<<endl;
    cout<<"--------------------------------------------Please Choose What You Wanna Do:--------------------------------------------"<<endl<<endl;
    cout<<"WITHDRAWAL........... 1"<<endl;
    cout<<"ACCOUNT BALANCE...... 2"<<endl;
    cout<<"DEPOSIT AMOUNT....... 3"<<endl;
    cout<<"TRANSFER AMOUNT...... 4"<<endl;
    cout<<"ACCOUNT DETAILS...... 5"<<endl;
    cout<<"CHANGE PIN........... 6"<<endl;
    cout<<"QUIT................. 7"<<endl<<endl;
    cout<<"Your Selection: ";
    cin>>x;
    system("cls");
return x;
}

void withdrawal(int a){
    D:int type, amount;
    cout<<"From Savings......1"<<endl;
    cout<<"From Current......2"<<endl;
    cin>>type;
    system("cls");
    switch(type){
        case 1: cout<<"Type The Amount You Wanna Withdraw: Rs.";
                cin>>amount;
                if(amount <= balance[a]){
                    cout<<"Please Collect Your Cash."<<endl;
                    balance[a] -= amount;
                    cout<<"Balance Remaining In Your Account: Rs."<<balance[a]<<endl<<endl;
                    break;
                }else{
                    cout<<"Balance Insufficient."<<endl;
                    cout<<"Balance In Your Account: Rs."<<balance[a]<<endl<<endl;
                    break;
                }

        case 2: cout<<"Type The Amount You Wanna Withdraw (Less Than The Limit:5000): Rs.";
                cin>>amount;
                if(amount<=5000){
                    due[a] += amount;
                }
                if(due[a]<=5000 && amount<=5000){
                    cout<<"Please Collect Your Cash."<<endl<<endl;
                    break;
                }else{
                    cout<<"You Exceeded The Limit."<<endl<<endl;
                    break;
                }

        default:cout<<"Please Choose From The Given Choices."<<endl;
                system("pause");
                system("cls");
                goto D;
    }
    end();
}

void account_balance(int a){
    cout<<"Your Account Balance is: Rs."<<balance[a]<<endl<<endl;
    end();
}

void deposit_amount(int a){
    int deposit;
    cout<<"Type The Amount You Wanna Deposit: Rs.";
    cin>>deposit;
    cout<<endl<<"The Amount is Successfully Deposited."<<endl;
    balance[a] += deposit;
    cout<<"Your Account Balance Now: Rs."<<balance[a]<<endl<<endl;
    end();
}

void transfer_amount(int a){
    C:string s1,s2,transfer;
    int transfer_amt,yes,transfer_person;
    cout<<"Enter The Full Name Of The Account Holder To Whom You Wanna Transfer Amount: ";
    cin>>s1>>s2;
    transfer = s1 + ' ' + s2;
    for(int j=0;j<10;j++){
        yes=0;
        if(transfer == name[j]){
            transfer_person = j;
            yes = 1;
            break;
        }
    }
    if(yes==0){
        cout<<"Please Enter Correct Account Holder Name."<<endl;
        system("pause");
        system("cls");
        goto C;
    }
    cout<<"Type The Amount You Wanna Transfer: Rs.";
    cin>>transfer_amt;
    cout<<endl;
    if(transfer_amt <= balance[a]){
        cout<<"Transaction Sucessful!!"<<endl;
        balance[a] -= transfer_amt;
        cout<<"Balance Remaining In Your Account: Rs."<<balance[a]<<endl<<endl;
        balance[transfer_person] += transfer_amt;
    }else{
        cout<<"Transaction Unsucessful...Insufficient Balance."<<endl;
        cout<<"Balance In Your Account: Rs."<<balance[a]<<endl<<endl;
    }
    end();
}

void account_details(int a){
    cout<<"Account Holder ---"<<endl<<endl;
    cout<<"Name: "<<name[a]<<endl;
    cout<<"Mobile Number: "<<mob_num[a]<<endl;
    cout<<"Account Balance: Rs."<<balance[a]<<endl<<endl;
    end();
}

void change_pin(int a){
    F:int p1,p2,p;
    cout<<"Enter Current PIN: ";
    cin>>p;
    if(p==pin[a]){
        cout<<"Enter New PIN: ";
        cin>>p1;
        cout<<"Enter New PIN Again: ";
        cin>>p2;
        cout<<endl;
        if(p1==p2){
            pin[a] = p1;
            cout<<"PIN Changed Successfully!!"<<endl<<endl;
            system("pause");
            cout<<endl;
            end();
        }else{
            cout<<"New PIN Does Not Match..."<<endl;
            cout<<"Try Again"<<endl<<endl;
            system("pause");
            system("cls");
            goto F;
        }
    }else{
        char decision;
        cout<<"PIN Entered is Wrong."<<endl<<endl;
        cout<<"Wanna Try Again?...(Y for Yes & N for No): ";
        cin>>decision;
        if(decision=='Y'){
            system("cls");
            goto F;
        }else{
            end();
        }
    }
}

void end(){
    cout<<"Do You Wanna Do More Transactions...(Y for Yes & N for No): ";
    cin>>choice;
}
