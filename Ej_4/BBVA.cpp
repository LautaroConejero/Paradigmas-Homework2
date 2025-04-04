#include "BBVA.hpp"


Banco::Banco(string titular, double saldo):
    TitularCuenta(titular), balance(saldo) {}
void Banco::Depositar(double monto){
    balance += monto;
    cout << "Se ha depositado el monto solicitado" << endl;
    cout << " El saldo actual es: " << balance << endl;
    return;
}

CajaDeAhorro::CajaDeAhorro(string titular, double saldo):
    Banco(titular, saldo), contador_mostrar(0) {}
void CajaDeAhorro::Retirar(double monto){
    if (monto > balance){
        cout << "No se puede retirar el monto solicitado" << endl;
        return;
    }
    balance -= monto;
    cout << "Se ha retirado el monto solicitado" << endl;
    cout << " El saldo actual es: " << balance << endl;
    return;
}
void CajaDeAhorro::mostrarinfo(){
    cout << "Titular de la cuenta: " << TitularCuenta << endl;
    cout << "Saldo actual: " << balance << endl;
    cout << "Cantidad de veces que se ha mostrado la informacion: " << contador_mostrar << endl;
    contador_mostrar++;
    if (contador_mostrar > 2){
        if (balance < 20){
            balance = 0;
        }
        else{
            balance -= 20;
        }
        cout << "Se ha cobrado una comision de 20" << endl;
    }
    return;
}

CuentaCorriente::CuentaCorriente(string titular, double saldo, CajaDeAhorro* cuenta_ahorro):
    Banco(titular, saldo), cuenta_ahorro(cuenta_ahorro){}
void CuentaCorriente::Retirar(double monto){
    if (monto <= balance){
        balance -= monto;
        cout << "Se ha retirado el monto solicitado" << endl;
        cout << " El saldo actual es: " << balance << endl;
        return;
    }
    monto -= balance;
    if (cuenta_ahorro->balance < monto){
        cout << "No se puede retirar el monto solicitado" << endl;
        return;
    }
    balance = 0;
    cuenta_ahorro->balance -= monto;
    cout << "Se ha retirado el monto solicitado" << endl;
    cout << " El saldo actual es: " << balance << endl;
    cout << " El saldo de la cuenta de ahorro es: " << cuenta_ahorro->balance << endl;
    return;
}
void CuentaCorriente::mostrarinfo(){
    cout << "Titular de la cuenta: " << TitularCuenta << endl;
    cout << "Saldo actual: " << balance << endl;
}
