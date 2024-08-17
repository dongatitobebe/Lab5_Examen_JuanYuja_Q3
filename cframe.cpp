#include "cframe.h"
#include "ui_cframe.h"
#include "reserva.h"
#include "mesa.h"
#include "manager.h"
#include <QDebug>
#include <QMessageBox>


manager admin;
int codigo = 1;
cframe::cframe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::cframe)
{
    ui->setupUi(this);
    QList<mesa>mesas=admin.obtenerlistadoMesas();
    for (const mesa& mesa : mesas) {
        ui->lista_CrearCliente->addItem(mesa.getNombre());
        ui->lista_CrearAdmin->addItem(mesa.getNombre());
        ui->lista_ModificarCliente->addItem(mesa.getNombre());
        ui->lista_ModificarAdmin->addItem(mesa.getNombre());
        ui->listaConsultaMesas->addItem(mesa.getNombre());
    }
}

cframe::~cframe()
{
    delete ui;
}

void cframe::on_bton_crear_reserva_clicked()
{
    int i=ui->lista_CrearCliente->currentRow();
    QList<mesa>mesas=admin.obtenerlistadoMesas();
    Reserva reserva1(ui->le_CrearNombreReserva->text(),ui->le_TelefonoCrearReserva->text(), ui->le_CantidadCrearReserva->text(),ui->de_FechaCrearReserva->date(),ui->te_HoraCrearReserva->time(),codigo++,mesas[i].getNombre());

    if(admin.agregarReserva(reserva1,mesas[i].getNombre())){
        QMessageBox::information(this,"Se ha hecho una reserva", "Codigo: "+QString::number(reserva1.getCodigo()));
    }else{
        QMessageBox::warning(this,"Error","ya hay una reserva en la fecha establecida");
    }
}




void cframe::on_pushButton_3_clicked()
{
    if(admin.verificarReserva(ui->le_ModNombreAdmin->text(),ui->le_ModCodigoAdmin->text().toInt())){
        ui->stackedWidget_2->setCurrentIndex(1);
    }else{
        QMessageBox::warning(this,"ha ocurrido un error", "No se encontro la reservacion");
    }
}


void cframe::on_bton_crear_reserva_2_clicked()
{
    admin.modificarReserva(ui->le_ModCodigoReserva->text().toInt(), ui->le_NombreModificarReserva->text(),ui->le_TelefonoModificarReserva->text(),ui->le_CantidadModificarReserva->text(),ui->de_FechaModificarReserva->date(),ui->te_HoraModificarReserva->time());
    QMessageBox::information(this,"Se ha hecho la modificacion", "Se ha modificado la reservacion");

    ui->stackedWidget_2->setCurrentIndex(0);
}


void cframe::on_pushButton_6_clicked()
{
    if(admin.verificarReserva(ui->le_NombreCancelarReserva->text(),ui->le_CodigoCancelarReserva->text().toInt())){
        admin.cancelarReserva(ui->le_CodigoCancelarReserva->text().toInt());
        QMessageBox::information(this,"Reserva eliminada","Se ha eliminado la reserva");
    }else{
        QMessageBox::warning(this,"Error","No se pudo cancelar la reserva");
    }
}


void cframe::on_bton_crear_reserva_5_clicked()
{
    int i=ui->lista_CrearAdmin->currentRow();
    QList<mesa>mesas=admin.obtenerlistadoMesas();
    Reserva reserva1(ui->le_NombreReservaAdmin->text(),ui->le_TelefonoReservaAdmin->text(), ui->le_CantidadReservaAdmin->text(),ui->de_FechaReservaAdmin->date(),ui->te_HoraReservaAdmin->time(),codigo++,mesas[i].getNombre());

    if(admin.agregarReserva(reserva1,mesas[i].getNombre())){
        qDebug() << reserva1.getNombreRepresentante() + reserva1.getNumeroDeTelefono();
        QMessageBox::information(this,"Se ha hecho una reserva", "Codigo de reserva: "+QString::number(reserva1.getCodigo()));
    }else{
        QMessageBox::warning(this,"Error", "Ya hay una reserva en esa fecha");
    }

}




void cframe::on_pushButton_10_clicked()
{
    ui->text_VerReservasAdmin->clear();
    ui->text_VerReservasAdmin->setText(admin.obtenerTodasLasReservas());
}


void cframe::on_Salir_clicked()
{
    admin.Reporte(admin.listadomesas,admin.xd);
    exit(0);
}


void cframe::on_bton_crear_reserva_6_clicked()
{
    admin.modificarReserva(ui->le_ModCodigoAdmin->text().toInt(), ui->le_ModNombreAdmin->text(),ui->le_TelefonoModifcarAdmin->text(),ui->le_CantidadModificarAdmin->text(),ui->de_FechaModificarAdmin->date(),ui->te_HoraModificarAdmin->time());
    QMessageBox::information(this,"Se ha hecho la modificacion", "Se ha modificado la reservacion");
    ui->stackedWidget_4->setCurrentIndex(0);
}


void cframe::on_pushButton_5_clicked()
{
    if(admin.verificarReserva(ui->le_ModNombreAdmin->text(),ui->le_ModCodigoAdmin->text().toInt())){
        ui->stackedWidget_4->setCurrentIndex(1);
    }else{
        QMessageBox::warning(this,"ha ocurrido un error", "No se encontro la reservacion");
    }
}


void cframe::on_pushButton_7_clicked()
{
    if(admin.verificarReserva(ui->le_NombreCancelarAdmin->text(),ui->le_CodigoCancelarAdmin->text().toInt())){
        admin.cancelarReserva(ui->le_CodigoCancelarAdmin->text().toInt());
        QMessageBox::information(this,"se ha eliminado", "se elimino la reserva");
    }else{
        qDebug() << "algo mal ocurrio";
    }
}


void cframe::on_pushButton_8_clicked()
{
    admin.agregarMesa(ui->le_CrearMesaAdmin->text());
    QMessageBox::information(this,"se agrego", "se agrego una nueva mesa");
    QList<mesa>mesas=admin.obtenerlistadoMesas();
    ui->lista_CrearCliente->clear();
    ui->lista_CrearAdmin->clear();
    ui->lista_ModificarCliente->clear();
    ui->lista_ModificarAdmin->clear();
    for (const mesa& mesa : mesas) {
        ui->lista_CrearCliente->addItem(mesa.getNombre());
        ui->lista_CrearAdmin->addItem(mesa.getNombre());
        ui->lista_ModificarCliente->addItem(mesa.getNombre());
        ui->lista_ModificarAdmin->addItem(mesa.getNombre());
        ui->listaConsultaMesas->addItem(mesa.getNombre());
    }
}


void cframe::on_pushButton_9_clicked()
{
    if(admin.quitarMesa(ui->le_DeshabilitarMesaAdmin->text())){
        //ui->le_DeshabilitarMesaAdmin->
        QMessageBox::information(this,"Se ha deshabilitado", "Se ha deshabilitado la mesa");
    }else{
        QMessageBox::warning(this,"Algo ocurrio mal", "No se pudo deshabilitar");
    }
    ui->lista_CrearCliente->clear();
    ui->lista_CrearAdmin->clear();
    ui->lista_ModificarCliente->clear();
    ui->lista_ModificarAdmin->clear();
    QList<mesa>mesas=admin.obtenerlistadoMesas();
    for (const mesa& mesa : mesas) {
        ui->lista_CrearCliente->addItem(mesa.getNombre());
        ui->lista_CrearAdmin->addItem(mesa.getNombre());
        ui->lista_ModificarCliente->addItem(mesa.getNombre());
        ui->lista_ModificarAdmin->addItem(mesa.getNombre());
        ui->listaConsultaMesas->addItem(mesa.getNombre());
    }
}


void cframe::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void cframe::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

