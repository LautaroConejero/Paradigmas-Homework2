#include <iostream>
#include <string>
using namespace std;
#include <iomanip>

class Tiempos{
    private:
        int horas;
        int minutos;
        int segundos;
        string meridiem;
    public:
    Tiempos();
    Tiempos(int h);
    Tiempos(int h, int m);
    Tiempos(int h, int m, int s);
    Tiempos(int h, int m, int s, string mer);
    //~Tiempos();
    bool cheqReloj();
    void leerHora() const;
    void leerMinutos() const;
    void leerSegundos() const;
    void leerMeridiem() const;
    void leercompleto()  const;
    void leer_24() const;
    void setHoras(int h);
    void setMinutos(int m);
    void setSegundos(int s);
    void setMeridiem(string mer);
};
int consola();
