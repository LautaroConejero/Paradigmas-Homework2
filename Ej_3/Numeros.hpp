#include <iostream>
#include <string>
using namespace std;

class Numero {
    protected:
        float valor;
    public:
        Numero(float v);
        virtual Numero* suma(Numero* n);
        virtual Numero* resta(Numero* n);
        virtual Numero* multiplicacion(Numero* n);
        virtual string Tostring() const;
};

class Num_entero : public Numero {
    public:
        Num_entero(float v);
};

class Num_real : public Numero {
    public:
        Num_real(float v);
};

class Num_complejo : public Numero {
    private:
        float imaginario;
    public:
        Num_complejo(float v, float i);
        Numero* suma(Num_complejo* n_C) override;
        Numero* resta(Num_complejo* n_C) override;
        Numero* multiplicacion(Num_complejo* n_C) override;
        virtual string Tostring() const override;

};
void operaciones(vector<Numero*>& numeros_activos);
int consola_numeros();