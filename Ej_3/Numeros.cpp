#include "Numeros.hpp"


Num_entero::Num_entero(int v) : entero(v) {}
Numero* Num_entero::suma(Numero* n) {
    Num_entero* n_E = dynamic_cast<Num_entero*>(n);
    int ent = this->entero + n_E->entero;
    return new Num_entero(ent);
}
Numero* Num_entero::resta(Numero* n) {
    Num_entero* n_E = dynamic_cast<Num_entero*>(n);
    int ent = this->entero - n_E->entero;
    return new Num_entero(ent);
}
Numero* Num_entero::multiplicacion(Numero* n) {
    Num_entero* n_E = dynamic_cast<Num_entero*>(n);
    int ent = this->entero * n_E->entero;
    return new Num_entero(ent);
}
string Num_entero::Tostring() const {
    return "Numero entero: " + to_string(entero);
}


Num_real::Num_real(float v) : real(v) {}

Numero* Num_real::suma(Numero* n) {
    Num_real* n_E = dynamic_cast<Num_real*>(n);
    float rl = this->real + n_E->real;
    return new Num_real(rl);
}
Numero* Num_real::resta(Numero* n) {
    Num_real* n_E = dynamic_cast<Num_real*>(n);
    float rl = this->real - n_E->real;
    return new Num_real(rl);
}
Numero* Num_real::multiplicacion(Numero* n) {
    Num_real* n_E = dynamic_cast<Num_real*>(n);
    float rl = this->real * n_E->real;
    return new Num_real(rl);
}
string Num_real::Tostring() const {
    return "Numero entero: " + to_string(real);
}


Num_complejo::Num_complejo(float v, float i) : real(v), imaginario(i) {}
Numero* Num_complejo::suma(Numero* n) {
    Num_complejo* n_C= dynamic_cast<Num_complejo*>(n);
    float rl = this->real + n_C->real;
    float im = this->imaginario + n_C->imaginario;
    return new Num_complejo(rl, im);
}
Numero* Num_complejo::resta(Numero* n) {
    Num_complejo* n_C = dynamic_cast<Num_complejo*>(n);
    float rl = this->real - n_C->real;
    float im = this->imaginario - n_C->imaginario;
    return new Num_complejo(rl, im);
}
Numero* Num_complejo::multiplicacion(Numero* n) {
    Num_complejo* n_C = dynamic_cast<Num_complejo*>(n);
    float rl = this->real * n_C->real - this->imaginario * n_C->imaginario;
    float im = this->real * n_C->imaginario + this->imaginario * n_C->real;
    return new Num_complejo(rl, im);
} 
string Num_complejo::Tostring() const {
    return "Parte real: " + to_string(real) + ", Parte imaginaria: " + to_string(imaginario);
}


void operaciones(vector<Numero*>& numeros_activos){
    cout << "Que desea hacer?" << endl;
    cout << "1. Sumar" << endl;
    cout << "2. Restar" << endl;
    cout << "3. Multiplicar" << endl;
    cout << "Opcion: ";
    int operacion;
    cin >> operacion;
    while (operacion < 1 || operacion > 3){
        cout << "Opcion invalida, intente de nuevo" << endl;
        cout << "Opcion: ";
        cin >> operacion;  
    }
    clear();
    cout << "Seleccione los numeros con los que desea trabajar: " << endl;
    vector<Numero*> numeros_seleccionados;
    while (true){
        for (int i = 0; i < numeros_activos.size(); i++){
            cout << i << ". " << numeros_activos[i]->Tostring() << endl;
        }
        cout << "Opcion: ";
        int numero_seleccionado;
        cin >> numero_seleccionado;
        while (numero_seleccionado < 0 || numero_seleccionado >= numeros_activos.size()){
            cout << "Opcion invalida, intente de nuevo" << endl;
            cout << "Opcion: ";
            cin >> numero_seleccionado;  
        }
        numeros_seleccionados.push_back(numeros_activos[numero_seleccionado]);
        cout << "Desea seleccionar otro numero? (s): ";
        char respuesta;
        cin >> respuesta;
        if (respuesta != 's'){
            break;
        }
    }
    Numero* temp = numeros_seleccionados[0];
    for (int i = 1; i < numeros_seleccionados.size(); i++){
        if (operacion == 1){
            temp = temp->suma(numeros_seleccionados[i]);
        }else if (operacion == 2){
            temp = temp->resta(numeros_seleccionados[i]);
        }else if (operacion == 3){
            temp = temp->multiplicacion(numeros_seleccionados[i]);
        }
    }
    numeros_activos.push_back(temp);
    cout << "El resultado de la operacion es: " << temp->Tostring() << endl;
    return;
}

void borar_numeros(vector<Numero*>& numeros_activos){
    for (int i = 0; i < numeros_activos.size(); i++){
        delete numeros_activos[i];
    }
    numeros_activos.clear();
}
int Consola_Numeros(){
    cout << "Bienvenido al programa de numeros" << endl;
    vector<Numero*> numeros_real;
    vector<Numero*> numeros_entero;
    vector<Numero*> numeros_complejo;
    while (true){
        cout << endl;
        cout << "Elija el tipo de numero que quieras trabajar:" << endl;
        cout << "1. Numero entero" << endl;
        cout << "2. Numero real" << endl;
        cout << "3. Numero complejo" << endl;
        cout << "4. Salir" << endl;
        cout << "Opcion: ";
        int opcion;
        cin >> opcion;
        while (opcion < 1 || opcion > 4){
            cout << "Opcion invalida, intente de nuevo" << endl;
            cout << "Opcion: ";
            cin >> opcion;  
        }
        clear();
        switch (opcion){
            case 1:{
                cout << "1. Ingresar un valor"<< endl;
                cout << "2. Realizar operaciones" << endl;
                cout << "Opcion: ";
                int sub_opcion;
                cin >> sub_opcion;
                while (sub_opcion < 1 || sub_opcion > 2){
                    cout << "Opcion invalida, intente de nuevo" << endl;
                    cout << "Opcion: ";
                    cin >> sub_opcion;  
                }
                if (sub_opcion == 2){
                    operaciones(numeros_entero);
                    break;
                }
                int valor;
                cout << "Ingrese el valor del numero entero: ";
                cin >> valor;
                Num_entero* n_e = new Num_entero(valor);
                numeros_entero.push_back(n_e);
                clear();
                break;
            }
            case 2:{
                cout << "1. Ingresar un valor"<< endl;
                cout << "2. Realizar operaciones" << endl;
                cout << "Opcion: ";
                int sub_opcion;
                cin >> sub_opcion;
                while (sub_opcion < 1 || sub_opcion > 2){
                    cout << "Opcion invalida, intente de nuevo" << endl;
                    cout << "Opcion: ";
                    cin >> sub_opcion;  
                }
                if (sub_opcion == 2){
                    operaciones(numeros_real);
                    break;
                }
                float valor;
                cout << "Ingrese el valor del numero real: ";
                cin >> valor;
                Num_real* n_r = new Num_real(valor);
                numeros_real.push_back(n_r);
                clear();
                break;
            }
            case 3:{
                cout << "1. Ingresar un valor"<< endl;
                cout << "2. Realizar operaciones" << endl;
                cout << "Opcion: ";
                int sub_opcion;
                cin >> sub_opcion;
                while (sub_opcion < 1 || sub_opcion > 2){
                    cout << "Opcion invalida, intente de nuevo" << endl;
                    cout << "Opcion: ";
                    cin >> sub_opcion;  
                }
                if (sub_opcion == 2){
                    operaciones(numeros_complejo);
                    break;
                }
                float valor;
                cout << "Ingrese la parte real del numero complejo: ";
                cin >> valor;
                float imaginario;
                cout << "Ingrese la parte imaginaria del numero complejo: ";
                cin >> imaginario;
                Num_complejo* n_C = new Num_complejo(valor, imaginario);
                numeros_complejo.push_back(n_C);
                clear();
                break;
            }
            case 4:{
                cout << "Gracias por utilizar el programa de numeros" << endl;
                borar_numeros(numeros_real);
                borar_numeros(numeros_entero);
                borar_numeros(numeros_complejo);
                return 0;
            }
        }
    }
}
