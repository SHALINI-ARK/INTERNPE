#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
srand(time(0));
cout<<"Welcome to Number Game.....!"<<endl;
cout<<"Guess a number between (1-100):"<<endl;
int number = rand()%100;
int c=0;
char ch;
ch=1;
int guess;
do
{
cout<<"Enter your guess :"<<endl;
cin>>guess;
c++;
if(guess==number)
{
cout<<"😍 Congratulations, You have correctly guessed the number correctly in "<<c<<" time."<<endl;
}
else if(guess>number)
{
cout<<"Your guess is higher than the number."<<endl;
cout<<"Try again...!"<<endl;
}
else
{
cout<<"Your guess is lower than the number."<<endl;
cout<<"Try again...!"<<endl;
}
}while(guess!=number);
return 0;
}
