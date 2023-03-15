#include <iostream>
using namespace std;

    int main(){
        long int n, ult=1,pult=1,seg;
        cin >> n;
        if (n < 10000){
            if (n == 1 || n == 2){
                cout << ult;
            } else {
                for (int aux = 3; aux <= n; aux++){
                    seg= ult + pult;
                    pult = ult; ult = seg;
                } cout << seg;
            }
        }
    }