#include "Tiempos.hpp"

// limpia la terminal
void clear(){
    cout << "\033[2J\033[1;1H";
    return;
}

Tiempos::Tiempos():
    horas(0), minutos(0), segundos(0), meridiem("am"){}

Tiempos::Tiempos(int h):
    horas(h), minutos(0), segundos(0), meridiem("am"){}

Tiempos::Tiempos(int h, int m):
horas(h), minutos(m), segundos(0), meridiem("am"){}

Tiempos::Tiempos(int h, int m, int s):
horas(h), minutos(m), segundos(s), meridiem("am"){}

Tiempos::Tiempos(int h, int m, int s, string mer):
horas(h), minutos(m), segundos(s), meridiem(mer){}

bool Tiempos::cheqReloj(){
    if((horas < 0 || horas > 12 || minutos < 0 || minutos > 59 || segundos < 0 || segundos > 59) || (meridiem != "am" && meridiem != "pm")){
        return false;
    }
    return true;
}

void Tiempos::leerHora() const{
    cout << "Hora: " << horas << endl;
    return;
}
void Tiempos::leerMinutos() const{
    cout << "Minutos: " << minutos << endl;
    return;
}
void Tiempos::leerSegundos() const{
    cout << "Segundos: " << segundos << endl;
    return;
}
void Tiempos::leerMeridiem() const{
    cout << "Meridiem: " << meridiem << endl;
    return;
}
void Tiempos::leercompleto() const{
    cout << "El tiempo completo es: "<< horas<< "h " << minutos << "m " << segundos << "s " << meridiem << endl;
    return;
}
void Tiempos::leer_24() const{
    if(meridiem == "am"){
        cout << "El tiempo en formato 24 horas es: " << horas << "h " << minutos << "m " << segundos << "s" << endl;
    }else{
        cout << "El tiempo en formato 24 horas es: " << horas + 12 << "h " << minutos << "m " << segundos << "s" << endl;
    }
    return;
}
void Tiempos::setHoras(int h){
    horas = h;
    return;
}
void Tiempos::setMinutos(int m){
    minutos = m;
    return;
}
void Tiempos::setSegundos(int s){
    segundos = s;
    return;
}
void Tiempos::setMeridiem(string mer){
    meridiem = mer;
    return;
}

int consola_tiempo(){
    clear();
    cout<< "bienvenido al programa de tiempo" << endl;
    cout << "Como desear ingresar la hora?" << endl;
    cout << "1. Hora" << endl;
    cout << "2. Hora y minutos" << endl;
    cout << "3. Hora, minutos y segundos" << endl;
    cout << "4. Hora, minutos, segundos y meridiem" << endl;
    cout << "5. Valores Predeterminados" << endl;
    int opcion;
    cin >> opcion;
    while (opcion < 1 || opcion > 5){
        cout << "Opcion invalida, intente de nuevo" << endl;
        cin >> opcion;
    }
    Tiempos tiempo;
    clear();
    // switch (opcion){
    //     case 1 :{
    //         int h;
    //         cout << "Ingrese la hora: ";
    //         cin >> h;
    //         Tiempos tiempo(h);
    //         while (!tiempo.cheqReloj()){
    //             cout << "Hora invalida, intente de nuevo" << endl;
    //             cin >> h;
    //             tiempo.setHoras(h);
    //         }
    //         tiempo.leerHora();
    //         break;
    //     }
    //     case 2 :{
    //         int h, m;
    //         cout << "Ingrese la hora: ";
    //         cin >> h;
    //         cout << "Ingrese los minutos: ";
    //         cin >> m;
    //         Tiempos tiempo(h, m);
    //         while (!tiempo.cheqReloj()){
    //             cout << "tiempo invalida, intente de nuevo" << endl;
    //             cin >> h;
    //             tiempo.setHoras(h);
    //             cout << "Ingrese los minutos: ";
    //             cin >> m;
    //             tiempo.setMinutos(m);
    //             }
    //         }
    //         break;
    //     case 3 :{
    //         int h, m, s;
    //         cout << "Ingrese la hora: ";
    //         cin >> h;
    //         cout << "Ingrese los minutos: ";
    //         cin >> m;
    //         cout << "Ingrese los segundos: ";
    //         cin >> s;
    //         Tiempos tiempo(h, m, s);
    //         while (!tiempo.cheqReloj()){
    //             cout << "tiempo invalida, intente de nuevo" << endl;
    //             cin >> h;
    //             tiempo.setHoras(h);
    //             cout << "Ingrese los minutos: ";
    //             cin >> m;
    //             tiempo.setMinutos(m);
    //             cout << "Ingrese los segundos: ";
    //             cin >> s;
    //             tiempo.setSegundos(s);
    //         }
    //         break;
    //     }
    //     case 4: {
    //         int h, m, s;
    //         string mer;
    //         cout << "Ingrese la hora: ";
    //         cin >> h;
    //         cout << "Ingrese los minutos: ";
    //         cin >> m;
    //         cout << "Ingrese los segundos: ";
    //         cin >> s;
    //         cout << "Ingrese el meridiem: ";
    //         cin >> mer;
    //         Tiempos tiempo(h, m, s, mer);
    //         while (!tiempo.cheqReloj()){
    //             cout << "tiempo invalida, intente de nuevo" << endl;
    //             cin >> h;
    //             tiempo.setHoras(h);
    //             cout << "Ingrese los minutos: ";
    //             cin >> m;
    //             tiempo.setMinutos(m);
    //             cout << "Ingrese los segundos: ";
    //             cin >> s;
    //             tiempo.setSegundos(s);
    //             cout << "Ingrese el meridiem: ";
    //             cin >> mer;
    //             tiempo.setMeridiem(mer);
    //         }
    //         break;
    //     }
    //     case 5: {
    //         Tiempos tiempo;
    //         break;
    //     }

    // }
//    clear();
    while(true){
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
                tiempo.leerHora();
                break;
            }
            case 2:{
                tiempo.leerMinutos();
                break;
            }
            case 3:{
                tiempo.leerSegundos();
                break;
            }
            case 4:{
                tiempo.leerMeridiem();
                break;
            }
            case 5:{
                tiempo.leercompleto();
                break;
            }
            case 6:{
                tiempo.leer_24();
                break;
            }
            case 7:{
                int h;
                cout << "Ingrese la hora: ";
                cin >> h;
                tiempo.setHoras(h);
                while (!tiempo.cheqReloj()){
                    cout << "Hora invalida, intente de nuevo" << endl;
                    cin >> h;
                    tiempo.setHoras(h);
                }
                break;
            }
            case 8:{
                int m;
                cout << "Ingrese los minutos: ";
                cin >> m;
                tiempo.setMinutos(m);
                while (!tiempo.cheqReloj()){
                    cout << "Minutos invalida, intente de nuevo" << endl;
                    cin >> m;
                    tiempo.setMinutos(m);
                }
                break;
            }
            case 9:{
                int s;
                cout << "Ingrese los segundos: ";
                cin >> s;
                tiempo.setSegundos(s);
                while (!tiempo.cheqReloj()){
                    cout << "Minutos invalida, intente de nuevo" << endl;
                    cin >> s;
                    tiempo.setSegundos(s);
                }
            }
            case 10:{
                string mer;
                cout << "Ingrese el meridiem: ";
                cin >> mer;
                tiempo.setMeridiem(mer);
                while (!tiempo.cheqReloj()){
                    cout << "Meridiem invalida, intente de nuevo" << endl;
                    cin >> mer;
                    tiempo.setMeridiem(mer);
                }
                break;
            }
            case 11:{
                return 0;
            }
        }    
    }
    return 0;
}