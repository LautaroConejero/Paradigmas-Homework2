#include "Ej_1/Tiempos.cpp"
#include "Ej_2/Cursos.cpp"
#include "Ej_3/Numeros.cpp"
#include "Ej_4/BBVA.cpp"
int main(){
    cout << "Bienvenido al Homework 2"<< endl;
    cout << "Elija el ejercicio a ejecutar:" << endl;
    cout << "1. Simulacro de Reloj" << endl;
    cout << "2. Simulacro de cursos" << endl;
    cout << "3. Simulacro de Numeros" << endl;
    cout << "4. Simulacro de cuenta bancaria" << endl;
    cout << "5. Salir" << endl;
    int eleccion;
    cin >> eleccion;
    while (eleccion < 1 || eleccion > 5){
        cout << "Opcion invalida, intente de nuevo" << endl;
        cin >> eleccion;
    }
    clear();
    switch(eleccion){
        case 1:{
            Consola_Tiempo();
            break;
        }
        case 2:{
            Consola_Cursos();
            break;
        }
        case 3:{
            Consola_Numeros();
            break;
        }
        case 4:{
            Consola_BBVA();
            break;
        }
        case 5:{
            break;
        }
    }
    return 0;
}