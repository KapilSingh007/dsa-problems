// User function template for C++

class Solution {
    public:
      void segregate0and1(vector<int> &arr) {
          // code here
          int n=arr.size();
          int i=0,j=n-1;
          
          while(i<j){
              while(arr[i] == 0 && i<n){
                  i++;
              }
              
              while(arr[j] == 1 && j>=0){
                  j--;
              }
              
              if(i<n && j>=0 && i<j){
                  swap(arr[i],arr[j]);
              }
            
          }
          
          
      }
  };