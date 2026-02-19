#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int>& nums) {

       int m = 0 , h = nums.size()-1 , l = 0;

       while(m <= h){

           if(nums[m] == 0){

               swap(nums[l],nums[m]);

               l++ , m++;

           }else if(nums[m] == 1){

               m++;

           }else{

               swap(nums[m],nums[h]);

               h--;

           }

       }
   }

int main (){
    vector<int> nums = {2,0,2,1,1,0};
    sortColors(nums);
    for(int num : nums){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
