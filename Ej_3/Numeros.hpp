#ifndef NUMEROS_HPP
#define NUMEROS_HPP
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Numero {
    public:
        virtual shared_ptr<Numero> suma(shared_ptr<Numero>& n) = 0;
        virtual shared_ptr<Numero> resta(shared_ptr<Numero>& n) = 0;
        virtual shared_ptr<Numero> multiplicacion(shared_ptr<Numero>& n) = 0;
        virtual string Tostring() const = 0;
};

class Num_entero : public Numero {
    private:
        int entero;
    public:
        Num_entero(int v);
        shared_ptr<Numero> suma(shared_ptr<Numero>& n_E) override;
        shared_ptr<Numero> resta(shared_ptr<Numero>& n_E) override;
        shared_ptr<Numero> multiplicacion(shared_ptr<Numero>& n_E) override;
        virtual string Tostring() const override;
};

class Num_real : public Numero {
    private:
        float real;
    public:
        Num_real(float v);
        shared_ptr<Numero> suma(shared_ptr<Numero>& n_R) override;
        shared_ptr<Numero> resta(shared_ptr<Numero>& n_R) override;
        shared_ptr<Numero> multiplicacion(shared_ptr<Numero>& n_R) override;
        virtual string Tostring() const override;
};

class Num_complejo : public Numero {
    private:
        float imaginario;
        float real;
    public:
        Num_complejo(float v, float i);
        shared_ptr<Numero> suma(shared_ptr<Numero>& n_C) override;
        shared_ptr<Numero> resta(shared_ptr<Numero>& n_C) override;
        shared_ptr<Numero> multiplicacion(shared_ptr<Numero>& n_C) override;
        virtual string Tostring() const override;

};
#endif
