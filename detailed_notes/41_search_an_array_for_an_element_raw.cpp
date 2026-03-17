#include<iostream>

int searchArray(int[],int,int);

int main(){

    int arr[] = {1,2,3,4,5,6,7,8,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int index;
    int target;

    std::cout<<"which element you want to find?"<<'\n';
    std::cin>>target;

    index = searchArray(arr,size,target);

    if(index != -1){
        std::cout<<"Your element is found on index "<<index;
    }else{
        std::cout<<"Element not found";
    }

    return 0;

}

int searchArray(int array[],int size,int target){

    for(int i = 0; i < size ; i++){

        if(array[i] == target){
            return i;
        }

    }

    return -1;
    
}