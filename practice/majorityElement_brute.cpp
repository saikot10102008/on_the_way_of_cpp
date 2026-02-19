#include <iostream>
#include <vector>
using namespace std;
int majorityElement(vector<int> nums){
    int n = nums.size();
    for(int val : nums){//to count the number of repeatation of an element
        int frequency = 0;//frequency = the number of time an element repeats
        for (int num : nums){//trying to search through the whole array
            if(num == val){//for counting repeatation of an element
                frequency++;
            }
        }
        if (frequency > n/2){return val;}//majority element means it is in more than half of the indices
    }
    return -1;//if not found the majority element
}
int main(){
    vector<int> vec = {1,1,1,1,1,1,1,1,2,2,2,};
    cout<<majorityElement(vec);
    return 0;
}
