#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
using namespace std;
struct AccountDetails
{
	int AccountNumber;
	double balance;
	int PIN;
	string Status;
};
void WriteFile(AccountDetails *A, int ArrayElements);
void readFile(AccountDetails *A , int ArrayElements);
void Add(AccountDetails *A,int &ArrayElements);
void DisplayArray(AccountDetails *A,int ArrayElements);
void search(AccountDetails *A,int ArrayElements);
void Deposit(AccountDetails *A,int  ArrayElements);
void Withdraw(AccountDetails *A,int  ArrayElements);
void RotateArray(AccountDetails *A,int  ArrayElements);
void Update(AccountDetails *A,int ArrayElements);
void sort(AccountDetails *A,int ArrayElements);
void Delete(AccountDetails *A,int &ArrayElements);