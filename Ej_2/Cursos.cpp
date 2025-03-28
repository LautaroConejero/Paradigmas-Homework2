#include "Cursos.hpp"
#include "memory"
#define Max_capacidad 20
// faltaria el punto el b v) y c
// posible pregunta, le podria permitir que cree un estudiante con diferente nombre y mismo legajo?

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
    cursos.push_back(make_pair(*c, calificacion));
    CalcularPromedio();
    return;
}
void Estudiante::eliminarCurso(Curso* curso){
    for (int i = 0; i < cursos.size(); i++){
        pair it = cursos[i];
        if (it.first.getNombre() == curso->getNombre()){
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
Curso::Curso(string n):
    nombre(n), estudiantes() {}
string Curso::getNombre() const{
    return nombre;
}
bool Curso::existeEstudiante(int legajo) const{
    for (int i = 0; i < estudiantes.size(); i++){
        Estudiante it = estudiantes[i];
        if (it.getLegajo() == legajo){
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
    if (Esta_completo() || existeEstudiante(e->getLegajo())){
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
    for (int i = 0; i < estudiantes.size(); i++){
        Estudiante it = estudiantes[i];
        if (it.getLegajo() == legajo){
            cout << "El estudiante se encuentra en el curso" << endl;
            estudiantes.erase(estudiantes.begin() + i);
            return;
        }
    }
    cout << "El estudiante no se encuentra en "<< nombre << endl; 
    return;
}
void Curso::imprimirEstudiantes_alfabeticamente() const{
    vector<Estudiante> estudiantes_ordenados = estudiantes;
    sort(estudiantes_ordenados.begin(), estudiantes_ordenados.end(), [](const Estudiante& a, const Estudiante& b){
        return a.getApellido() < b.getApellido();});
    for (int i = 0; i < estudiantes_ordenados.size(); i++){
        Estudiante it = estudiantes_ordenados[i];
        cout << "1." << "Nombre completo: " << it.getNombre_completo() << endl;
    }
}

int consola_cursos(){
    cout << "Bienvenido al programa de cursos" << endl;
    vector<Curso> cursos_activos;
    Curso curso("Paradigmas de la Programacion");
    cursos_activos.push_back(curso);
    cout << "El curso " << curso.getNombre() << " ha sido creado" << endl;
    while(true){
        cout << "\nQue desea hacer?" << endl;
        cout << "1.Trabajar con un curso existente" << endl;
        cout << "2.Crear un nuevo curso" << endl;
        cout << "3.Salir" << endl;
        cout << "Opcion: ";
        int opcion;
        cin >> opcion;
        while (opcion < 1 || opcion > 3){
            cout << "Opcion invalida, intente de nuevo" << endl;
            cout << "Opcion: ";
            cin >> opcion;  
        }
        if (opcion == 3){
            clear();
            cout << "Gracias por utilizar el programa de cursos" << endl;
            return 0;
        }
        if (opcion == 2){
            string nombre_curso;
            cout << "Ingrese el nombre del curso: ";
            cin >> nombre_curso;
            Curso nuevo_curso(nombre_curso);
            cursos_activos.push_back(nuevo_curso);
            clear();
        }
        else{
            cout << "Seleccione el curso con el que desea trabajar: " << endl;
            for (int i = 0; i < cursos_activos.size(); i++){
                cout << i + 1 << ". " << cursos_activos[i].getNombre() << endl;
            }
            int curso_seleccionado;
            cout << "Opcion: ";
            cin >> curso_seleccionado;
            while (curso_seleccionado < 1 || curso_seleccionado > cursos_activos.size()){
                cout << "opcion invalida, intente de nuevo" << endl;
                cout << "Opcion: ";
                cin >> curso_seleccionado;
            }
            clear();
            Curso& curso_trabajado = cursos_activos[curso_seleccionado - 1];
            
            cout << "Que desea hacer con " << curso_trabajado.getNombre() << "?" << endl;
            cout << "1. Agregar un estudiante" << endl;
            cout << "2. Eliminar un estudiante" << endl;
            cout << "3. Verificar si el alumno se encuentra" << endl;
            cout << "4. Imprimir los estudiantes alfabeticamnte" << endl;
            cout << "5. Verificar la capacidad" << endl;
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
                    if (curso_trabajado.agregarEstudiante(e)){
                        e->agregarCurso(&curso_trabajado, calificacion); 
                    }              
                    break;
                }
                case 2:{
                    int legajo;
                    cout << "Ingrese el legajo del estudiante a eliminar: ";
                    cin >> legajo;
                    curso_trabajado.eliminarEstudiante(legajo);
                    break;
                }
                case 3:{
                    int legajo;
                    cout << "Ingrese el legajo del estudiante a verificar: ";
                    cin >> legajo;
                    if (curso_trabajado.existeEstudiante(legajo)){
                        cout << "El estudiante se encuentra en el curso" << endl;
                    }else{
                        cout << "El estudiante no se encuentra en el curso" << endl;
                    }
                    break;
                }
                case 4:{
                    cout << "Los estudiantes del curso son: " << endl;
                    curso_trabajado.imprimirEstudiantes_alfabeticamente();
                    break;
                }
                case 5:{
                    cout << "El curso tiene " << curso_trabajado.getCantidadEstudiantes() << " estudiantes" << endl;
                    if (curso_trabajado.Esta_completo()){
                        cout << "El curso se encuentra esta completo" << endl;
                        break;}
                    cout << "El curso no se encuentra completo" << endl;
                    cout << "El curso tiene " << Max_capacidad - curso_trabajado.getCantidadEstudiantes() << " lugares disponibles" << endl;
                    break;
                }
            }
        }
    }
    
    return 0;
}