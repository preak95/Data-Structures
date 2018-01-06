#include <iostream>
#include <vector>
#include <ctime>

/*This is meant to provide all the sorting algorithms.*/

using namespace std;

int n;
vector<int> arr;

void printList(vector<int> arr){
    for(int i=0; i<arr.size(); i++)
        cout<<arr[i]<<" ";

    cout<<"\n";
}

void getArray(){
    cout<<"Enter no. of elements"<<endl;
    cin>>n;
    arr = vector<int>(n);
    cout<<"Enter the "<<n<<" elements"<<endl;
    for(int i=0; i<n; i++)
        cin>>arr[i];
}

void bubbleSort(vector<int> a){
    int flag = 0;
    time_t t1 = time(0);
    const long double time1 = t1*1000;
    for(unsigned int i=0; i<a.size(); i++){
        flag = 0;
        for(unsigned int j=0; j<a.size()-1; j++){
            if(a[j+1]<a[j]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = 0;
            }
            else
                flag++;
        }
        if(flag == a.size()-1)
            break;
    }
    time_t t2 = time(0);
    const long double time2 = t2*1000;
    for(int j=0; j<a.size(); j++){
        cout<<a[j]<<" ";
    }

    cout<<"\n Time taken: "<<time2<<endl;

}

void insertionSort(vector<int> arr){
    for(int i=1; i<arr.size(); i++){
        int temp = arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
        for(int k=0; k<arr.size(); k++)
                cout<<arr[k]<<" ";
            cout<<""<<endl;
    }
}

void quickSort(vector<int> &arr, int lb, int ub){
    if(lb >= ub)
        return;
    //arr[lb] as pivot
    int pivot = arr[ub];
    int pIndex = lb;
    for(int i=lb; i<ub; i++){
        if(arr[i]<=pivot){ // Swap
            int temp = arr[i];
            arr[i] = arr[pIndex];
            arr[pIndex] = temp;
            pIndex++;
        }
    }

    int t = arr[ub];
    arr[ub] = arr[pIndex];
    arr[pIndex] = t;

    quickSort(arr, lb, pIndex-1);
    quickSort(arr, pIndex+1, ub);
}

int main()
{
    cout << "Hello! Enter your array size" << endl;
    cin>>n;
    arr = vector<int>(n);
    cout << "Enter the elements of array."<<endl;
    for(int i=0; i<n; i++)
        cin>>arr[i];


    string menu = "1. Bubble sort \n2. Insertion Sort \n3. Quick Sort\n8. New array\n0. Exit";
    int c = 99;
    do{
        cout<<"Enter the method"<<endl;
        cout<<menu<<endl;
        cin>>c;
        switch(c){
            case 1: {
                        cout<<"You chose Bubble sort"<<endl;
                        bubbleSort(arr);
                    }
            break;

            case 2: {
                        cout<<"You chose Insertion sort"<<endl;
                        insertionSort(arr);
                    }
            break;

            case 3: {
                        cout<<"You chose Quick sort"<<endl;
                        quickSort(arr, 0, arr.size()-1);
                        printList(arr);
                    }
            break;

            case 8: {
                        getArray();
                    }
            break;

            case 0: c = 0;
            break;

            default: cout<<"Wrong Choice"<<endl;
        }
    }while(c!=0);
    return 0;
}
