#include "mesa.h"

mesa::mesa(const QString nombre)
    : nombre(nombre){}

QString mesa::getNombre() const {
    return nombre;
}


bool mesa::eliminarReservacion(int codigo) {
    for (int i = 0; i < reservaciones.size(); ++i) {
        if (reservaciones[i].getCodigo() == codigo) {
            reservaciones.removeAt(i);
            return true;
        }
    }
    return false;
}

QList<Reserva> mesa::getReservaciones() const {
    return reservaciones;
}



void mesa::agregarReservacion(const Reserva& reserva) {
    qDebug() << "Agregando reserva para :"+reserva.getNombreRepresentante();
    reservaciones.append(reserva);
    qDebug() << "Reservaciones actuales: "+reservaciones.size();
}
