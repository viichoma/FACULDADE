#include <iostream>
#include <cmath>
using namespace std;
void raizes (float a, float b, float c, float x1, float x2) {
    float delta = (b * b) - 4 * a * c;
    if (delta > 0) {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        cout << fixed; cout.precision(2);
        cout << x1 << "\t" << x2 << endl;
    } else cout << "NARN" << endl;
}

int main(){
    float a,b,c,x1 = 0.0 ,x2 = 0.0;
    ( cin >> a >> b >> c);
    raizes(a,b,c,x1,x2);
};
