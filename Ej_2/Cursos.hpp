#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;
class Estudiante;

class Curso{
    private:
        vector<Estudiante> estudiantes;
        string nombre;
    public:
        Curso(string n);
        string getNombre() const;
        bool agregarEstudiante(Estudiante* e);
        void eliminarEstudiante(int legajo);
        bool existeEstudiante(int legajo) const;
        int getCantidadEstudiantes() const;
        bool Esta_completo() const;
        void imprimirEstudiantes_alfabeticamente() const;
};
class Estudiante{
    private:
        string nombre;
        string apellido;
        int legajo;
        float promedio;
        vector<pair<Curso, float>> cursos; 
    public:
        Estudiante(string n, string a, int e);
        string getApellido() const; 
        string getNombre_completo() const;
        int getLegajo() const;
        float getPromedio() const;
        void agregarCurso(Curso* c, float calificacion); 
        void eliminarCurso(Curso* c); 
        void CalcularPromedio();
        bool operator<(const Estudiante& estudiante) const; 
        void operator<<(const Estudiante& estudiante);
};

int consola_cursos();