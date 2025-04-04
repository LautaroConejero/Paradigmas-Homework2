#include "Tiempos.hpp"

Tiempos::Tiempos(int h, int m, int s, string mer):
horas(h), minutos(m), segundos(s), meridiem(mer){
    verificar_hora();
    verificar_minuto();
    verificar_segundo();
    verificar_meridiem();
}

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
        cout << "ingrese nuevamente la hora: ";
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
        cout << "ingrese nuevamente los minutos: ";
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
        cout << "ingrese nuevamente los segundos: ";
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
        cout << "ingrese nuevamente el meridiem: ";
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