#include<bits/stdc++.h>
using namespace std;

//this function is used to calculate no of times
//sum of digits is calculated to get a single digit
//recursive
int no_Of_Sums(int num,int count){
	//base case
	if(num<10)
	return count;
	
	//calculate sum of digits and increment count
	int sum=0;
	while(num){
		sum=sum+(num%10);
		num/=10;
	}count++;
	
	//take sum and count as arguments
	return no_Of_Sums(sum,count);
}

int main(){
	
	//as n can be as large as 10^100000 it can be stored 
	//in string of max length 100000 
	string n;
	cin>>n;
	
	//if size of n is 1 then no summation is needed
	if(n.size()==1){
		cout<<"0"<<endl;
	}
	
	//string summation is calculated which can be stored in 
	//int as its size don't exceed 900000
	else{
	int sum=0;
	for(int i=0;i<n.size();i++){
		sum+=(n[i]-'0');
	}
	
	//pass sum,1 as arguments to no_Of_Sums as we calculated
	//sum 1 time already
	cout<<no_Of_Sums(sum,1)<<endl;
}

}
