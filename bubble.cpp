#include<iostream>
#include<iostream>

using namespace std;

int main(){
vector<int> arr{5,4,3,2,1};
int n=arr.size();

//bubble sort
for(int i=0;i<n;i++){
    for(int j=0;j<n-1;j++){
        if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
        }
    }
}

//printing
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}

    return 0;
}