#ifndef CFRAME_H
#define CFRAME_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class cframe;
}
QT_END_NAMESPACE

class cframe : public QMainWindow
{
    Q_OBJECT

public:
    cframe(QWidget *parent = nullptr);
    ~cframe();

private slots:
    void on_bton_crear_reserva_clicked();

    void on_pushButton_3_clicked();

    void on_bton_crear_reserva_2_clicked();

    void on_pushButton_6_clicked();

    void on_bton_crear_reserva_5_clicked();

    void on_pushButton_10_clicked();

    void on_Salir_clicked();

    void on_bton_crear_reserva_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::cframe *ui;
};
#endif // CFRAME_H
