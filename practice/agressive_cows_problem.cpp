#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool isValid(vector<int> arr , int cows , int n , int minAllowedDistance){
    int cow = 1;
    int lastPosition = arr[0];

    for(int i = 0; i < n; i++){

        if(arr[i]-lastPosition >= minAllowedDistance){
            cow++;
            lastPosition = arr[i];
        }

        if (cow==cows) {

            return true;

        }
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k) {


       // code here
       int n = stalls.size();


       sort(stalls.begin(),stalls.end());

       int start = 1 , end = stalls[n-1]-stalls[0] , ans = -1;

       while (start <= end) {
           int mid = start + (end-start)/2;
           if(isValid(stalls,k,n,mid)){
               start = mid+1;
               ans = mid;
           }else end = mid-1;
       }

       return ans;

   }
int main(){

    int n,k;
    cin>>n>>k;
    vector<int> stalls(n);
    for(int i = 0; i < n; i++){
        cin>>stalls[i];
    }
    cout<<aggressiveCows(stalls,k)<<endl;

    return 0;
}
