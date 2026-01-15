#include <iostream>
using namespace std;
int main (void){
    char snils[15];
    cin.getline(snils, 15);
    int k = 9;
    int summ = 0;
    for(int i = 0; i < 11; i++){
        if (snils[i] - '0' >= 0 && snils[i] - '0' <= 9){
            if (k >= 1){
                summ += (snils[i] - '0') * k;
                k--;
            }else{
                break;
            }
            

        }
    }
    int carry = summ % 101;
    int kontrSumm = 0;
    
    for (int i = 12, k = 10; i < 14; i++){
        kontrSumm += (snils[i] - '0') * k;
        k = k / 10;

    }
    if (carry == kontrSumm){
        cout<<"Контрольное число "<<kontrSumm<<" — указано верно";
    }else
        cout<<"Контрольное число "<<kontrSumm<<" — указано неверно";
    
    

}