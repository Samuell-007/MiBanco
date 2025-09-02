#include <iostream>
using namespace std;

int menu(float saldo) {
    cout << "\nSaldo actual: " << saldo << "\n";
    cout << "1. Consultar saldo\n";
    cout << "2. Depositar\n";
    cout << "3. Retirar\n";
    cout << "4. Salir\n";
    cout << "Opcion: ";
    int op;
    cin >> op;
    return op;
}

int main() {
    float saldo = 50000, monto;
    int opcion;

    do {
        opcion = menu(saldo);
        switch (opcion) {
            case 1:
                cout << "Saldo actual: " << saldo << "\n";
                break;
            case 2:
                cout << "Monto a depositar: ";
                cin >> monto;
                saldo += monto;
                cout << "Saldo actual: " << saldo << "\n";
                break;
            case 3:
                cout << "Monto a retirar: ";
                cin >> monto;
                if (monto > saldo) {
                    cout << "Fondos insuficientes. Saldo actual: " << saldo << "\n";
                }
                else {
                    saldo -= monto;
                    cout << "Retiro exitoso. Saldo actual: " << saldo << "\n";
                }
                break;
            case 4:
                cout << "Gracias por usar el cajero.\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    }
    while (opcion != 4);
    return 0;
}
//
// Created by USUARIO on 1/09/2025.
//
