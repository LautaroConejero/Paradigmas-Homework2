#include <iostream>
#include <string>
using namespace std;

class Banco {
    protected:
        double balance;
        string TitularCuenta;
    public:
        Banco(string titular, double saldo);
        void Depositar(double monto);
        virtual void Retirar(double monto) = 0;
        virtual void mostrarinfo() const = 0;
};

class CajaDeAhorro : public Banco {
    private:
        int contador_mostrar;
    public:
        CajaDeAhorro(string titular, double saldo);
        void Retirar(double monto) override;
        void mostrarinfo() const override;
    friend class CuentaCorriente;
};

class CuentaCorriente : public Banco {
    private:
        CajaDeAhorro* cuenta_ahorro;
    public:
        CuentaCorriente(string titular, double saldo, CajaDeAhorro* cuenta_ahorro);
        void Retirar(double monto) override;
        void mostrarinfo() const override;
};

int Consola_BBVA();