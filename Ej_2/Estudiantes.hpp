#ifndef ESTUDIANTES_HPP
#define ESTUDIANTES_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility> 

using namespace std;

class Curso; 
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



#endif 