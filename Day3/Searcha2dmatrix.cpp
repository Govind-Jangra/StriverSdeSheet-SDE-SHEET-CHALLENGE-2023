// https://leetcode.com/problems/search-a-2d-matrix/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int low = 0;
        int high = n-1;
        while(low < high){
            int mid = low + (high - low)/2;
            if(matrix[mid][m-1] < target){
                low = mid+1;
            }
            else if(matrix[mid][m-1] == target) return 1;
            else{
                high = mid;
            }
        }
        int row= matrix[low][m-1] >=target ? low : 0;
        cout<<row;
        low=0,high=m-1;
         while (low <= high) {
    int mid = low + (high - low) / 2;

    if (matrix[row][mid] == target)
      return 1;

    if (matrix[row][mid] < target)
      low = mid + 1;

    else
      high = mid - 1;
  }


        return 0;

    }
};