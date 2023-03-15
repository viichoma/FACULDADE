#include <iostream>
using namespace std;
void dentro_ret (int x0, int y0, int x1, int y1, int x, int y){
    int min, max, min1, max1;
    if (x0 < x1){ min = x0; max = x1;}
    else {max = x0; min = x1;}

    if (y0 < y1){ min1 = y0; max1 = y1;}
    else { max1 = y0; min1 = y1;}

    if (min <= x && x <= max && min1 <= y && y <= max1){
        cout << "INTERNO";
    } else cout << "EXTERNO";
}

int main() {
    int x0, y0, x1, y1, x, y;
    cin >> x0 >> y0 >> x1 >> y1 >> x >> y;
    dentro_ret (x0, y0, x1, y1, x, y);
}
