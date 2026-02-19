//steps
// 1.First of all: sort the array
// a element will be the majority element if it is present more than n/2 times in a array.[n = array size]
// 2.After sorting the array we will get elements in a order that repeating elements will be in a continuos subarray
// 3.So , now we will use a loop to calculate the number of occurence of every element.When we get a element that occured more than n/2 times , we will return the element.
// This is how we can finde the majority element in an array
// Solution:
// sort function: sort(vector.begin(),vector.end());
#include <algorithm>
#include <iostream>
#include <sys/types.h>
#include <vector>
using namespace std;
int majorityElement(vector<int> vec){
    int n = vec.size();
    //sorting
    sort(vec.begin(),vec.end());
    //initialization: frequency is equals to occurence and we will assign the value of frequency = 1; and ans = vec[0]
    int frequency = 1 , ans = vec[0];
    for (int i = 1 ; i < n;i++){
        if (vec[i] == vec[i-1]){
            frequency++;
        }else{
            frequency = 1;
            ans = vec[i];
            // frequency = 1, ans = vec[i];
        }
        if (frequency>n/2){return ans;}
    }
    return ans;
}
int main(){
    vector<int> vect = {1,2,5,7,3,5,9,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    cout<<majorityElement(vect);
    return 0;
}
//summary from gemini:
// This C++ code provides a solution to the LeetCode problem "169. Majority Element". Here's a summary of how it works:

// Algorithm:

// Sorting: The code begins by sorting the input vector vec using the std::sort() function. This step is crucial because it brings all identical elements together in contiguous sub-arrays.

// Iterating and Counting: After sorting, the code iterates through the sorted vector, starting from the second element (index 1). It maintains two variables:

// frequency: Keeps track of the current consecutive count of the same element. It's initialized to 1 (for the first element).
// ans: Stores the current element being tracked for majority. It's initialized to the first element of the vector (vec[0]).
// Frequency Check: In each iteration, the code compares the current element (vec[i]) with the previous element (vec[i-1]).

// If they are the same: It increments the frequency counter.
// If they are different: It resets the frequency counter to 1 and updates ans to the current element (vec[i]), as a new sequence of potentially majority elements has begun.
// Majority Condition: Inside the loop, after updating the frequency, the code checks if frequency is greater than n/2, where n is the size of the input vector. If this condition is true, it means the current element (ans) has appeared more than half the times in the vector, so it is the majority element, and the function immediately returns ans.

// Final Return: If the loop completes without finding a majority element (although the problem statement guarantees one exists), the function returns the last stored value in ans. This will be the majority element because after sorting, the majority element will occupy a contiguous block of size greater than n/2.

// How it solves LeetCode Problem 169:

// The problem asks to find the majority element in an array, which is defined as an element that appears more than n/2 times. This code leverages the property that after sorting an array, all occurrences of the majority element will be adjacent to each other. By iterating through the sorted array and keeping track of the frequency of consecutive identical elements, the code efficiently identifies the element whose count exceeds n/2. The early return as soon as the majority condition is met can also optimize the process.
