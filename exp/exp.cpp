#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
bool isSimple(char *array){
    unsigned long long int sum = 0;
    bool isSimple = true;
    unsigned long long int k = 1;
    for (int i = 9; i >= 0; i--){
        sum += (array[i] - '0') * k;
        k *= 10;
    }
    if(sum % 2 == 0) return false;
    for(unsigned long long int i = 3; i * i <= sum; i += 2){
        if (sum % i == 0){
            isSimple = false;
            break;
            
        }
    }
    return isSimple;
}
int main(void){
    char buffer[11];
    buffer[10] = '\0';
    ifstream file;
    file.open("e2mil.txt");
    if( file.is_open() ){
        string skip;
        getline(file, skip);
        int line = 1;
        int position = 1;
        char ch;
        while(file.get(ch) && ch != '.')
            continue;
        int count = 0;
        while(count < 10 && file.get(ch)){
            if (ch >= '0' && ch <= '9'){
                buffer[count++] = ch;
            }   
        }if(isSimple(buffer)){
            cout<<"Найдено простое число - "<<buffer <<". Первая строка"<<endl;
            return 0;
        }else{
            while(file.get(ch)){
                if(ch < '0' || ch > '9'){
                    line += 1;
                    continue;
                }
                for(int i = 0; i < 9; i++) buffer[i] = buffer[i+1];
                buffer[9] = ch; 
                position ++;
                if(isSimple(buffer)){
                    cout<<"Найдено простое число - "<<buffer <<". Строка - "<<line<<". Позиция - "<<position<<endl;
                    return 0;
                }
            }
        }  
    }
}
    