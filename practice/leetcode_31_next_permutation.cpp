#include<iostream>
#include<vector>
using namespace std;

void nextPermutation(vector<int>& A) {

        // finding pivot
        int pivot = -1 , n = A.size();

        for(int i = n-2 ; i>=0 ; i-- ){
            if(A[i]<A[i+1]){
                pivot = i;
                break;
            }
        }
        // reversing array if pivot not found
        if (pivot == -1) {
            reverse(A.begin(),A.end());
            return;
        }
        //swapping pivot and closest larger number in the right side of the array
        for (int i = n-1; i >= 0; i--){
            if (A[pivot]<A[i]){
                swap(A[pivot],A[i]);
                break;
            }
        }
        //now sorting
        int i = pivot+1 , j = n-1;

        while(i <= j){
            swap(A[i],A[j]);
            i++,j--;
        }
        return;

    }

int main(){
    vector<int> A = {1,2,3};
    nextPermutation(A);
    for(int i = 0 ; i < A.size() ; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}
