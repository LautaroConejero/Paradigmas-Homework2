#include "Tiempos.hpp"

// limpia la terminal
void clear(){
    cout << "\033[2J\033[1;1H";
    return;
}
Tiempos::Tiempos(int h, int m, int s, string mer):
horas(h), minutos(m), segundos(s), meridiem(mer){}

void Tiempos::get_Hora() const{
    cout << "Hora: " << horas << endl;
    return;
}
void Tiempos::get_Minutos() const{
    cout << "Minutos: " << minutos << endl;
    return;
}
void Tiempos::get_Segundos() const{
    cout << "Segundos: " << segundos << endl;
    return;
}
void Tiempos::get_Meridiem() const{
    cout << "Meridiem: " << meridiem << endl;
    return;
}
void Tiempos::get_completo() const{
    cout << "El tiempo completo es: "<< horas<< "h " << minutos << "m " << segundos << "s " << meridiem << endl;
    return;
}
void Tiempos::get__24() const{
    if(meridiem == "am" && horas != 12){
        cout << "El tiempo en formato 24 horas es: " << horas << "h " << minutos << "m " << segundos << "s" << endl;
    }else{
        cout << "El tiempo en formato 24 horas es: " << (horas + 12)%24 << "h " << minutos << "m " << segundos << "s" << endl;
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
bool Tiempos::verificar_hora(){
    while (horas < 1 || horas > 12){
        int h;
        cout << "Hora invalida, intente de nuevo" << endl;
        if (salir_programa()) return false;
        clear();
        cout << "ingrese nuevamente: ";
        cin >> h;
        setHoras(h);
    }
    return true;
}
bool Tiempos::verificar_minuto(){
    while (minutos < 0 || minutos > 59){
        int m;
        cout << "minuto invalida, intente de nuevo" << endl;
        if (salir_programa()) return false;
        cout << "ingrese nuevamente: ";
        cin >> m;
        setMinutos(m);
    }
    return true;
}
bool Tiempos::verificar_segundo(){
    while (segundos < 0 || segundos > 59){
        int s;
        cout << "segundo invalida, intente de nuevo" << endl;
        if (salir_programa()) return false;
        cout << "ingrese nuevamente: ";
        cin >> s;
        setSegundos(s);
    }
    return true;
}
bool Tiempos::verificar_meridiem(){
    while (meridiem != "am" && meridiem != "pm"){
        string mer;
        cout << "meridiem invalida, intente de nuevo" << endl;
        if (salir_programa()) return false;
        cout << "ingrese nuevamente: ";
        cin >> mer;
        setMeridiem(mer);
    }
    return true;
}
bool salir_programa(){
    cout << "Estas deseando salir? si tu respuesta es Si, ingrese 1: ";
    int salir;
    cin >> salir;
    if (salir == 1) return true;
    return false;
}
int consola_tiempo(){
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
    if (!tiempo.verificar_hora()) return 0;
    if (!tiempo.verificar_minuto()) return 0;
    if (!tiempo.verificar_segundo()) return 0;
    if (!tiempo.verificar_meridiem()) return 0;
    clear();
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
                return 0;
            }
        }    
    }
    return 0;
}