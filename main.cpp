#include "Ej_1/Tiempos.cpp"
#include "Ej_2/Cursos.cpp"
int main(){
    cout << "Bienvenido al Homework 2";
    cout << "Elija el ejercicio a ejecutar:" << endl;
    cout << "1. Ejercicio 1" << endl;
    cout << "2. Ejercicio 2" << endl;
    cout << "3. Ejercicio 3" << endl;
    cout << "4. Ejercicio 4" << endl;
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
            consola_tiempo();
            break;
        }
        case 2:{
            consola_cursos();
            break;
        }
        case 3:{
            consola_cursos();
            break;
        }
        case 4:{
            consola_cursos();
            break;
        }
        case 5:{
            break;
        }
    }
    return 0;
}