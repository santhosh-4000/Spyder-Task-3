//*No of  distinct colors are same as no of primes below n
//*because if we start from 2 all multiples of 2 can be 
//assined a single color and next prime is 3 which is co-prime 
// to 2 hence should be given another color
//*direct application of sieve of eratosthenes

#include<bits/stdc++.h>
using namespace std;

//find no> of primes using sieve of eratosthenes
int no_of_primes(int n){
	int count=0;
	vector<bool> prime(n+1,true);
	
	for(int i=2;i*i<=n;i++){
		if(prime[i]==true){
			for(int j=i*i;j<=n;j+=i){
				prime[j]=false;
			}
		}
	}
	
	for(int i=2;i<=n;i++){
		if(prime[i])
		count++;
	}
	return count;
}


int main(){
	int n;
	cin>>n;
	
	int s=no_of_primes(n);
	//result will be minimum sum of distinct values
	long result=s*(s+1)/2;
	
	cout<<result<<endl;
}
