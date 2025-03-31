#include "Cursos.hpp"
//  La relacion entre los objetos Curso y Estudiante es "agregacion".
//  La agregación es una relación débil entre objetos, donde el 'todo' (Curso) contiene referencias a las 'partes' (Estudiantes), pero estas partes pueden existir independientemente del todo.
//  Es por esto, que si un curso desaperece, Los estudiantes se quedarian sin ese curso, pero pueden seguir buscando otro
//  Y tambien, si los cursos se quedan sin estudiantes, aun asi pueden seguir existiendo, ya que no dependen de los estudiantes

Curso::Curso(string n):
    nombre(n), estudiantes() {}

//  Constructor de copia
//  Este constructor hace una copia superficial del curso, 
//  osea copia el nombre y la lista de estudiantes, pero no copia los estudiantes en si. 
//  Te guardas la direccion de memoria de los estudiantes.
Curso::Curso(const Curso& c){
    nombre = c.nombre;
    for (int i = 0; i < c.estudiantes.size(); i++){
        Estudiante* it = c.estudiantes[i];
        estudiantes.push_back(it);
    }
}
string Curso::getNombre() const{
    return nombre;
}
bool Curso::existeEstudiante(int legajo) const{
    for (int i = 0; i < estudiantes.size(); i++){
        Estudiante* it = estudiantes[i];
        if (it->getLegajo() == legajo){
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
    estudiantes.push_back(e);
    cout << "El estudiante ha sido ingresado correctamente" << endl;
    return true;
}
void Curso::eliminarEstudiante(int legajo){
    for (int i = 0; i < estudiantes.size(); i++){
        Estudiante* it = estudiantes[i];
        if (it->getLegajo() == legajo){
            cout << "El estudiante se encuentra en el curso" << endl;
            estudiantes.erase(estudiantes.begin() + i);
            return;
        }
    }
    cout << "El estudiante no se encuentra en "<< nombre << endl; 
    return;
}
void Curso::imprimirEstudiantes_alfabeticamente() const{
    vector<Estudiante*> estudiantes_ordenados = estudiantes;
    sort(estudiantes_ordenados.begin(), estudiantes_ordenados.end(), [](const Estudiante* a, const Estudiante* b){
        return a->getApellido() < b->getApellido();});
    for (int i = 0; i < estudiantes_ordenados.size(); i++){
        Estudiante* it = estudiantes_ordenados[i];
        cout << "1." << "Nombre completo: " << it->getNombre_completo() << endl;
    }
}
