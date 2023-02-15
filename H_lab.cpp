#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//Maximum size of the array 
 int arrSize=10;
 // account information
struct AccountDetails{
	int AccountNumber;
	double balance;
	int PIN;
	string Status;
};

// function takes a dynamic array as parameter  ,and number of accounts stored currently in the array 
void WriteFile(AccountDetails *A, int ArrayElements)
// this function writes into file the Accounts info that stored in array 
{
   ofstream outfile;
   // open a file names account details 
    	outfile.open("Account details.text",ios::out);
    	// check if the file is not open
   if (!outfile.is_open())	{
   	cout<< "Cant Open File "<<endl;
   		}
   else 
   for (int i =0 ;i<ArrayElements;i++)
   { //take each acount and store the details in a line in the file 
    outfile <<A[i].AccountNumber << " ";
    outfile<<A[i].balance<< " ";
  	outfile<<A[i].PIN<< " ";
    outfile<<A[i].Status<< " ";
   	outfile<<endl;
   }
   outfile.close();
   cout << "**********************************************************************************************"<<endl;
}


void readFile(AccountDetails *A , int ArrayElements)
// this function read from file and fill the array again to edit the data and rewrite in file 
{
	ifstream infile ;
	infile.open("Account details.text");
	if (!infile.is_open()){
   		cout<< "Cant Open File "<<endl;	}
   	while (infile)
   	{ 
   		for(int i=0 ;i<ArrayElements;i++)
     	{ // take each value in the file and store it in the correct variable in the struct 
     	infile>>A [i].AccountNumber ;
     	// to ignore the space in the file 
     	infile.ignore(1);
   	    infile>>A [i].balance;
   	    infile.ignore(1);
   	    infile>>A [i].PIN;
   	    infile.ignore(1);
   	    // get line is used to read a string from the file and store in string data type 
   	    getline(infile,A[i].Status,' ');  
   	     infile.ignore(1);
	   }	
	} 	   
}
// function used to add a new account to the accounts array  the value ArrayElements contains number of account inside the array it passed by refernce because when we add new account we should increment it 
void Add(AccountDetails *A,int &ArrayElements) 
{  

	cout << " Please enter your Account number: (9 digits) ";	
	cin>>A[ArrayElements].AccountNumber;	
    cout << " Enter Balance: ";
	cin >>A[ArrayElements].balance;
    cout << " Enter PIN (4 digits): ";
	cin >>A[ArrayElements].PIN;
	A[ArrayElements].Status="Active";
	// increment the number of accounts by 1 after adding a new account 
	ArrayElements++;
}

// function read the data in the array ad display it on the screen
void DisplayArray(AccountDetails *A,int ArrayElements) 
{
	for( int i=0 ; i<ArrayElements; i ++)
	{	
		cout << "Account # :"<< i+1<<endl;
		cout <<"Account Number :  "<<A[i].AccountNumber <<endl;
		cout<<"Balance :"<< A[i].balance<<endl;
		cout<< "PIN :"<<A [i].PIN<<endl;
		cout<<"Status :"<< A[i].Status<<endl;
		cout << "**************************************************"<<endl;
	}//for

}
// function takes the account number from the user and search in the array to check if it is exist or not then display the details of theis account 
void search(AccountDetails *A,int ArrayElements)	{ 
	int number;
	cout<<"Please enter your Account number: (0-9)"<<endl;
	cin>>number;
	
   	bool Found =false;
   	// for each element in the array 
   	for(int i=0;i<ArrayElements;i++){
   		//check if the number entered by the user equals any of the account numbers in the array 
   		if (number==A [i].AccountNumber){
   			// change this boolean to true if the number matched any of the accounts 
   			Found=true;
   			cout<<" Account number    : "<< A[i].AccountNumber<<endl;
   		    cout<<" Account Balance : "<< A[i].balance<<endl;
   		    cout<<" PIN Code  : "<<  A[i].PIN<<endl;
   		    cout<<" Account Status : "<<  A[i].Status<<endl;
   		    }
			}
			
	   if (Found==false) {
	   	//if the boolean false means that there is no acount with this number 
	    	cout << "......... This Account Doesn't exist............"<< endl;	}
	    	
			cout << "**********************************************************************************************"<<endl;   }

		// ask for the amout the user wants to detuct from the balance  but ask the user to enter the account number first 		 	
void Deposit(AccountDetails *A,int  ArrayElements){
	int number;
	double Amount;
	cout<<"Please enter your Account number: (0-9)"<<endl;
	cin>>number;
	// search for account in accounts array
		bool Found =false;
   	for(int i=0;i<ArrayElements;i++){
   		// if the account found in the array the user should enter the amount of money 
   		if (number==A[i].AccountNumber){
   			Found=true;
   		
	        cout<<"Please enter your amount to deposite: "<<endl;
	        cin>>Amount;
	        // check after taking the amount from the balance  if it will be 0 or not ( if greater than 0 then detuct the amount 
			if((A [i].balance - Amount)>=0){
			
				A[i].balance -= Amount;
			    cout<<"the amount updated Successfully"<<endl;
			}
			 else
			{
				cout<<"the deposite amount is greater than your balance...please try again!!!"<<endl;
			}
			break;	
		}
		}
		
	   if (Found==false) {
	    	cout << "......... This Account Doesn't exist............"<< endl;	}
	
}
// ask for the amout the user wants to detuct from the balance  but ask the user to enter the account number first 

void Withdraw(AccountDetails *A,int  ArrayElements){
	int number;
	double Amount;
	cout<<"Please enter your Account number: (0-9)"<<endl;
	cin>>number;
	// search for account in accounts array
		bool Found =false;
		// for each account check it matches the number entered by user 
   	for(int i=0;i<ArrayElements;i++){
   		// if there is a match  then ask for the amount needs to be added 
   		if (number==A[i].AccountNumber){
   			Found=true;
   		
	        cout<<"Please enter your amount to deposite: "<<endl;
	        cin>>Amount;	// add the amount to the balance 
			A[i].balance += Amount;
			cout<<"the amount updated Successfully"<<endl;
			break;	
		}
		}
		
	   if (Found==false) {
	    	cout << "......... This Account Doesn't exist............"<< endl;	}
	
}

void RotateArray(AccountDetails *A,int  ArrayElements){
	int newPositionIndex;

	AccountDetails temp[arrSize];
	// rotate each element by 1 step
	for(int i=0;i<ArrayElements;i++)
	{
		newPositionIndex=i+3;// retoate index by 3
		if(newPositionIndex>=ArrayElements)
			newPositionIndex=newPositionIndex%ArrayElements;
		temp[newPositionIndex]=A[i];
	}

	// Print array after rotating
	cout<<" the result after rotating is: "<<endl;
	cout<<" Account number \t Balance \t PIN \t Status "<<endl;
    cout<<"***********************************************************"<<endl;
	for(int i=0;i<ArrayElements;i++)
	{
		
		cout<<temp [i].AccountNumber<<"\t"<<temp [i].balance<<"\t"<<temp [i].PIN<<"\t"<<temp [i].Status<<endl;
  }
	    cout<<"***********************************************************"<<endl;
}


void Update(AccountDetails *A,int ArrayElements)	{ 
   int number;
   // ask the user for the account number and search for it 
	cout<<"Please enter your Account number: (0-9)"<<endl;
	cin>>number;
	
   	bool Found =false;
   	for(int i=0;i<ArrayElements;i++){
   		// if the account number is found  then ask the user to enter  the update details 
   		if (number==A [i].AccountNumber){
   			Found=true;
   			cout<<" Enter The New Information.... ";
   			cout<<" Account number    : ";
   			cin>>A[i].AccountNumber;
   		    cout<<" Account Balance : ";
   		    cin>>A[i].balance;
   		    cout<<" PIN Code  : ";
   		    cin>>A[i].PIN;
   		    cout<<" Account Status : ";
   		    cin>>A[i].Status;
   		    }
			}
	   if (Found==false) {
	    	cout << "......... This Account Doesn't exist............"<< endl;	}
	    	
			cout << "****************************************"<<endl; 
}
				 	
		// sort the array based on the balance Ascending .		 	
void sort(AccountDetails *A,int ArrayElements)
{ // make a counter = to the number of accounts stored in the array
	int counter=ArrayElements;
	// make a variable of type account details to copy the sorted array to it 
	AccountDetails  temp;
	cout << "sorting in progress ................."<< endl;
	//nested loop  start from the end of the array  then 
	for (int j =counter-1 ;j>0 ;j--)   {
		// another loop starts from the begining 
	   for (int i =0 ; i <ArrayElements-1;i++) 	{
	   	// check if the balance of the current account greater than the next one  if yes  switch the Two accounts using a temprory array 
	    	if(A[i].balance >= A[i+1].balance)	{    
	      		temp=A[i];
	      		A[i]=A[i+1];
	      		A[i+1]=temp;	    		
			}	}	}	}
	// ask the user to enter the account number then search for it in the array to check if there is match  with one of the accounts then  the array will be shifted startinf from the position if the requested account		
void Delete(AccountDetails *A,int &ArrayElements)
	{ 
	   	int number;
	cout<<"Please enter your Account number: (0-9)"<<endl;
	cin>>number;
	
   	bool Found =false;
   	for(int i=0;i<ArrayElements;i++){
   		if (number==A [i].AccountNumber){
   			Found=true;
   			// shift the next account to be in the current position 
   			A[i] =A[i+1];
     				}
     				// decrement the size of array by 1  after deletion 
					 ArrayElements--;
					 cout<<"This Account is Successfuly deleted "<<endl;
   		    }
	   if (Found==false) {
	    	cout << "......... This Account Doesn't exist............"<< endl;	}
	    	
			cout << "**********************************************************************************************"<<endl; 
       			 	
	}