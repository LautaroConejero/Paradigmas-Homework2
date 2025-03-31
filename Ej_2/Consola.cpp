#include "Consola.hpp"


void ingresar_Est_viejo(Curso& curso_trabajado, vector<Estudiante>& estudiantes_activos){
    cout << "Elija uno de los siguientes Alumnos: ";
    for (int i = 0; i < estudiantes_activos.size(); i++){
        Estudiante it = estudiantes_activos[i];
        cout << i+1 << ". "<< it.getNombre_completo() <<" [" << it.getLegajo() << "]" << endl;
    }
    cout << "Ingrese el legajo del estudiante: ";
    int legajo;
    cin >> legajo;
    while (true){
        for (int i = 0; i < estudiantes_activos.size(); i++){
            Estudiante it = estudiantes_activos[i];
            if (it.getLegajo() == legajo){
                if(curso_trabajado.agregarEstudiante(&it)){
                    it.agregarCurso(&curso_trabajado, it.getPromedio());
                }
                break;
            }
            else{
                cout << "El legajo no existe" << endl;
            }
        }
        break;
    }
    return;
}

void ingresar_Est_nuevo(Curso& curso_trabajado, vector<Estudiante>& estudiantes_activos){
    string nombre, apellido;
    int legajo;
    float calificacion;
    cout << "Ingrese el nombre del estudiante: ";
    cin >> nombre;
    cout << "Ingrese el apellido del estudiante: ";
    cin >> apellido;
    cout << "Ingrese el legajo del estudiante: ";
    cin >> legajo;

    for (int i = 0; i < estudiantes_activos.size(); i++){
        Estudiante it = estudiantes_activos[i];
        while (it.getLegajo() == legajo){
            cout << "El legajo ya existe" << endl;
            cout << "Nuevo legajo: " << it.getLegajo() << endl;
        }
    }

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
    return;           
}
int Consola_Cursos(){
    cout << "Bienvenido al programa de cursos" << endl;
    vector<Curso> cursos_activos;
    vector<Estudiante> estudiantes_activos;
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
                    if (curso_trabajado.Esta_completo()){
                        cout << "El curso esta completo" << endl;
                        break;
                    }
                    cout << "Que quieres?" << endl;
                    cout << "1. Ingresar un estudiante nuevo" << endl;
                    cout << "2. Ingresar un estudiante existente" << endl;
                    cout << "Opcion: ";
                    int opcion;
                    cin >> opcion;
                    while (opcion < 1 || opcion > 2){
                        cout << "Opcion invalida, intente de nuevo" << endl;
                        cout << "Opcion: ";
                        cin >> opcion;  
                    }
                    clear();
                    if (opcion == 2){
                        if (estudiantes_activos.size() == 0){
                            cout << "No hay estudiantes existentes" << endl;
                            break;
                        }
                        ingresar_Est_viejo(curso_trabajado, estudiantes_activos);
                        break;
                    }
                    ingresar_Est_nuevo(curso_trabajado, estudiantes_activos);
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