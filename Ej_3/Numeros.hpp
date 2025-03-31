#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;
#ifndef NUMEROS_HPP
#define NUMEROS_HPP
class Numero {
    public:
        virtual Numero* suma(Numero* n) = 0;
        virtual Numero* resta(Numero* n) = 0;
        virtual Numero* multiplicacion(Numero* n) = 0;
        virtual string Tostring() const = 0;
};

class Num_entero : public Numero {
    private:
        int entero;
    public:
        Num_entero(int v);
        Numero* suma(Numero* n_E) override;
        Numero* resta(Numero* n_E) override;
        Numero* multiplicacion(Numero* n_E) override;
        virtual string Tostring() const override;
};

class Num_real : public Numero {
    private:
        float real;
    public:
        Num_real(float v);
        Numero* suma(Numero* n_R) override;
        Numero* resta(Numero* n_R) override;
        Numero* multiplicacion(Numero* n_R) override;
        virtual string Tostring() const override;
};

class Num_complejo : public Numero {
    private:
        float imaginario;
        float real;
    public:
        Num_complejo(float v, float i);
        Numero* suma(Numero* n_C) override;
        Numero* resta(Numero* n_C) override;
        Numero* multiplicacion(Numero* n_C) override;
        virtual string Tostring() const override;

};
void operaciones(vector<Numero*>& numeros_activos);
void borar_numeros(vector<Numero*>& numeros_activos);
int Consola_Numeros();
void clear();
#endif
