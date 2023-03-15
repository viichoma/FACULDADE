#include <iostream>
#include <cmath>
using namespace std;
double poli (double vet,int grau, double x){
    return (vet * (pow(x, grau)));
}
int main() {
    int grau, i = 0, g = 0;
    double vetores[101], xis = 0.0, multi = 0.0;
    cin >> grau >> xis;
    if (grau > 0 && grau <= 100) {
        int aux = grau;
        while (g <= grau) {
            cin >> vetores[i];
            g++,i++;
        }
        for (i = 0; i < aux; i++) {
            multi += poli(vetores[i], grau,xis);
            grau--;
        }
        cout << fixed; cout.precision(2); cout << multi +vetores[aux];
    }
}