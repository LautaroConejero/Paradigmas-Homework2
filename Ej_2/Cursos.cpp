#include "Cursos.hpp"
#include "memory"

// faltaria el punto el b v) y c
// posible pregunta, le podria permitir que cree un estudiante con diferente nombre y mismo legajo?
Estudiante::Estudiante(string n, string a, int e):
    nombre(n), apellido(a), legajo(e), promedio(0), cursos() {}
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
    cursos.push_back(make_pair(*c, calificacion));
    return;
}
void Estudiante::eliminarCurso(Curso* curso){
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
bool Estudiante::operator<(const Estudiante& estudiante) const{
    return this->apellido < estudiante.apellido;
}
void Estudiante::operator<<(const Estudiante& estudiante){
    cout << "Nombre completo : " << estudiante.getNombre_completo() << "\n" << "Legajo : " << estudiante.getLegajo() << "\n" << "Promedio general: " << estudiante.getPromedio() << "\n" << endl;
    return;
}
Curso::Curso(string n):
    nombre(n), estudiantes() {}
string Curso::getNombre() const{
    return nombre;
}
bool Curso::existeEstudiante(Estudiante* e) const{
    for (auto it = estudiantes.begin(); it != estudiantes.end(); it++){
        if (it->legajo == e->legajo){
            return true;
        }
    }
    return false;
}
bool Curso::Esta_completo() const{
    if (estudiantes.size() == 20){
        return true;
    }
    return false;
}
bool Curso::agregarEstudiante(Estudiante* e){
    if (Esta_completo() || existeEstudiante(e)){
        cout << "El estudiante no pudo ser ingresado" << endl;
        if (Esta_completo()){
            cout << "El curso esta completo" << endl;
        }else{
            cout << "El estudiante ya existe" << endl;
        }
        return false;
    }
    estudiantes.push_back(*e);
    return true;
}
void Curso::eliminarEstudiante(Estudiante* e){
    for (auto it = estudiantes.begin(); it != estudiantes.end(); it++){
        if (it->legajo == e->legajo){
            estudiantes.erase(it);
            return;
        }
    }
    cout << "El estudiante no se encuentra en "<< nombre << endl; 
    return;
}
void Curso::imprimirEstudiantes_alfabeticamente() const{
    vector<Estudiante> estudiantes_ordenados = estudiantes;
    sort(estudiantes_ordenados.begin(), estudiantes_ordenados.end(), [](const Estudiante& a, const Estudiante& b){
        return a.apellido < b.apellido;});
    for (auto it = estudiantes_ordenados.begin(); it != estudiantes_ordenados.end(); it++){
        cout << it->nombre << " " << it->apellido << endl;
    }
}

int consola_cursos(){
    cout << "Bienvenido al programa de cursos" << endl;
    Curso curso("Paradigmas de la Programacion");
    cout << "El curso " << curso.getNombre() << " ha sido creado" << endl;
    cout << "Desea agregar un estudiante al curso?" << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    int eleccion;
    cin >> eleccion;
    while (eleccion < 1 || eleccion > 2){
        cout << "Opcion invalida, intente de nuevo" << endl;
        cin >> eleccion;
    }
    clear();
    
    
    
    return 0;
}