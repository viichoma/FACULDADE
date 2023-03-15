#include <iostream>
using namespace std;
void primo(int n){
    int i,div = 0;
    for (i = 1; i <= n; i++){
        if (n % i == 0) div++;}
        if (div==2) {
            cout << "PRIMO";
        }else cout << "!PRIMO";
}
int main() {
    int teste = 0;
    cin >> teste;
    primo(teste);
    return 0;
}
