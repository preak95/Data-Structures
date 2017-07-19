#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void allSubsets(string array, vector<string> &vee, int x)
{
    long int n=array.size();
    string p;
    if(n>1)
    for(unsigned int i=0; i<n-x+1; i++){
        p ="";
        for(int j=i; j<i+x; j++){
            p+= array[j];
        }
        if ( p.length() == x) {
                vee.push_back(p);
                //cout<<"String: "<<p<<endl;
            }
    }
    else
        vee.push_back(array);
 }

int main() {
    string s;
    vector<string> v;
    vector<long int> summ;
    long int k,b,m;
    cin>>s;
    cin>>k>>b>>m;

    allSubsets(s,v,k);

    for(unsigned int i=0; i<v.size(); i++){
        string q = v[i];
        long int number = 0;
        long int cnt = 0;
        while(q.length() != 0){
            string temp = q;
            temp = temp.back();
            long int a;
            try{
                 a = std::stol(temp);
            }
            catch(int e){
                return e;
            }

            long int f =  pow(b,cnt);
            long int w = f % m;
            //cout<<"val i get:"<<a*f<<" and"<<a * pow(b,cnt)<<endl;
            number += a * w ;
            cnt++;

            q.pop_back();
        }
        //cout<<"Out: "<<number%m<<endl;
        summ.push_back(number%m);
    }
    long int sum = 0;
    for(unsigned int i=0; i<summ.size(); i++)
        sum+= summ[i];

    cout<<sum;
    return 0;
}
