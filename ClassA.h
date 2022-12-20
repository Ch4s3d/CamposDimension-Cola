#ifndef CLASSA_H
#define CLASSA_H
#include "ClassB.h"
#define MAX 20
#define ClassASize sizeof(char)*20 +sizeof(int)
#define CLASSBSIZE sizeof(double) + sizeof (bool)

class ClassA
{
private:
    friend class Admin;
    char cadena[MAX];
    int entero;
    int contClassB;
    ClassB* b;
public:
    ClassA(char* cadena, int entero, int contClassB, ClassB* b)
    {
        for (int i=0 ; i<MAX ; i++)
            this->cadena[i] = cadena[i];
        this->entero = entero;
        this->contClassB = contClassB;
        b = new ClassB[contClassB];
        for (int i=0 ; i<contClassB ; i++)
            this->b[i] = b[i];
    }

    ClassA(){}

    ClassA(char* s)
    {
        int k = 0;
        string cadenaAux = "";
        for(int i=0 ; i<sizeof (char)*MAX ; i++, k++)
            ((char*)&cadena)[i] = s[k];
        for(int i=0 ; i<sizeof (int); i++, k++)
            ((char*)&entero)[i] = s[k];
        for(int i=0 ; i<sizeof (int); i++, k++)
            ((char*)&contClassB)[i] = s[k];
        b = new ClassB[contClassB];
        for(int i=0 ; i<contClassB; i++, k=+ sizeof (ClassB))
            ((char*)&b)[i] = s[k];
    }

    string toString()
    {
        string out;

        out = "Cadena: ";
        for(int i=0 ; i<9 ; i++)
            out += cadena[9];
        out += ", Entero: ";
        out += entero;

        for(int i=0 ; i<contClassB ; i++)
            b[i].toString();

        return out;
    }
};

#endif // CLASSA_H
