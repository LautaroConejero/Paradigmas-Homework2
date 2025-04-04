#include "consola_tiempos.hpp"

int Consola_Tiempo(){
    clear();
    cout<< "bienvenido al programa de tiempo" << endl;
    cout << "Como desear ingresar la hora?" << endl;
    cout << "1. Valores Predeterminados" << endl;
    cout << "2. Hora" << endl;
    cout << "3. Hora y minutos" << endl;
    cout << "4. Hora, minutos y segundos" << endl;
    cout << "5. Hora, minutos, segundos y meridiem" << endl;
    int opcion;
    cin >> opcion;
    while (opcion < 1 || opcion > 5){
        cout << "Opcion invalida, intente de nuevo" << endl;
        cin >> opcion;
    }
    int hora = 12, minuto = 0, segundo = 0;
    string meridiem = "am";

    if (opcion >= 2){
        cout << "Ingrese el valor de la hora: ";
        cin >> hora;
        if (opcion >= 3){
            cout << "Ingrese el valor de los minutos: ";
            cin >> minuto;
            if (opcion >= 4){
                cout << "Ingrese el valor de los segundos: ";
                cin >> segundo;
                if (opcion == 5){
                    cout << "Ingrese el meridiem: ";
                    cin >> meridiem;
                }
            }
        }
    }
    Tiempos tiempo(hora, minuto, segundo, meridiem);
    clear();
    while(true){
        cout << endl;
        cout << "Con que deseas continuar"<< endl;
        cout << "1. Leer la hora\n2. Leer los minutos\n3. Leer los segundos\n4. Leer el meridiem\n5. Leer el tiempo completo\n6. Leer el tiempo en formato 24 horas\n7. Cambiar la hora\n8. Cambiar los minutos\n9. Cambiar los segundos\n10. Cambiar el meridiem\n11. Salir" << endl;
        int eleccion;
        cin >> eleccion;
        while (eleccion < 1 || eleccion > 11){
            cout << "Opcion invalida, intente de nuevo" << endl;
            cin >> eleccion;
        }
        clear();
        switch(eleccion){
            case 1:{
                tiempo.get_Hora();
                break;
            }
            case 2:{
                tiempo.get_Minutos();
                break;
            }
            case 3:{
                tiempo.get_Segundos();
                break;
            }
            case 4:{
                tiempo.get_Meridiem();
                break;
            }
            case 5:{
                tiempo.get_completo();
                break;
            }
            case 6:{
                tiempo.get__24();
                break;
            }
            case 7:{
                int h;
                cout << "Ingrese la hora: ";
                cin >> h;
                tiempo.setHoras(h);
                if (!tiempo.verificar_hora()) return 0;
                break;
            }
            case 8:{
                int m;
                cout << "Ingrese los minutos: ";
                cin >> m;
                tiempo.setMinutos(m);
                if (!tiempo.verificar_minuto()) return 0;
                break;
            }
            case 9:{
                int s;
                cout << "Ingrese los segundos: ";
                cin >> s;
                tiempo.setSegundos(s);
                if (!tiempo.verificar_segundo()) return 0;
                break;
            }
            case 10:{
                string mer;
                cout << "Ingrese el meridiem: ";
                cin >> mer;
                tiempo.setMeridiem(mer);
                if (!tiempo.verificar_meridiem()) return 0;
                break;
            }
            case 11:{
                cout << "Gracias por utilizar el programa de tiempo" << endl;
                return 0;
            }
        }    
    }
    return 0;
}