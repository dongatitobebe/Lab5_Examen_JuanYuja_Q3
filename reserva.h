#ifndef RESERVA_H
#define RESERVA_H
#include<QString>
#include<QDate>
#include<QTime>


class Reserva
{
public:
    Reserva(const QString& nombre, const QString& telefono, QString cantidad, const QDate& fecha, const QTime& hora, int codigo, QString mesa);



    int getCodigo() const;
    QDate getFecha() const;
    void setFecha(const QDate& fecha);
    QTime getHora() const;
    void setHora(const QTime& hora);
    QString getMesa() const;
    void setMesa(const QString& mesa);
    QString getNombreRepresentante() const;
    void setNombreRepresentante(const QString& nombre);
    QString getNumeroDeTelefono() const;
    void setNumeroDeTelefono(const QString& telefono);
    QString getCantidad() const;
    void setCantidad(QString cantidad);

    QString toString() const {
        return QString("Cliente: %1, Mesa: %2, Fecha: %3, Hora: %4")
            .arg(nombreRepresentante).arg(mesa).arg(fecha.toString()).arg(hora.toString());
    }

private:
    QString nombreRepresentante;
    QString numeroDeTelefono;
    QString cantidad;
    QDate fecha;
    QTime hora;


    int codigo;
    QString mesa;
    //Reserva();
};

#endif // RESERVA_H
