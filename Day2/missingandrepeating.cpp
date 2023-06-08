// https://www.codingninjas.com/codestudio/problems/873366?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=2
#include<bits/stdc++.h>
using namespace std;

pair<int,int> missingAndRepeating(vector<int> &a, int  n)
{
	// Write your code here 
	

    int Xor = 0;

  
    for (int i = 0; i < n; i++) {
        Xor = Xor ^ a[i];
        Xor = Xor ^ (i + 1);
    }

   
    int number = (Xor & ~(Xor - 1));


    int zero = 0;
    int one = 0;
    for (int i = 0; i < n; i++) {
     
        if ((a[i] & number) != 0) {
            one = one ^ a[i];
        }
        
        else {
            zero = zero ^ a[i];
        }
    }

    for (int i = 1; i <= n; i++) {
    
        if ((i & number) != 0) {
            one = one ^ i;
        }
     
        else {
            zero = zero ^ i;
        }
    }


    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == zero) cnt++;
    }

    if (cnt == 2) return {one, zero};
    return {zero, one};

	
}
