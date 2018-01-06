#include <bits/stdc++.h>

using namespace std;

vector<string> suffixArray(string s){
    vector<string> sArray;
    for(int i=s.size()-1; i>=1; i--){
        sArray.push_back(s.substr(i,s.size()-1));
    }
    sArray.push_back(s);
    sort(sArray.begin(), sArray.end());
    return sArray;
}

int lcp(string a, string b){
    int i=0;
    while(i < a.size() && i < b.size()){
        if(a[i] == b[i]){
            i++;
        }
        else
            break;
    }
    return i;
}

int numberOfSubstrings(string str){
    vector<string> suffixArr = suffixArray(str);
    int LCP = 0;
    for(int i=0; i<suffixArr.size()-1; i++){
        LCP += lcp(suffixArr[i], suffixArr[i+1]);
    }
    int n = str.size();
    int nSub = ( n*(n+1)/ 2 ) - LCP;
    return nSub;
}

int main()
{
    string str = "CCCCC";
    cout<<numberOfSubstrings(str)<<endl;
    return 0;
}
