#include "reserva.h"

Reserva::Reserva(const QString& nombre, const QString& telefono, QString cantidad, const QDate& fecha, const QTime& hora, int codigo, QString mesa)
    : nombreRepresentante(nombre), numeroDeTelefono(telefono), cantidad(cantidad), fecha(fecha), hora(hora), codigo(codigo), mesa(mesa){}




QString Reserva::getNumeroDeTelefono() const {
    return numeroDeTelefono;
}

QString Reserva::getCantidad() const {
    return cantidad;
}
QString Reserva::getNombreRepresentante() const {
    return nombreRepresentante;
}

QTime Reserva::getHora() const {
    return hora;
}

int Reserva::getCodigo() const {
    return codigo;
}
QDate Reserva::getFecha() const {
    return fecha;
}
QString Reserva::getMesa() const {
    return mesa;
}



void Reserva::setCantidad(QString cantidad) {
    this->cantidad= cantidad;
}
void Reserva::setNumeroDeTelefono(const QString& telefono) {
    numeroDeTelefono = telefono;
}
void Reserva::setNombreRepresentante(const QString& nombre) {
    nombreRepresentante = nombre;
}


void Reserva::setHora(const QTime& hora) {
    this->hora = hora;
}
void Reserva::setFecha(const QDate& fecha) {
    this->fecha = fecha;
}
void Reserva::setMesa(const QString& mesa){
    this->mesa = mesa;
}

