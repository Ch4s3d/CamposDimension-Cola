#include "Admin.h"

int main()
{
    int op;
    Admin admin;
    do {
        cout << "1. Encolar" << endl;
        cout << "2. Desencolar" << endl;
        cout << "3. Frente" << endl;
        cout << "0. Salir" << endl;
        cin >> op;
    } while (admin.menu(op));

    cout << "Listo" << endl;
    return -1;
}
