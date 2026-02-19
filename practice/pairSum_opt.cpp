//pair sum : Return pair in sorted array with target sum
#include <iostream>
#include <vector>
using namespace std;
vector<int> pairSum (vector<int> vec,int target){
    int n = vec.size();
    int i = 0;
    int j = n-1;
    vector<int> vect;
    while (i<j) {
        int pairSum = vec[i]+vec[j];
        if (pairSum<target){
            i++;
        }else if (pairSum>target) {
            j--;
        }else if (pairSum==target) {
            vect.push_back(i);
            vect.push_back(j);
            return vect;
        }
        // if (pairSum==target){
        //     vect.push_back(vec[i]);
        //     vect.push_back(vec[j]);
        //     return vect;
        // }else if (pairSum<target){
        //     i++;
        // }else if(pairSum>target) {
        //     j--;
        // }

    }
    return vect;
}
int main (){
    vector<int> vec = {1,2,3,4,5,6,7,8};
    vector<int> ans = pairSum(vec,8);
    cout<<ans[0]<<' '<<ans[1];
    return 0;
}
