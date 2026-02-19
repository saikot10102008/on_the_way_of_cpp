#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
//real function
int maxSubArray(vector<int>& nums){
    int currentSum = 0,maxSum = INT_MIN;
            for (int num:nums){
                currentSum += num;
                maxSum = max(maxSum,currentSum);
                if (currentSum < 0){
                    currentSum = 0;
                }
            }
            return maxSum;
}
//practice function prototype
int maximumSomeinSubarray(vector<int>& numm);
//main function
int main () {
    vector<int> vec = {2,1,3,3,-9,4,-3,-4,5,-9};//the vector in which we will operate
    cout<<maxSubArray(vec)<<"\n"<<maximumSomeinSubarray(vec);//testing my practice function if it does work.
    return 0;
}
//practice function
int maximumSomeinSubarray(vector<int>& numm){

    int currentSum = 0 , maxSum = INT_MIN;
    for (int num : numm){
        currentSum += num;
        maxSum = max(maxSum,currentSum);
        if (currentSum<0){currentSum = 0;}
    }

    return maxSum;

}
