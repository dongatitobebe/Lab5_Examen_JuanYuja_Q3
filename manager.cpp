#include "manager.h"



manager::manager() {
    mesa m("Mesa 1");
    listadomesas.append(m);

    //Reserva r()
    //xd.append();
}


bool manager::agregarReserva(const Reserva& reserva, const QString& nombreMesa) {
    for (mesa& mesa : listadomesas) {
        if (mesa.getNombre() == nombreMesa) {

            const QList<Reserva>& reservasDeMesa = mesa.getReservaciones();
            for (const Reserva& r : reservasDeMesa) {
                if (r.getFecha() == reserva.getFecha() && r.getHora() == reserva.getHora()) {
                    qDebug() << "Error ya hay una reserva para esta fecha";
                    return false;
                }
            }


            mesa.agregarReservacion(reserva);
            xd.append(reserva);
            qDebug() << "la mesa se agrego correctamente";
            qDebug() << "Codigo: "+QString::number(mesa.getReservaciones().size());
            return true;
        }
    }
    return false;
}

void manager::agregarMesa(const mesa& mesa) {
    listadomesas.append(mesa);
}



QList<Reserva> manager::obtenerReservas() const {
    return xd;
}


QList<mesa> manager::obtenerlistadoMesas() const {
    return listadomesas;
}

bool manager::quitarMesa(const QString& nombre) {
    for (int in = 0; in < listadomesas.size(); in++) {
        if (listadomesas[in].getNombre() == nombre) {
            listadomesas.removeAt(in);
            return true;
        }
    }
    return false;
}



bool manager::cancelarReserva(int codigo) {

    for (mesa& mesa : listadomesas) {

        QList<Reserva> reservas = mesa.getReservaciones();


        for (int i = 0; i < reservas.size(); ++i) {
            if (reservas[i].getCodigo() == codigo) {

                reservas.removeAt(i);
                xd.removeAt(i);
                return true;
            }
        }
    }

    return false;
}
/*
    int manager::getContadorReservas() const {
        return contadorReservas;
    }
*/

bool manager::verificarReserva(const QString& nombre, int codigo) {
    for (mesa& m : listadomesas) {

        QList<Reserva> reservas = m.getReservaciones();


        for (const Reserva& reserva : reservas) {
            if (reserva.getCodigo() == codigo && reserva.getNombreRepresentante() == nombre) {
                return true;
            }
        }
    }
    return false;
}



void manager::modificarReserva(int codigo, const QString& nombreDelRepresentante, const QString& numeroDeContacto, QString cantidad, const QDate& fecha, const QTime& hora) {

    for (mesa& mesa : listadomesas) {

        for (Reserva& reserva : mesa.getReservaciones()) {
            if (reserva.getCodigo() == codigo) {

                reserva.setNombreRepresentante(nombreDelRepresentante);
                reserva.setNumeroDeTelefono(numeroDeContacto);
                reserva.setCantidad(cantidad);
                reserva.setFecha(fecha);
                reserva.setHora(hora);
                xd[codigo-1]= reserva;

                return;
            }
        }
    }
}

QString manager::obtenerTodasLasReservas(){
    QString resultado;
    for (int i = 0; i<obtenerReservas().size(); i++){
        resultado.append("Reserva a nombre de: "+xd[i].getNombreRepresentante()+" para el: "+xd[i].getFecha().toString()+xd[i].getHora().toString()+"\n\n");
    }
    return resultado;
}
