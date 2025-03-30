#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;
class Estudiante;

class Curso{
    private:
        vector<Estudiante*> estudiantes;
        string nombre;
    public:
        Curso(string n);
        Curso(const Curso& c); // esto hace una shallow copy del curso, se hace asi porque la gracia es que ambos mantengan el mismo puntero de los estudiantes, y si se borra uno tambien se borre en el otro
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
        vector<pair<Curso*, float>> cursos; 
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

void ingresar_Est_viejo(Curso& curso_trabajado, vector<Estudiante>& estudiantes_activos);
void ingresar_Est_nuevo(Curso& curso_trabajado, vector<Estudiante>& estudiantes_activos);
int Consola_Cursos();