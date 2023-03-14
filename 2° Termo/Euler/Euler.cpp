#include <iostream>
using namespace std;

long double fatorial(int n){
    int fat = 1;
    for(int k = 2; k <= n; k++){
    fat *= k;
    } return fat;
}

int main() {
    int n; long double e = 0;
    cin >> n;
    for(int i = 0;i <= n;i++){
    e += (1.0/ fatorial(i));
    } cout << fixed; cout.precision(16); cout << e << endl;
    return 0;
}
