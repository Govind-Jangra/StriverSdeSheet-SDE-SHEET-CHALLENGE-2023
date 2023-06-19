// https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/

#include<bits/stdc++.h>

using namespace std;



int solve(string s) {
   int i=0,j=s.size()-1;
   int trim=j;
   int ans=0;
   while(i<j){
       if(s[i]==s[j]){ i++;j--;}
       else{
           i=0;
           j=--trim;
           ans++;
       }
   }
   return ans;
}
