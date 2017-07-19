#include <iostream>

using namespace std;

class test{
public:
    int a;
};

void funn(test &t){
    t.a = 10;
}

int main()
{
    test t1;
    t1.a = 2;
    funn(t1);
    cout << t1.a << endl;
    return 0;
}
