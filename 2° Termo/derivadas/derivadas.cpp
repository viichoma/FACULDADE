#include <iostream>
using namespace std;
void derivada(double vet, int grau) {
    if (grau > 2){
        cout << grau * vet << "x^" << grau - 1 << "+";
    }
    else if (grau == 2) {
        cout << grau * vet << "x" <<"+";
    } else cout << (grau * vet);
};

int main() {
    int grau, i = 0, g = 0;
    cin >> grau;
    if (grau > 0 && grau <= 100) {
        int aux = grau;
        double vetores[101];
        while (g <= (grau)) {
            cin >> vetores[i];
            g++, i++;
        }
        for (i = 0; i < aux; i++) {
            if (vetores[i] != 0) {
                derivada(vetores[i], grau);
            }
            grau--;
        }
    }
}