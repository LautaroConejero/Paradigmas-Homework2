#include <iostream>
#include <string>
using namespace std;

class Numeros {
    protected:
    double resultado;
    public:
        Numeros(){}
        virtual double suma() = 0;
        virtual double resta() = 0;
        virtual double multiplicacion() = 0;
}

class Num_entero : publ