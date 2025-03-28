#include "Cursos.hpp"
#include "memory"
#define Max_capacidad 20
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
bool Curso::existeEstudiante(int legajo) const{
    for (auto it = estudiantes.begin(); it != estudiantes.end(); it++){
        if (it->legajo == legajo){
            return true;
        }
    }
    return false;
}
int Curso::getCantidadEstudiantes() const{
    return estudiantes.size();
}
bool Curso::Esta_completo() const{
    if (getCantidadEstudiantes() == Max_capacidad){
        return true;
    }
    return false;
}
bool Curso::agregarEstudiante(Estudiante* e){
    if (Esta_completo() || existeEstudiante(e->legajo)){
        cout << "El estudiante no pudo ser ingresado" << endl;
        if (Esta_completo()){
            cout << "El curso esta completo" << endl;
        }else{
            cout << "El estudiante ya existe" << endl;
        }
        return false;
    }
    estudiantes.push_back(*e);
    cout << "El estudiante ha sido ingresado correctamente" << endl;
    return true;
}
void Curso::eliminarEstudiante(int legajo){
    for (auto it = estudiantes.begin(); it != estudiantes.end(); it++){
        if (it->legajo == legajo){
            it->eliminarCurso(this);
            estudiantes.erase(it);
            cout << "El estudiante ha sido eliminado correctamente" << endl;
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
    while(true){
        cout << "\nQue desea hacer?" << endl;
        cout << "1. Agregar estudiante" << endl;
        cout << "2. Eliminar un estudiante del curso" << endl;
        cout << "3. Verificar si el alumno se encuentra en el curso" << endl;
        cout << "4. Imprimir los estudiantes del curso alfabeticamente" << endl;
        cout << "5. Verificar el tamaño del curso" << endl;
        cout << "6. Salir" << endl;
        cout << "Opcion: ";
        int eleccion;
        cin >> eleccion;
        while (eleccion < 1 || eleccion > 6){
            cout << "Opcion invalida, intente de nuevo" << endl;
            cout << "Opcion: ";
            cin >> eleccion;  
        }
        clear();
        switch (eleccion){
            case 1:{
                string nombre, apellido;
                int legajo;
                float calificacion;
                cout << "Ingrese el nombre del estudiante: ";
                cin >> nombre;
                cout << "Ingrese el apellido del estudiante: ";
                cin >> apellido;
                cout << "Ingrese el legajo del estudiante: ";
                cin >> legajo;
                cout << "Ingrese la calificacion del estudiante: ";
                cin >> calificacion;
                while (calificacion < 0 || calificacion > 10){
                    cout << "La calificacion debe ser entre 0 y 10" << endl;
                    cout << "Ingrese la calificacion del estudiante: ";
                    cin >> calificacion;
                }
                Estudiante* e = new Estudiante(nombre, apellido, legajo);
                if (curso.agregarEstudiante(e)){
                    e->agregarCurso(&curso, calificacion);
                    e->CalcularPromedio();  
                }              
                break;
            }
            case 2:{
                int legajo;
                cout << "Ingrese el legajo del estudiante a eliminar: ";
                cin >> legajo;
                curso.eliminarEstudiante(legajo);
                break;
            }
            case 3:{
                int legajo;
                cout << "Ingrese el legajo del estudiante a verificar: ";
                cin >> legajo;
                if (curso.existeEstudiante(legajo)){
                    cout << "El estudiante se encuentra en el curso" << endl;
                }else{
                    cout << "El estudiante no se encuentra en el curso" << endl;
                }
                break;
            }
            case 4:{
                cout << "Los estudiantes del curso son: " << endl;
                curso.imprimirEstudiantes_alfabeticamente();
                break;
            }
            case 5:{
                cout << "El curso tiene " << curso.getCantidadEstudiantes() << " estudiantes" << endl;
                if (curso.Esta_completo()){
                    cout << "El curso se encuentra esta completo" << endl;
                    break;}
                cout << "El curso no se encuentra completo" << endl;
                break;
            }
        }
    }
    
    return 0;
}