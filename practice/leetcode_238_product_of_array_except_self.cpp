#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(); // calculating n to use in the code

        vector<int> ans(n , 1); //here n is the size and 1 is assigned to every value

        int prefix_product = 1 , suffix_product = 1;

        for(int i = 1 ; i < n ; i++){
            prefix_product *= nums[i-1];
            ans[i] = prefix_product;
            // ans[i] = ans[i-1]*nums[i-1]; // failed try to improve memory usage
        }

        // int suffix_product = 1; // failed try to improve memory usage

        for (int i = n-2 ; i >= 0 ; i--){
            suffix_product *= nums[i+1];
            ans[i] *= suffix_product;
        }

        return ans;
    }

int main (){

    vector<int> nums = {1,2,3,4};
    vector<int> result = productExceptSelf(nums);

    for(int i = 0 ; i < result.size() ; i++){
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}
