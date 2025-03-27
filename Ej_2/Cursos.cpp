#include "Cursos.hpp"
#include "memory"

Estudiante::Estudiante(string n, string a, int e):
    nombre(n), apellido(a), legajo(e), promedio(0), cursos(new list<Curso>) {}
void Estudiante::agregarCurso(Curso c, float calificacion){
    cursos.push_back(make_pair(c, calificacion));
    return;
}
void Estudiante::eliminarCurso(Curso curso){
    for (auto it = cursos.begin(); it != cursos.end(); it++){
        if (it->first.nombre == curso->nombre){
            cursos.erase(it);
            return;
        }
    }
    return;
}
void Estudiante::CalcularPromedio(){
    float prom = 0;
    for (auto it = cursos.begin(); it != cursos.end(); it++){
        prom += it->second;
    }
    promedio = prom/cursos.size();
    return;
}

Curso::Curso(string n):
    nombre(n), estudiantes(new vector<Estudiante>) {}
Curso::Curso(string n, vector<Estudiante> estudiantes):
    nombre(n), estudiantes(estudiantes) {}

void Curso::agregarEstudiante(Estudiante e){
    estudiantes.push_back(e);
    return;
}
void Curso::eliminarEstudiante(Estudiante e){
    for (auto it = estudiantes.begin(); it != estudiantes.end(); it++){
        if (it->legajo == e->legajo){
            estudiantes.erase(it);
            return;
        }
    }
    return;
}
bool Curso::Esta_completo(){
    if (estudiantes.size() == 20){
        return true;
    }
    return false;
}
bool Curso::operator<(const Estudiante& estudiante){
    return this->nombre < estudiante.nombre;
}
void Curso::imprimirEstudiantes_alfabeticamente(){
    sort(estudiantes.begin(), estudiantes.end());
    for (auto it = estudiantes.begin(); it != estudiantes.end(); it++){
        cout << it->nombre << " " << it->apellido << endl;
    }
}