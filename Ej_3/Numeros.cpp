#include "Numeros.hpp"

Numero::Numero(float v) : valor(v) {}
Numero* Numero::suma(Numero* n) {
    return new Numero(this->valor + n->valor);
}
Numero* Numero::resta(Numero* n) {
    return new Numero(this->valor - n->valor);
}
Numero* Numero::multiplicacion(Numero* n) {
    return new Numero(this->valor * n->valor);
}
string Numero::Tostring() const {
    return "Valor: " + to_string(valor);
}

Num_entero::Num_entero(float v) : Numero(v) {}
Num_real::Num_real(float v) : Numero(v) {}

Num_complejo::Num_complejo(float v, float i) : Numero(v), imaginario(i) {}
Numero* Num_complejo::suma(Numero* n) {
    Num_complejo* n_C= dynamic_cast<Num_complejo*>(n);
    float real = this->valor + n_C->valor;
    if (n_C->imaginario == 0){
        return new Num_complejo(real, this->imaginario);
    }
    float imaginario = this->imaginario + n_C->imaginario;
    return new Num_complejo(real, imaginario);
}
Numero* Num_complejo::resta(Numero* n) {
    Num_complejo* n_C = dynamic_cast<Num_complejo*>(n);
    float real = this->valor - n_C->valor;
    if (n_C->imaginario == 0){
        return new Num_complejo(this->valor, this->imaginario);
    }

    float imaginario = this->imaginario - n_C->imaginario;
    return new Num_complejo(real, imaginario);
}
Numero* Num_complejo::multiplicacion(Numero* n) {
    Num_complejo* n_C = dynamic_cast<Num_complejo*>(n);
    if (n_C->imaginario == 0){
        float real = this->valor * n_C->valor;
        float imaginario = this->imaginario * n_C->valor;
        return new Num_complejo(real, imaginario);
    }
    
    float valor = this->valor * n_C->valor - this->imaginario * n_C->imaginario;
    float imaginario = this->valor * n_C->imaginario + this->imaginario * n_C->valor;
    return new Num_complejo(this->valor, this->imaginario);
} 
string Num_complejo::Tostring() const {
    return "Parte real: " + to_string(valor) + ", Parte imaginaria: " + to_string(imaginario);
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

int Consola_Numeros(){
    cout << "Bienvenido al programa de numeros" << endl;
    vector<Numero*> numeros_activos;
    while (true){
        cout << endl;
        cout << "Ingrese el tipo de numero que desea crear:" << endl;
        cout << "1. Numero entero" << endl;
        cout << "2. Numero real" << endl;
        cout << "3. Numero complejo" << endl;
        cout << "4. Trabajar con los numeros existentes" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: ";
        int opcion;
        cin >> opcion;
        while (opcion < 1 || opcion > 5){
            cout << "Opcion invalida, intente de nuevo" << endl;
            cout << "Opcion: ";
            cin >> opcion;  
        }
        clear();
        float valor;
        switch (opcion)
        {
            case 1:{
                cout << "Ingrese el valor del numero entero: ";
                cin >> valor;
                Num_entero* n_e = new Num_entero(valor);
                numeros_activos.push_back(n_e);
                break;
            }
            case 2:{
                cout << "Ingrese el valor del numero real: ";
                cin >> valor;
                Num_real* n_r = new Num_real(valor);
                numeros_activos.push_back(n_r);
                break;
            }
            case 3:{
                cout << "Ingrese la parte real del numero complejo: ";
                cin >> valor;
                float imaginario;
                cout << "Ingrese la parte imaginaria del numero complejo: ";
                cin >> imaginario;
                Num_complejo* n_C = new Num_complejo(valor, imaginario);
                numeros_activos.push_back(n_C);
                break;
            }
            case 4:{
                if (numeros_activos.size() <= 1){
                    cout << "No tienes numeros suficientes para trabajar" << endl;
                    break;
                }
                operaciones(numeros_activos);
            break;    
            }
            case 5:{
                cout << "Gracias por utilizar el programa de numeros" << endl;
                for (int i = 0; i < numeros_activos.size(); i++){
                    delete numeros_activos[i];
                }
                return 0;
            }
        }
    }
}
