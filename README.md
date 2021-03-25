# ATM
ICP Project

Libraries included - iostream
                     cstdlib
                     string
                  
Global Variables - char choice
                   int secret_pin
                   int person
                   int pin[10]
                   int due[10]                                                            mob_num , name is static (that means they will not change)
                   long long mob_num[10]                                                  balance , pin , due is not static
                   long long balance[10]
                   string name[10]
                   
Functions - int intro();
            void end();
            void withdrawal(int a);
            void account_balance(int a);
            void deposit_amount(int a);
            void transfer_amount(int a);
            void account_details(int a);
            void change_pin(int a);
            
START - From main ---- 
        local variable - int process
        calling function intro();
        In intro - local variable - int x;
        In intro function the main menu will open....Where you have to choose one option from list.
        when you choose one option value will be return to main function by returning x (that contains your selected option number).
        the number return from the function x will store in int process.
        
        Then if condition comes - If process <1 OR (||) >7....then you have to choose again.... and the program will goto A (starting).
        if process = 7 .... then the program will goto E (Thankyou statement).
        else the program will continue...
        
        
        
            
            
                   
                   
