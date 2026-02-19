#include <iostream>
#include <vector>
using namespace std;
int majorityElement(vector<int>& vec){//there & is just useless but just used to practice it.
    int frequency = 0 , ans = 0;
    for (int i = 0 ; i < vec.size() ; i++){
        if (frequency == 0){
            ans = vec[i];
        }
        if (ans == vec[i]){
            frequency++;
        }else{
            frequency--;
        }
        //to make sure that this array has majority element.This extra step will be necessary if there is chance that majority element doesn't exist
        int count = 0;
        for (int val : vec){
            if (ans == val){
                count++;
            }
        }
        if (count > (vec.size())/2){
            return ans;
        }else {
            return -1;
        }
    }
    return ans; // return answer [directly return when there is no chance of that the array don't have any majority element]

}
int main(){
    vector<int> vec = {1,2,3,1,1,1,1,2,1};
    cout<<majorityElement(vec);
    return 0;
}
