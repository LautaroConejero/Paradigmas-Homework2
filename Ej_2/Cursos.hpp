#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

class Curso{
    private:
        vector<Estudiante> estudiantes;
        string nombre;
    public:
        Curso(string n);
        Curso(string n, vector<Estudiante> estudiantes);
        void agregarEstudiante(Estudiante e);
        void eliminarEstudiante(Estudiante e);
        bool Esta_completo();
        bool operator<(const Estudiante& estudiante);
        void imprimirEstudiantes_alfabeticamente();
};
class Estudiante{
    private:
        string nombre;
        string apellido;
        int legajo;
        float promedio;
        list<pair<Curso, float>> cursos;
    public:
        Estudiante(string n, string a, int e);
        void agregarCurso(Curso c, float calificacion);
        void eliminarCurso(Curso c);
        void CalcularPromedio();

};