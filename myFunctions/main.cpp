#include <iostream>

using namespace std;


//1. Get sum of a vector from i to j. Uses memoization
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

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
