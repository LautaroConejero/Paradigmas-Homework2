#include "BBVA.hpp"

Banco::Banco(string titular, double saldo):
    TitularCuenta(titular), balance(saldo) {}
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
void CajaDeAhorro::mostrarinfo() const{
    cout << "Titular de la cuenta: " << TitularCuenta << endl;
    cout << "Saldo actual: " << balance << endl;
    cout << "Cantidad de veces que se ha mostrado la informacion: " << contador_mostrar << endl;
    contador_mostrar++;
    if (contador_mostrar > 2){
        if (balance < 20){
            balance = 0;
        }
        balance -= 20;
        cout << "Se ha cobrado una comision de 20" << endl;
    }
    return;
}
void CuentaCorriente::CuentaCorriente(string titular, double saldo, CajaDeAhorro* cuenta_ahorro):
    Banco(titular, saldo), cuenta_ahorro(*cuenta_ahorro){}
void CuentaCorriente::Retirar(double monto){
    if (monto <= balance){
        balance -= monto;
        cout << "Se ha retirado el monto solicitado" << endl;
        cout << " El saldo actual es: " << balance << endl;
        return;
    }
    monto -= balance;
    if (CajaDeAhorro::balance < monto){
        cout << "No se puede retirar el monto solicitado" << endl;
        return;
    }
    balance = 0;
}
void CuentaCorriente::mostrarinfo() const{
    cout << "Titular de la cuenta: " << TitularCuenta << endl;
    cout << "Saldo actual: " << balance << endl;
}

int Consola_BBVA(){
    clear();
    cout << "Bienvenido al banco BBVA" << endl;
    cout 
    cout << "Creando tu caja de ahorros..."
    string titular;
    double saldo;
    cout << "Ingrese el nombre completo del titular: ";
    cin.ignore();
    getline(cin, titular);
    cout << "Ingrese el saldo tu banco: ";
    cin >> saldo;
    while (saldo < 0){
        cout << "El saldo no puede ser negativo, intente de nuevo" << endl;
        cout << "Ingrese el saldo tu banco: ";
        cin >> saldo; 
    }
    CajaDeAhorro cuenta(titular, saldo);
    cout << "Tienes una cuenta corriente? (S/N): ";
    char respuesta;
    cin >> respuesta;
    while (respuesta != 'S' && respuesta != 'N'){
        cout << "Respuesta invalida, intente de nuevo" << endl;
        cout << "Tienes una cuenta corriente? (S/N): ";
        cin >> respuesta; 
    }
    

}

