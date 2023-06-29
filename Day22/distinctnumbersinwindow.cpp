// https://www.interviewbit.com/problems/distinct-numbers-in-window/

vector<int> Solution::dNums(vector<int> &A, int B) {
     vector <int>ans;
         unordered_map<int,int>mp;
         int i=0;int j=0; 
         while(j<n){
             mp[arr[j]]++;
             
             if(j-i+1<k) j++;
             
             else if(j-i+1==k){
                 ans.push_back(mp.size());
                 mp[arr[i]]--;
                 if(mp[arr[i]]==0) mp.erase(arr[i]);
                 i++;j++;
             }
             
         }
         return ans;
}
