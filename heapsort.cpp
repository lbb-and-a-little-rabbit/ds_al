#include <iostream>
#include <vector>

using namespace std;

class heap{//maxheap
private:    
    vector<int> arr;

    int getparent(int i){return (i-1)/2;}

    int getleft(int i){return 2*i+1;}

    int getright(int i){return 2*i+2;}

    void siftDown(int i,int size){
        int large=i;
        int l=getleft(i);
        int r=getright(i);
        if(l<size&&arr[l]>arr[large]) large=l;
        if(r<size&&arr[r]>arr[large]) large=r;
        if(large!=i){
            swap(arr[i],arr[large]);
            siftDown(large,size);
        }
    }

    void siftUp(int i){
        if(i==0) return;
        int par=getparent(i);
        if(arr[par]<arr[i]){
            swap(arr[i],arr[par]);
            siftUp(par);
        }
        else{
            return;
        }
    }

    void buildHeap(const vector<int> &arr){
        int n=arr.size();
        for(int i=n/2-1;i>=0;i--){
            siftDown(i,n);
        }
    }

public:
    heap(){}

    heap(const vector<int> &arr){
        this->arr=arr;
        buildHeap(this->arr);
    }

    void insert(int i){
        arr.push_back(i);
        siftUp(this->arr.size()-1);
    }

    bool isempty(){
        return this->arr.size()==0;
    }

    int extractMax(){
        if(this->isempty()){
            cout << "heap is empty" << '\n';
            return -1;
        }
        int root=arr[0];
        arr[0]=arr[arr.size()-1];
        arr.pop_back();
        siftDown(0,arr.size());
        return root;
    }
};

    void Heapsort(vector<int> &nums){
        heap h(nums);
        for(int i=nums.size()-1;i>=0;i--){
            nums[i]=h.extractMax();
        }
    }

int main(){
    vector<int> arr;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int tem;
        cin >> tem;
        arr.push_back(tem);
    }
    Heapsort(arr);
    for(int i=0;i<n;i++){
        cout << arr[i] << ' ';
    }
}