#include "Consola_banco.hpp"
int Consola_BBVA(){
    clear();
    cout << "Bienvenido al banco BBVA" << endl; 
    cout << "Creando tu caja de ahorros..."<< endl;
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

    cout << "Creando tu cuenta corriente..." << endl;
    string titular_cuenta_corriente;
    double saldo_cuenta_corriente;
    cout << "Ingrese el nombre completo del titular de la cuenta corriente: ";
    cin.ignore();
    getline(cin, titular_cuenta_corriente);
    cout << "Ingrese el saldo de la cuenta corriente: ";
    cin >> saldo_cuenta_corriente;
    while (saldo_cuenta_corriente < 0){
        cout << "El saldo no puede ser negativo, intente de nuevo" << endl;
        cout << "Ingrese el saldo de la cuenta corriente: ";
        cin >> saldo_cuenta_corriente; 
    }
    CuentaCorriente cuenta_corriente(titular_cuenta_corriente, saldo_cuenta_corriente, &cuenta);
    
    clear();
    cout << "Bienvenido al sistema de ayuda del banco BBVA" << endl;
    while(true){
        cout << "En que cuenta bancaria quieres trabajar?" << endl;
        cout << "1. Caja de ahorros" << endl;
        cout << "2. Cuenta corriente" << endl;
        cout << "3. Salir" << endl;
        cout << "Opcion: ";
        int cuenta_elegida;
        cin >> cuenta_elegida;
        while (cuenta_elegida < 1 || cuenta_elegida > 3){
            cout << "Opcion invalida, intente de nuevo" << endl;
            cout << "Opcion: ";
            cin >> cuenta_elegida;  
        }
        if (cuenta_elegida == 3){
            clear();
            cout << "Gracias por usar el sistema de ayuda del banco BBVA" << endl;
            return 0;
        }
        clear();

        cout << "Que accion desea hacer?" << endl;
        cout << "1. Depositar" << endl;
        cout << "2. Retirar" << endl;
        cout << "3. Mostrar informacion de la cuenta" << endl;
        cout << "Opcion: ";
        int eleccion;
        cin >> eleccion;
        while (eleccion < 1 || eleccion > 3){
            cout << "Opcion invalida, intente de nuevo" << endl;
            cout << "Opcion: ";
            cin >> eleccion;  
        }
        clear();

        switch (eleccion){
            case 1:{
                double monto;
                cout << "Ingrese el monto a depositar: ";
                cin >> monto;
                while (monto < 0){
                    cout << "El monto no puede ser negativo, intente de nuevo" << endl;
                    cout << "Ingrese el monto a depositar: ";
                    cin >> monto; 
                }
                clear();
                if (cuenta_elegida == 1){
                    cuenta.Depositar(monto);
                }else{
                    cuenta_corriente.Depositar(monto);
                }
                break;
            }
            case 2:{
                double monto;
                cout << "Ingrese el monto a retirar: ";
                cin >> monto;
                while (monto < 0){
                    cout << "El monto no puede ser negativo, intente de nuevo" << endl;
                    cout << "Ingrese el monto a retirar: ";
                    cin >> monto; 
                }
                clear();
                if (cuenta_elegida == 1){
                    cuenta.Retirar(monto);
                }else{
                    cuenta_corriente.Retirar(monto);
                }
                break;
            }
            case 3:{
                clear();
                if (cuenta_elegida == 1){
                    cuenta.mostrarinfo();
                }else{
                    cuenta_corriente.mostrarinfo();
                }
                break;
            }
        }
    }
}

