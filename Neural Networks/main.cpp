#include <iostream>
#include <math.h>

using namespace std;

float lRate = 0.05;

class Neuron{
    float w1; float w2;
public:
    Neuron(){
        w1 = 2.5;
        w2 = 2.5;
    }
    float output(float X, float Y){
        float out = w1*X + w2*Y;
        backProp(X,Y,X+Y);
        return out;
    }

    void backProp(float x, float y, float real){
        float temp1 = w1 - 2*lRate*( w1*x + w2*y - real);
        float temp2 = w2 - 2*lRate*( w1*x + w2*y - real);
        this->w1 = temp1; this->w2 = temp2;
    }

    float activationFunc(float x){
        return 1/(1+exp(x*(-1)));
    }

    void printWeights(){
        cout<<"W1: "<<w1<<" W2: "<<w2<<endl;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    Neuron n1;

    n1.backProp(3,2,5);
    n1.backProp(1,1,2);
    n1.backProp(0,1,1);
    n1.backProp(1,2,3);
    n1.backProp(3,3,6);
    n1.backProp(0,0,0);
    n1.backProp(2,3,5);
    n1.backProp(2,1,3);

    cout<<"Output:"<<n1.output(1,0)<<endl;


    cout<<"1. Enter values of x and y"<<endl;
    cout<<"2. Print the weights"<<endl;
    cout<<"3. Reset weight to 0"<<endl;

    int s,w;
    while(s!=0){
        cin>>s;
        switch(s){
            case 1: {
                        cout<<"Enter x and y"<<endl;
                        int x,y; cin>>x>>y;
                        cout<<"Output:"<<n1.output(x,y)<<endl;
                    }
            break;
            case 2: n1.printWeights();
            break;
            case 3: w = 0;
            break;
            case 0: "Exiting!";
            break;
            default: cout<<"Wrong choice"<<endl;
        }
    }

    return 0;
}
