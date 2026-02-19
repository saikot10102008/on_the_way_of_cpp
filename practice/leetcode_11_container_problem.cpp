#include <iostream>
#include <vector>
using namespace std;
int maxArea(vector<int>& height) {
        int ans = 0;

        int right_pointer = height.size()-1 , left_pointer = 0;

        while(left_pointer < right_pointer){

            int ans_2 = (right_pointer-left_pointer) * min(height[left_pointer],height[right_pointer]);

            ans = max(ans,ans_2);

            if (height[left_pointer] < height[right_pointer]){

                left_pointer++;

            }else
                right_pointer--;
        }

        return ans;
    }
int main() {

    vector<int> heights = {1,8,6,2,5,4,8,3,7};
    cout<<maxArea(heights);

    return 0;
}
