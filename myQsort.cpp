#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr,int left,int right){
    int pivot=arr[right];
    int pos=left;
    for(int i=left;i<right;i++){
        if(arr[i]<pivot){
            int tem=arr[pos];
            arr[pos]=arr[i];
            arr[i]=tem;
            pos++;
        }
    }
    int tem=arr[pos];
    arr[pos]=pivot;
    arr[right]=tem;
    return pos;
}

void quicksort(vector<int> &arr,int left,int right){
    if(left>=right) return;
    int part=partition(arr,left,right);
    quicksort(arr,left,part-1);
    quicksort(arr,part+1,right);
}

int main(){
    int n;
    vector<int> arr;
    cin >> n;
    int a;
    for(int i=0;i<n;i++){
        cin >> a;
        arr.push_back(a);
    }
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout << arr[i] << ' ';    
    }
}