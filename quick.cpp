#include<iostream>

using namespace std;

int partition(int arr[],int s,int e){
    int pivotIndex=s;
    int pivotElement=arr[s];

    int count=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivotElement){
            count++;
        }
    }

    //when i come out of loop, i'll have pivot's right position
    int rightIndex=s+count;
    swap(arr[pivotIndex],arr[rightIndex]);
    pivotIndex=rightIndex;

    int i=s;
    int j=e;

    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<pivotElement){
            i++;
        }
        while(arr[j]>pivotElement){
            j--;
        }

        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i],arr[j]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[],int s,int e){
    if(s>=e){
        return ;
    }

    //partiton
    int p=partition(arr,s,e);

    //recursive calls
    //left
    quickSort(arr,s,p-1);

    //right
    quickSort(arr,p+1,e);
}

int main(){

    int arr[] {5,4,3,2,1};
    int n=5;

    int s=0;
    int e=n-1;
    quickSort(arr,s,e);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}