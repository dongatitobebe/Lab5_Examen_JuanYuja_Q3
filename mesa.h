#ifndef MESA_H
#define MESA_H

#include "reserva.h"
#include<QString>
#include<QVector>
#include<QList>

class mesa
{
public:
    mesa(const QString nombre);

    QString getNombre() const;
    QList<Reserva> getReservaciones() const;
    void agregarReservacion(const Reserva& reserva);
    bool eliminarReservacion(int codigo);

    QString toString() const {
        return QString("Mesa: %1 ").arg(nombre);
    }

protected:
    QString nombre;
    QList<Reserva> reservaciones;

};

#endif // MESA_H
