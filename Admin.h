#ifndef ADMIN_H
#define ADMIN_H
#include "ClassA.h"
#define ClassASize sizeof(char)*20 +sizeof(int)
#define CLASSBSIZE sizeof(double) + sizeof (bool)

class Admin
{
    ClassA* Capturar()
    {
        ClassA* nuevo = new ClassA();
        cout << "Entero: ";
        cin >> nuevo->entero;
        cin.ignore();
        cout << "Cadena: ";
        cin.getline(nuevo->cadena, 20);
        cout << "Cantidad de ClassB: ";
        cin >> nuevo->contClassB;

        ClassB* nuevoB = new ClassB[nuevo->contClassB];
        for(int i=0 ; i<nuevo->contClassB ; i++)
        {
            double doble;
            bool bul;

            cout << "\tClassB " << i+1 << ":" << endl;
            cout << "Doble:  ";
            cin >> doble;
            cout << "Booleano:  ";
            cin >> bul;
            ClassB n = *new ClassB(doble, bul);
            nuevoB[i] = n;
        }
        return nuevo;
    }
    void Encolar(ClassA* a)
    {
        ofstream fout("Archivo.bin",ios::app|ios::binary);
        if(!fout.good())
            fout.open("Archivo.bin",ios::app|ios::binary);
        fout << a;
        fout.close();
    }

    void Frente()
    {
        char* s = nullptr;

        ifstream fin("Archivo.bin", ios::binary);
        fin.read(s,sizeof(ClassA));
        ClassA a = *new ClassA(s);
        cout << a.toString();
        fin.close();
    }

    void Desencolar()
    {
        char* s;

        ifstream fin("Archivo.bin",ios::binary);
        ofstream fout("Auxiliar.bin",ios::app|ios::binary);
        fin.read(s,sizeof(ClassA));
        ClassA* a = new ClassA(s);
        cout << a->toString();
        delete a;

        fin.read(s,sizeof(ClassA));
        while(!fin.eof())
        {
            ClassA* a = new ClassA(s);
            fout << a->toString();
            delete a;
        }
        fin.close();
    }

public:
    bool menu(int op)
    {
        switch (op)
        {
        case 0:
            return false;
        case 1:
            Encolar(Capturar());
            return true;
        case 2:
            Desencolar();
            return true;
        case 3:
            Frente();
            return true;
        }
    }
};

#endif // ADMIN_H
