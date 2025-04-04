#include "Numeros.hpp"


Num_entero::Num_entero(int v) : entero(v) {}
shared_ptr<Numero> Num_entero::suma(shared_ptr<Numero>& n) {
    shared_ptr<Num_entero> n_E = dynamic_pointer_cast<Num_entero>(n);
    int ent = this->entero + n_E->entero;
    return make_shared<Num_entero>(ent);
}
shared_ptr<Numero> Num_entero::resta(shared_ptr<Numero>& n) {
    shared_ptr<Num_entero> n_E = dynamic_pointer_cast<Num_entero>(n);
    int ent = this->entero - n_E->entero;
    return make_shared<Num_entero>(ent);
}
shared_ptr<Numero> Num_entero::multiplicacion(shared_ptr<Numero>& n) {
    shared_ptr<Num_entero> n_E = dynamic_pointer_cast<Num_entero>(n);
    int ent = this->entero * n_E->entero;
    return make_shared<Num_entero>(ent);
}
string Num_entero::Tostring() const {
    return "Numero entero: " + to_string(entero);
}


Num_real::Num_real(float v) : real(v) {}

shared_ptr<Numero> Num_real::suma(shared_ptr<Numero>& n) {
    shared_ptr<Num_real> n_E = dynamic_pointer_cast<Num_real>(n);
    float rl = this->real + n_E->real;
    return make_shared<Num_real>(rl);
}
shared_ptr<Numero> Num_real::resta(shared_ptr<Numero>& n) {
    shared_ptr<Num_real> n_E = dynamic_pointer_cast<Num_real>(n);
    float rl = this->real - n_E->real;
    return make_shared<Num_real>(rl);
}
shared_ptr<Numero> Num_real::multiplicacion(shared_ptr<Numero>& n) {
    shared_ptr<Num_real> n_E = dynamic_pointer_cast<Num_real>(n);
    float rl = this->real * n_E->real;
    return make_shared<Num_real>(rl);
}
string Num_real::Tostring() const {
    return "Numero entero: " + to_string(real);
}


Num_complejo::Num_complejo(float v, float i) : real(v), imaginario(i) {}
shared_ptr<Numero> Num_complejo::suma(shared_ptr<Numero>& n) {
    shared_ptr<Num_complejo> n_C= dynamic_pointer_cast<Num_complejo>(n);
    float rl = this->real + n_C->real;
    float im = this->imaginario + n_C->imaginario;
    return make_shared<Num_complejo>(rl, im);
}
shared_ptr<Numero> Num_complejo::resta(shared_ptr<Numero>& n) {
    shared_ptr<Num_complejo> n_C = dynamic_pointer_cast<Num_complejo>(n);
    float rl = this->real - n_C->real;
    float im = this->imaginario - n_C->imaginario;
    return make_shared<Num_complejo>(rl, im);
}
shared_ptr<Numero> Num_complejo::multiplicacion(shared_ptr<Numero>& n) {
    shared_ptr<Num_complejo> n_C = dynamic_pointer_cast<Num_complejo> (n);
    float rl = this->real * n_C->real - this->imaginario * n_C->imaginario;
    float im = this->real * n_C->imaginario + this->imaginario * n_C->real;
    return make_shared<Num_complejo>(rl, im);
} 
string Num_complejo::Tostring() const {
    return "Parte real: " + to_string(real) + ", Parte imaginaria: " + to_string(imaginario);
}

