#include<iostream>
using namespace std;
#include<cmath>

int minCount(int n)
{
	//Write your code here
	if ( sqrt (n) -floor(sqrt(n))==0)  return 1;
    
      int arr[n+1];
    arr[0]=0;
    arr[1]=1;
    arr[2]=2;
    arr[3]=3;
    
    for(int i=4 ;i<=n ;i++)
    {
      	  
        arr[i] = i; 
  
        for (int x = 1; x <= ceil(sqrt(i)); x++) { 
            int temp = x * x; 
            if (temp > i) 
                break; 
            else
                arr[i] = min(arr[i], 1 + arr[i - temp]); 
           }
    }
    return arr[n];
}

int main() {
    int n;
    cin >>n;

    cout << minCount(n) << endl;
     
     return 0;
}