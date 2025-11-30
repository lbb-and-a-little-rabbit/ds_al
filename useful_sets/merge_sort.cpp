#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr,int left,int right,int mid){
    int n1=mid-left+1;
    int n2=right-mid;
    vector<int> L;
    vector<int> R;
    for(int i=0;i<n1;i++) L.push_back(arr[left+i]);
    for(int i=0;i<n2;i++) R.push_back(arr[mid+1+i]);
    int l=0,r=0,k=0;
    while(l<n1&&r<n2){
        if(L[l]<R[r]){
            arr[left+k]=L[l];
            l++;
            k++;
        }
        else{
            arr[left+k]=R[r];
            r++;
            k++;
        }
    }
    while(l<n1){
        arr[left+k]=L[l];
        l++;
        k++;
    }
    while(r<n2){
        arr[left+k]=R[r];
        r++;
        k++;
    }
}

void merge_sort(vector<int> &arr,int left,int right){
    if(left>=right) return;
    int mid=left+(right-left)/2;
    merge_sort(arr,left,mid);
    merge_sort(arr,mid+1,right);
    merge(arr,left,right,mid);
}

int main(){
    vector<int> arr;
    int n;
    cin >> n;
    int a;
    for(int i=0;i<n;i++){
        cin >> a;
        arr.push_back(a);
    }
    merge_sort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}