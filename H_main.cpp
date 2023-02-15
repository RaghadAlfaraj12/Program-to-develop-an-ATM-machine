#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include "H_lab.h"
using namespace std ;
int main(int argc, char** argv) 
{
      // variable to read the user option
        int option;
        // dynamic array used by functions 
       	AccountDetails* AccountsArray;
        AccountsArray= new AccountDetails[arrSize]; // this is a dynamic array
       
	do {	    
	
	
	cout<<"**************** Select an operation **************** "<<endl;
    cout<<"Press 1 to Add Account "<<endl;
	cout<<"Press 2 to Deposit an account "<<endl;
	cout<<"Press 3 to Withdraw an account "<<endl;
	cout<<"Press 4 to Show Informations of All Accounts "<<endl;
	cout<<"Press 5 to Search for Account and Print its Informations "<<endl;
	cout<<"Press 6 to rotate array of Accounts by 3 "<<endl;
	cout<<"Press 7 to Update an Accounts "<<endl;
	cout<<"Press 8 to Sort Accounts by balance  "<<endl;
	cout<<"Press 9 to Delete Account  "<<endl;
	cout<<"Press 0 to exit "<<endl;
	cin>>option; 
   // in the followinf part we read the number of lines in the file to know how many accounts stored and store them in the array 
	int AccountsNumber = 0;
		 string Line;
           	ifstream in("Account details.text");
           	    // every time a line found in the file  increment the accounts number by one 
                 while ( getline(in, Line) )
                    { 
	                  AccountsNumber++;
	                   }
	                
		switch(option)
		{   
			
			case 1: 
			// the read file will fill the array fromthe file to the AccountArray  
			    readFile(AccountsArray,AccountsNumber);
			    // give this array that filled form the file to the Add function 
				Add(AccountsArray,AccountsNumber);
				// after adding new account in the array rewrite the array again to the file 
                WriteFile(AccountsArray,AccountsNumber);	
	            break;
           case 2:
                readFile(AccountsArray,AccountsNumber);
	     		Deposit(AccountsArray,AccountsNumber);
	     		WriteFile(AccountsArray,AccountsNumber);
	     	
	     		break;
	     	case 3:
	     		readFile(AccountsArray,AccountsNumber);
	     		Withdraw(AccountsArray,AccountsNumber);
	     		WriteFile(AccountsArray,AccountsNumber);
			   
	     		break;
	     	case 4:
	     		readFile(AccountsArray,AccountsNumber);
				DisplayArray(AccountsArray,AccountsNumber);
			    break;
			case 5:
			    readFile(AccountsArray,AccountsNumber);
				search(AccountsArray,AccountsNumber);
			    break;
			case 6:
				readFile(AccountsArray,AccountsNumber );
				RotateArray(AccountsArray,AccountsNumber);
				break;
			case 7:
				readFile(AccountsArray,AccountsNumber );
				Update(AccountsArray,AccountsNumber );
				WriteFile(AccountsArray,AccountsNumber );
				
			
				break;
			case 8:
				readFile(AccountsArray,AccountsNumber );
				sort(AccountsArray,AccountsNumber );
				WriteFile(AccountsArray,AccountsNumber );
				break;
			case 9:
				readFile(AccountsArray,AccountsNumber );
				Delete(AccountsArray,AccountsNumber );
				WriteFile(AccountsArray,AccountsNumber );
			
				break;
			default:
	     		cout << "invaled choice try again ....."<<endl;
	     	
		}//switch
		}while (option!=0);
		cout<<"_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*__*_*_*_*_*_*_*_*_*_*_"<<endl;
	return 0;
}