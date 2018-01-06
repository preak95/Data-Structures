#include <bits/stdc++.h>
using namespace std;

void max_heapify(vector<int> &a, int i, int N){
    int left = 2*i+1;
    int right = 2*i+2;
    int largest;
    if(left < N && a[i]<a[left])
        largest = left;
    else
        largest = i;

    if(right < N && a[largest]<a[right] )
        largest = right;

    if(largest != i){
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        max_heapify(a, largest, N);
    }
}

void build_maxheap(vector<int> &a){
    int n = a.size();
    for(int i=(n/2)-1; i>=0; i--)
        max_heapify(a, i, n);
}

void heap_sort(vector<int> &a){
    int heap_size = a.size();
    build_maxheap(a);
    for(int i = a.size()-1; i>=0; i--){
        swap(a[0], a[i]);
        heap_size = heap_size - 1;
        max_heapify(a, 0, heap_size);
    }
}

void Merge(vector<int> &left, vector<int> &right, vector<int> &a){
    int nL = left.size(); int nR = right.size();
    int i=0; int j=0; int k=0;
    while(i < nL && j < nR){
        if(left[i] <= right[j]){
            a[k] = left[i];
            k++; i++;
        }
        else{
            a[k] = right[j];
            k++; j++;
        }
    }
    while(i < nL){
        a[k] = left[i];
        k++; i++;
    }
    while(j < nR){
        a[k] = right[j];
        k++; j++;
    }
}

void mergeSort(vector<int> &a){
    int n = a.size();
    if(n<2)
        return ;
    int mid = n/2;
    vector<int> left(mid);
    vector<int> right(n-mid);
    for(int i=0 ; i<mid; i++)
        left[i] = a[i];
    for(int i=mid ; i<n; i++)
        right[i-mid] = a[i];

    mergeSort(left); mergeSort(right);
    Merge(left, right, a);
}

int main() {
    int n; cin>>n;
	vector<int> arr(n);
	cout<<"Enter "<<n<<"values"<<endl;
	for(int i=0; i<n; i++)
	    cin>>arr[i];

    mergeSort(arr);
	for(int i=0; i<n; i++)
	    cout<<arr[i]<<" ";

	return 0;
}
