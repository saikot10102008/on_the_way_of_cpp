#include <iostream>
#include<vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // //solution 1
        // int i = 0;
        // for (int num2:nums2){
        //     nums1[m+i] = num2;
        //     i++;
        // }
        // sort(nums1.begin(),nums1.end());
        //
        //
        // //solution 2
        int idx = m+n-1 , i = m-1 , j = n-1;

        while(i >= 0 && j >= 0){
            if(nums1[i] >= nums2[j]){
                nums1[idx--] = nums1[i--];
                // idx--,i--
            }else{
                nums1[idx--] = nums2[j--];
            }

        }
            while(j >= 0){
                nums1[idx--] = nums2[j--];
            }
    }

int main(){
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    merge(nums1,3,nums2,3);
    for(int num:nums1){
        cout<<num<<" ";
    }
    return 0;
}
