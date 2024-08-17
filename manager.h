#ifndef MANAGER_H
#define MANAGER_H
#include"mesa.h"
#include"reserva.h"
#include<QList>
#include<QString>
#include<QDate>
#include<QTime>
#include<QDebug>
#include <QFile>
#include<QTextStream>
#include<QDir>
#include <QStringList>

class manager
{
public:
    manager();
    bool agregarReserva(const Reserva& reserva, const QString& nombreMesa);

    void agregarMesa(const mesa& mesa);

    QList<Reserva> obtenerReservas() const;

    QList<mesa> obtenerlistadoMesas() const;

    bool cancelarReserva(const int codigo);

    bool quitarMesa(const QString& nombre);

    bool verificarReserva(const QString& nombre, int codigo);

    void modificarReserva(int codigo, const QString& Representante, const QString& telefono, QString cantidad, const QDate& fecha, const QTime& hora);

    QString obtenerTodasLasReservas() ;

    void Reporte(const QList<mesa>& mesas, const QList<Reserva>& reservas) {
        QString escritorioPath = QDir::homePath() + "/Desktop/copiaDeSeguridad.txt";

        QFile file(escritorioPath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);


            out << "Reporte de Reservas\n\n";
            out << "Mesas:\n";
            for (const mesa& mesa : mesas) {
                out << mesa.toString() << '\n';
            }

            out << '\n';

            out << "Reservas:\n";
            for (const Reserva& reserva : reservas) {
                out << reserva.toString() << '\n';
            }

            file.close();
        } else {
            qWarning() << "No se pudo abrir el archivo para escribir.";
        }
    }

    QList<Reserva> xd;

    QList<mesa> listadomesas;

};

#endif // MANAGER_H
