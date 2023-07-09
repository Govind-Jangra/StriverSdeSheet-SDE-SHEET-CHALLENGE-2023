// https://practice.geeksforgeeks.org/problems/power-set4302/1#




  void solve(string s,string t,vector<string> &ans){
			if(s.size()==0){
					ans.push_back(t);
					return;
			}
			char c=s[0];
			solve(s.substr(1),t,ans);
			solve(s.substr(1),t+c,ans);
		}
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    
		  //  sort(s.begin(),s.end());
			vector<string> ans;
			if(s.size()==1){
			    ans.push_back(s);
			    return ans;
			}
			solve(s,"",ans);
			sort(ans.begin(),ans.end());
			ans.erase(ans.begin());
			return ans;
		}
};