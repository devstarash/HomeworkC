#include <iostream>
#include <vector>
using namespace std;
vector<int> sum(vector<int>& a, vector<int>& b){
    vector<int> c;
    int carry = 0;
    int minSize = a.size() > b.size() ? b.size() : a.size();
    for(int i = 0; i < minSize; i++){
        c.push_back((carry+ a[i] + b[i]) % 10);
        carry = (carry + a[i] + b[i]) / 10;                                                      
    }
    if ( a.size() > b.size()){
        c.push_back((a[a.size()-1] + carry) % 10);
        carry = (a[a.size()-1] + carry) / 10;    
    } else if (a.size() < b.size()){
        c.push_back((b[b.size()-1] + carry) % 10);
        carry = (b[b.size()-1] + carry) / 10;    

    }
    if (carry > 0){
        c.push_back(carry);
    }
    return c;
}
const int FIB_NUMBER= 10000;
int main(void){
    setlocale(LC_ALL, "RU");
    vector<int> f1;
    vector<int> f2;
    vector<int> f3;
    f1.push_back(0);
    f2.push_back(1);
    cout<<"10.000 Фибоначчи"<<endl;
    cout<<1<<" - "<<0<<endl;
    cout<<2<<" - "<<1<<endl;
    for (int i = 0; i < FIB_NUMBER - 1; i++){
        f3 = sum(f1, f2);
        f1 = f2;
        f2 = f3;
        cout<<i + 2<<" - ";
        for(int i = f3.size() - 1; i >= 0; i--){
            cout<<f3[i];
        }
        cout<<endl;
    }
}
