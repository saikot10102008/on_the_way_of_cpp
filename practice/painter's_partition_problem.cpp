#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> arr , int max , int m , int n){



        int painter = 1;
        int ans = 0;

        for(int i = 0 ; i < n ; i++){

            if(arr[i]>max) return false;

            if(ans+arr[i] <= max){
                ans += arr[i];
            }else{
                painter++;
                ans = arr[i];

            }

        }

        return m < painter ? false:true;

    }





    int minTime(vector<int>& arr, int m) {
        // code here
        int n = arr.size();
        int sum = 0 , start = INT_MIN;
        for(int i =0; i < n ; i++){
            sum += arr[i];
            start = max(start,arr[i]);
        }
        int ans = -1;
        int end = sum;

        while(start <= end){

            int mid = start + (end - start)/2;

            if(isValid(arr,mid,m,n)){
                ans = mid;
                end = mid - 1;
            }else start = mid + 1;

        }

        return ans;
    }

int main(){
    vector<int> arr = {10, 20, 30, 40};
    int m = 2;

    cout << "Minimum time to paint all boards: " << minTime(arr, m) << endl;
    return 0;
}
