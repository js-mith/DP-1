#include<iostream>
#include<limits.h>
using namespace std;

int minstep(int n){
    if(n<=1){
        return 0;
    }
    // recursive call

    int x = minstep(n-1);

    int y = INT_MAX , z = INT_MAX;

    if(n % 2 == 0){
        y = minstep(n/2);
    }

    if( n % 3 == 0){
        z = minstep(n/3);
    }

    //calculate the final o/p

    int ans = min(x , min(y,z)) +1;

    return ans;
}

// memoziation

int minstephelper(int n , int *ans){
    if(n <= 1){
        return 0;
    }

    if(ans[n] != -1){
        return ans[n];
    }

      int x = minstephelper(n-1 , ans);

    int y = INT_MAX , z = INT_MAX;

    if(n % 2 == 0){
        y = minstephelper(n/2 , ans);
    }

    if( n % 3 == 0){
        z = minstephelper(n/3 , ans );
    }

    //calculate the final o/p

    int output = min(x , min(y,z)) +1;

    ans[n] = output;

    return output;
}

int minstep2(int n){
    int *ans = new int[n+1];

    for(int i = 0; i< n;  i++){
        ans[i] = -1;
    }

    return minstephelper(n , ans);
}
// dyamin prog...

int minstep3(int n){
    	 int a[n+1];
     
    a[1]=0; a[2]=a[3]=1;
   int b,c;
    for(int i=4 ;i<n+1;i++)
    {   
        b=c=n;
     
       if(i%2==0) b=a[i/2];
        if(i%3==0) c=a[i/3];
     
      a[i]=1+ min(a[i-1] ,min(b,c));
    }
return a[n];
}

int main() {
     int n;
     cin >> n;

     cout << minstep3(n) << endl;
     return 0;
}