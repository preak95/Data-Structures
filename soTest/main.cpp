#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> sums(100, vector<int>(100, 0));


int getsum(vector<int> a, int i, int j){
    if(sums[i][j] > 0){
        return sums[i][j];
    }

    if(i==j)
        return a[i];

    else{
        sums[i][j] = a[j]+getsum(a,i,j-1);
        return sums[i][j];
    }
}
/*
int givenr(vector<int> a, int n, int req){
    int i,j; i=0; j=n-1;
    int sum = a[0];

    return 0;
}
*/
int main()
{
    vector<int> a(10);
    for(int i=1; i<10; i++)
        a[i] = i;

    int sum1 = getsum(a, 0, 4);
    cout<<"sum1: "<<sum1<<endl;
    int sum2 = getsum(a, 0, 6);
    cout<<"sum2: "<<sum2<<endl;
    int sum3 = getsum(a, 0, 9);
    cout<<"sum3: "<<sum3<<endl;

    cout<<toupper('s')<<endl;
    return 0;
}
