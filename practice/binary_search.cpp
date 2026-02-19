#include <iostream>
#include <vector>
using namespace std;

int binarysearch(vector<int> arr, int target){
    int start = 0 , end = arr.size() -1;

    while(start<=end){
        int mid = (start+end)/2;

        if (target > arr[mid]){
            start = mid + 1;
        }else if (target < arr[mid]){
            end = mid - 1;
        }else return mid;

    }

    return -1;

}

int recursive_binarysearch(vector<int> arr, int target, int start, int end){
    if(start <= end) {

    int mid = start+((end-start)/2);

    if(target > arr[mid]){
        return recursive_binarysearch(arr, target, mid+1, end);
    }else if(target < arr[mid]){
        return recursive_binarysearch(arr, target, start, mid-1);
    }else return mid;
    }
    return -1;
}

int main(){


    // int a = 5;
    // int* ptr = &a;
    // int** ptr2 = &ptr;
    // cout<<ptr2;
    // cout<<"\n"<<&ptr<<"\n";
    // cout<<*&ptr2<<"\n"<<*&ptr<<"\n"<<*&a<<"\n"<<*ptr<<"\n"<<**ptr2<<"\n";


    vector<int> vec = {1,2,3,4,5,6,7,8,9};

    int target = 9;

    cout<<binarysearch(vec,target);
    cout<<endl<<recursive_binarysearch(vec,target,0,vec.size()-1)<<endl;


    // recursive binary search is not efficient for large datasets
    return 0;
}
