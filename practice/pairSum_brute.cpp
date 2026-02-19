#include <iostream>
#include <vector>
using namespace std;
//pair sum : Return pair in sorted array with target sum
vector<int> pairSum(vector<int> array , int target){
    vector<int> ans;
    int n = array.size();
    for (int i = 0;i < n;i++){
        for(int j = i+1; j < n ; j++){
            if (array[i]+array[j]==target){
                ans.push_back(i);
                ans.push_back(j);
                // return ans; ////retruning the answer here and returning it to the last line is the same
            }
        }
    }
    return ans;
}

//pair sum problem solve : brute force approach
//the example array = {1,2,3,4} , target = 6

int main () {
    int target = 9;
    vector<int> vec = {1,2,3,4,6,7,8,9,0};
    vector<int> ans = pairSum(vec,target);
    cout<<ans[0]<<" "<<ans[1];

    return 0;
}
