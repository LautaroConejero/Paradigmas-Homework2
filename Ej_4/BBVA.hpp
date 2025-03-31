#include <iostream>
#include <string>
using namespace std;
#ifndef BBVA_HPP
#define BBVA_HPP

// Para el banco es simple, es protected asi las clasaes "hijas" pueden acceder a los atributos de la clase padre, pero no al reves
// el resto es publica porque son funciones que se pueden usar desde afuera de la clase
// Ahora en la Cuenta corriente, la caja de ahorro es privada porque no quiero que se pueda acceder a ella desde afuera de la clase, solo desde la cuenta corriente
class Banco {
    protected:
        double balance;
        string TitularCuenta;
    public:
        Banco(string titular, double saldo);
        void Depositar(double monto);
        virtual void Retirar(double monto) = 0;
        virtual void mostrarinfo() = 0;
};

class CajaDeAhorro : public Banco {
    private:
        int contador_mostrar;
    public:
        CajaDeAhorro(string titular, double saldo);
        void Retirar(double monto) override;
        void mostrarinfo() override;
    friend class CuentaCorriente;
};

class CuentaCorriente : public Banco {
    private:
        CajaDeAhorro* cuenta_ahorro;
    public:
        CuentaCorriente(string titular, double saldo, CajaDeAhorro* cuenta_ahorro);
        void Retirar(double monto) override;
        void mostrarinfo() override;
};

int Consola_BBVA();
void clear();
#endif
