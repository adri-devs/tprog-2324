#include <iostream>
#include "cuenta.cc"

using namespace std;

double total(Cuenta* cuentas[], int n, int t) {
    double res = 0;
    for (int i = 0; i < n; i++) {
        res += cuentas[i]->valor(t);
    }
    return res;
}

// misma implementacion para todas
void mostrar_taes(Cuenta* cuentas[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Cuenta " << i << " TAE: " << cuentas[i]->tae(1) << endl;
    }

}

// Cuidado con los gch

int main() {
    Cuenta* cuentas[4];
    // Constructor 1
    cuentas[0] = new Cuenta(Cuenta::AHORRO, 1000, 0.05, 0);
    // Constructor 2
    cuentas[1] = new Cuenta(2000, 0.03);
    // Constructor 3
    cuentas[2] = new Cuenta(3000, 0.04, 3);
    for (int i = 0; i < 4; ++i) {
        cout << "Cuenta " << i << " valor: " << cuentas[i]->valor(1) << endl;
    }
    mostrar_taes(cuentas, 4);
    return 0;
}