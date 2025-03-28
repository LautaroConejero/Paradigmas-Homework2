#include <iostream>
#include <string>
using namespace std;

class Numeros {
    protected:
    double resultado;
    public:
        Numeros();
        virtual double suma() = 0;
        virtual double resta() = 0;
        virtual double multiplicacion() = 0;
        virtual void Tostring() const;
}

class Num_entero : public Numeros {
    private:

    public:
        Num_entero();
        double suma() override;
        double resta() override;
        double multiplicacion() override;
        virtual void Tostring() const override;

}

class Num_real : public Numeros {
    private:

    public:
        Num_entero();
        double suma() override;
        double resta() override;
        double multiplicacion() override;
        virtual void Tostring() const override;

}

class Num_complejo : public Numeros {
    private:

    public:
        Num_entero();
        double suma() override;
        double resta() override;
        double multiplicacion() override;
        virtual void Tostring() const override;

}