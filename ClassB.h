#ifndef CLASSB_H
#define CLASSB_H
#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;

class ClassB
{
private:
  friend class ClassA;
  double doble;
  bool bul;
public:
  ClassB(){}

  ClassB(double doble, bool bul)
  {
      this->doble = doble;
      this->bul = bul;

  }

  ClassB(char* s)
  {
      int k = 0;
      string cadenaAux = "";
      for(int i=0 ; i<sizeof (double) ; i++, k++)
          ((char*)&doble)[i] = s[k];
      doble = stod(cadenaAux);

      for(int i=0 ; i<sizeof (bool) ; i++, k++)
          ((char*)&bul)[i] = s[k];
      bul = stoi(cadenaAux);

  }

  string toString()
  {
      string out;

      out = '[';
      out += to_string(doble);
      out += to_string(bul) + ']';

      return out;
  }
};

#endif // CLASSB_H
