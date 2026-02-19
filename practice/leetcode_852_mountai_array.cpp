#include <iostream>
#include <vector>
using namespace std;
int peakIndexInMountainArray(vector<int>& arr) {

        int n = arr.size(),start = 1 , end = n-2;

        while(start <= end){
            int mid = start + (end - start)/2;

            if (arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]) return mid;

            if (arr[mid]>arr[mid-1]){

                start = mid + 1;

            }else end = mid - 1;
        }
        return -1;
    }

int main(){
    vector<int> arr = {0,2,1,0};
    cout << peakIndexInMountainArray(arr) << endl;
    return 0;
}
