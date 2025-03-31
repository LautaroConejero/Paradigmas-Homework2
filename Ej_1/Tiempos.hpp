#include <iostream>
#include <string>
using namespace std;
#include <iomanip>
#ifndef TIEMPOS_HPP
#define TIEMPOS_HPP
class Tiempos{
    private:
        int horas;
        int minutos;
        int segundos;
        string meridiem;
    public:
    Tiempos(int h, int m, int s, string mer);
    void get_Hora() const;
    void get_Minutos() const;
    void get_Segundos() const;
    void get_Meridiem() const;
    void get_completo()  const;
    void get__24() const;
    void setHoras(int h);
    void setMinutos(int m);
    void setSegundos(int s);
    void setMeridiem(string mer);
    bool verificar_hora();
    bool verificar_minuto();
    bool verificar_segundo();
    bool verificar_meridiem();
};
bool salir_programa();
int Consola_Tiempo();
void clear();
#endif 