//*we need to have an arr of size n from m with maximum possible minimum
//*first sort arr in decreasing order
//*Consider array of first n elements and copy to res array as first
//n elements have greatest minimum among all other combinations 
//*as we can combine two bricks to get a single brick of unit length
//combine greatest of remainig element in arr to least of res(res[n-1])
//*sort res in decreasing order
//*repeat this process m-n times
// res[n-1] will be result
//Greedy approach

#include<bits/stdc++.h>
using namespace std;

int main(){
	//take inputs
	 int n,m;
	 cin>>n>>m;
	 vector<long> a;
	 for(int i=0;i<m;i++){
	 	int temp;
	 	cin>>temp;
	 	a.push_back(temp);
	 }
	 
	 //sort a in decreasing order
	 sort(a.begin(),a.end(),greater<int>());
	 
	 //copy first n elements in a to res
	 vector<long>::iterator itr=a.begin();
	 vector<long> res(itr,itr+n);
	 
	 
	 for(int i=1;i<=m-n;i++){
	 	res[n-1]=res[n-1]+a[n-1+i];
	 	
	 	//modified insertion sort
	 	if(res[n-1]>res[n-2]){
	 		int temp=res[n-1];
	 		int j=n-2;
	 		while(j>=0&&res[j]<temp){
	 			res[j+1]=res[j];
	 			j--;
			 }res[j+1]=temp;
		 }
		 
	 }

	 cout<<res[n-1]<<endl;
}
