#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Cliente {
    string nombre;
    float saldo;
};

const int MAX_CLIENTES = 100;
Cliente clientes[MAX_CLIENTES];
int numClientes = 0;

int buscarCliente(const string& nombre) {
    for (int i = 0; i < numClientes; i++) {
        if (clientes[i].nombre == nombre) return i;
    }
    return -1;
}

void agregarCliente() {
    if (numClientes >= MAX_CLIENTES) {
        cout << "No se pueden agregar mas clientes.\n";
        return;
    }
    cout << "Nombre del cliente: ";
    string nombre;
    cin >> nombre;
    if (buscarCliente(nombre) != -1) {
        cout << "El cliente ya existe.\n";
        return;
    }
    clientes[numClientes].nombre = nombre;
    clientes[numClientes].saldo = 0;
    numClientes++;
    cout << "Cliente agregado exitosamente.\n";
}

void listarClientes() {
    if (numClientes == 0) {
        cout << "No hay clientes registrados.\n";
        return;
    }
    for (int i = 0; i < numClientes; i++) {
        cout << clientes[i].nombre << " - Saldo: " << clientes[i].saldo << "\n";
    }
}

void consignar() {
    cout << "Nombre del cliente: ";
    string nombre;
    cin >> nombre;
    int idx = buscarCliente(nombre);
    if (idx == -1) {
        cout << "Cliente no encontrado.\n";
        return;
    }
    float monto;
    cout << "Monto a consignar: ";
    cin >> monto;
    clientes[idx].saldo += monto;
    cout << "Consignacion exitosa. Nuevo saldo: " << clientes[idx].saldo << "\n";
}

void retirar() {
    cout << "Nombre del cliente: ";
    string nombre;
    cin >> nombre;
    int idx = buscarCliente(nombre);
    if (idx == -1) {
        cout << "Cliente no encontrado.\n";
        return;
    }
    float monto;
    cout << "Monto a retirar: ";
    cin >> monto;
    if (monto > clientes[idx].saldo) {
        cout << "Fondos insuficientes. Saldo actual: " << clientes[idx].saldo << "\n";
    } else {
        clientes[idx].saldo -= monto;
        cout << "Retiro exitoso. Nuevo saldo: " << clientes[idx].saldo << "\n";
    }
}

void transferir() {
    cout << "Cliente origen: ";
    string origen;
    cin >> origen;
    int idxOrigen = buscarCliente(origen);
    if (idxOrigen == -1) {
        cout << "Cliente origen no encontrado.\n";
        return;
    }

    cout << "Cliente destino: ";
    string destino;
    cin >> destino;
    int idxDestino = buscarCliente(destino);
    if (idxDestino == -1) {
        cout << "Cliente destino no encontrado.\n";
        return;
    }

    float monto;
    cout << "Monto a transferir: ";
    cin >> monto;
    if (monto > clientes[idxOrigen].saldo) {
        cout << "Fondos insuficientes en " << origen << ".\n";
    } else {
        clientes[idxOrigen].saldo -= monto;
        clientes[idxDestino].saldo += monto;
        cout << "Transferencia exitosa.\n";
    }
}

void totales() {
    float suma = 0;
    for (int i = 0; i < numClientes; i++) {
        suma += clientes[i].saldo;
    }
    cout << "Total de saldos en el banco: " << suma << "\n";
}

int main() {
    int opcion;
    do {
        cout << "\nMENU MI BANCO\n";
        cout << "1. Agregar cliente\n";
        cout << "2. Listar clientes\n";
        cout << "3. Consignar\n";
        cout << "4. Retirar\n";
        cout << "5. Transferir\n";
        cout << "6. Totales\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: agregarCliente(); break;
            case 2: listarClientes(); break;
            case 3: consignar(); break;
            case 4: retirar(); break;
            case 5: transferir(); break;
            case 6: totales(); break;
            case 0: cout << "Gracias por usar el banco.\n"; break;
            default: cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);

    return 0;
}
