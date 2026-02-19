#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
        int start = 0 , end = nums.size() - 1;

        while (start <= end){
            int mid = start + ((end-start)/2);

            if (nums[mid] == target) return mid; // checking if the mid is the result

            if (nums[start] <= nums[mid]){ //checking if the left side is sorted
                //checking if the target exists in the left side , if exists then end = mid - 1 ; to search on that side
                if (nums[start] <= target && target <= nums[mid]){
                    end = mid - 1;
                }else{//if the target doesn't exist then change the start to mid+1 so that it can be searched in the right side
                    start = mid + 1;
                }

            }else{ // if the rotated array is not sorted in the left side then it is sorted in the right side

                //checking if the targeg exists in the right side , if exists then start = mid + 1; to search on that side
                if (nums[mid] <= target && target <= nums[end]){
                    start = mid + 1;
                }else{ // if target doesn't exist then end = mid - 1 ; to search on the left side of the array because target doesn't exist in the right side
                    end = mid - 1;
                }
            }
        }

        // if target is not found then return -1;
        return -1;
    }


int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    cout << search(nums, target);
    return 0;
}
