#ifndef CURSOS_HPP
#define CURSOS_HPP
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <memory>
#define Max_capacidad 20
using namespace std;

class Estudiante; 
class Curso{
    private:
        vector<shared_ptr<Estudiante>> estudiantes;
        string nombre;
    public:
        Curso(string n);
        Curso(const Curso& c); // esto hace una shallow copy del curso, se hace asi porque la gracia es que ambos mantengan el mismo puntero de los estudiantes, y si se borra uno tambien se borre en el otro
        string getNombre() const;
        bool agregarEstudiante(shared_ptr<Estudiante> e);
        void eliminarEstudiante(int legajo);
        bool existeEstudiante(int legajo) const;
        int getCantidadEstudiantes() const;
        bool Esta_completo() const;
        void imprimirEstudiantes_alfabeticamente() const;
};

bool comparar_estudiantes(shared_ptr<Estudiante> e1, shared_ptr<Estudiante> e2);
#endif