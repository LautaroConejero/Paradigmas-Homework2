#include "Estudiantes.hpp"

Estudiante::Estudiante(string n, string a, int e):
    nombre(n), apellido(a), legajo(e), promedio(0), cursos() {}
string Estudiante::getApellido() const{
    return apellido;
}
string Estudiante::getNombre_completo() const{
    return nombre + " " + apellido;
}
int Estudiante::getLegajo() const{
    return legajo;
}
float Estudiante::getPromedio() const{
    return promedio;
}
void Estudiante::agregarCurso(Curso* c, float calificacion){
    cursos.push_back(make_pair(c, calificacion));
    CalcularPromedio();
    return;
}
void Estudiante::eliminarCurso(Curso* curso){
    for (int i = 0; i < cursos.size(); i++){
        pair it = cursos[i];
        if (it.first->getNombre() == curso->getNombre()){
            cursos.erase(cursos.begin() + i);
        }
        CalcularPromedio();
    }
    return;
}
void Estudiante::CalcularPromedio(){
    if (cursos.size() == 0){
        promedio = 0;
        return;
    }
    float prom = 0;
    for (int i = 0; i < cursos.size(); i++){
        pair it = cursos[i];
        prom += it.second;
    }
    promedio = prom/cursos.size();
    return;
}
bool Estudiante::operator<(const Estudiante& estudiante) const{
    return this->apellido < estudiante.apellido;
}
void Estudiante::operator<<(const Estudiante& estudiante){
    cout << "Nombre completo : " << estudiante.getNombre_completo() << "\n" << "Legajo : " << estudiante.getLegajo() << "\n" << "Promedio general: " << estudiante.getPromedio() << "\n" << endl;
    return;
}