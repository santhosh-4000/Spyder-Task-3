//*we need to have an arr of size n from m with maximum possible minimum
//*first sort arr in decreasing order
//*Consider array of first n elements and copy to res array as first
//n elements have greatest minimum among all other combinations 
//*as we can combine two bricks to get a single brick of unit length
//combine greatest of remainig element in arr to least of res(res[n-1])
//*sort res in decreasing order
//*repeat this process m-n times
// res[n-1] will be result

#include<bits/stdc++.h>
  using namespace std;

 
//get least element on top of heap(root)
  void heapify (vector < long >&arr, int n, int i)
{
  
int least = i;
  
int l = 2 * i + 1;		//left child  
  int r = 2 * i + 2;		//right child 
  
    //if left child is less than root
    if (l < n && arr[l] < arr[least])
    
least = l;
  
    //if right child is less than root and left child 
    if (r < n && arr[r] < arr[least])
    
least = r;
  
    //if root is not least then swap with least 
    //and recursively heapify left and right subheaps
    if (least != i)
    {
      
swap (arr[i], arr[least]);
      
 
heapify (arr, n, least);
    
}

}


 
int
main ()
{
  
    //take inputs
  int n, m;
  
cin >> n >> m;
  
vector < long >a;
  
for (int i = 0; i < m; i++)
    {
      
int temp;
      
cin >> temp;
      
a.push_back (temp);
    
} 
 
    //sort a in decreasing order
  sort (a.begin (), a.end (), greater < int >());
  
 
    //copy first n elements in a to res
  vector < long >::iterator itr = a.begin ();
  
vector < long >res (itr, itr + n);
  
 
    //make min heap from res
    for (int i = (n / 2 - 1); i >= 0; i--)
    
heapify (res, n, i);
  
 
 
for (int i = 1; i <= m - n; i++)
    {
      
res[0] = res[0] + a[n - 1 + i];
      
heapify (res, n, 0);
    
} 
 

    
cout << res[0] << endl;

}

