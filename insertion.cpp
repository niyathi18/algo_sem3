#include<iostream>

using namespace std;

int main(){
    vector<int> arr{5,4,3,2,1};
    int n=arr.size();

    //insertion sort
    for(int i=1;i<n;i++){
        int j=i-1;
        int val=arr[i];
        for( j=i-1;j>=0;j--){
            if(arr[j]>val){
                //shift
                arr[j+1]=arr[j];
            }else{
                break;
            }
        }
        arr[j+1]=val;
    }

//printing
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
    return 0;
}