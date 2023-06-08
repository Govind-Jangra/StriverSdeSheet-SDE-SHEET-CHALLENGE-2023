//https://www.codingninjas.com/codestudio/problems/count-inversions_615
#include <bits/stdc++.h> 
  long long merge(long long arr[], long long l, long long m, long long r)
    {
         // Your code here
         long long inv=0;
         long long n1=m-l+1;
         long long n2=r-m;
         long long a1[n1];
         long long a2[n2];
         for(long long i=0;i<n1;i++){
             a1[i]=arr[l+i];
         }
         for(long long i=0;i<n2;i++){
             a2[i]=arr[m+i+1];
         }
         long long i=0,j=0,k=l;
         
         while(i<n1 && j<n2){
             if(a1[i]<=a2[j]){
                 arr[k++]=a1[i++];
             }
             else{
                 arr[k++]=a2[j++];
                 inv+=n1-i;
             }
         }
         while(i<n1){
              arr[k++]=a1[i++];
         }
         while(j<n2){
               arr[k++]=a2[j++];
         }
         return inv;
    }

    long long mergeSort(long long arr[], long long l, long long r)
    {
        //code here
        long long inv=0;
        if(l<r){
            int mid=(l+r)/2;
           inv+= mergeSort(arr,l,mid);
           inv+= mergeSort(arr,mid+1,r);
           inv+= merge(arr,l,mid,r);
        }
        return inv;
    }
long long getInversions(long long *arr, int n){
    // Write your code here.
    return mergeSort(arr,0,n-1);

}