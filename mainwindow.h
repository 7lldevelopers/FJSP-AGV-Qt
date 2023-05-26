#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qlabel.h>
#include <qprocess.h>
#include <qlineedit.h>
#include<QJsonArray>
#include<QJsonDocument>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString agv;
    QString machine;
    QString  jop;
    QString  a1_1;
    QString  a1_2;
    QString  a1_3;
    QString  a1_4;
    QString  a2_1;
    QString  a2_2;
    QString  a2_3;
    QString  a2_4;
    QString  a3_1;
    QString  a3_2;
    QString  a3_3;
    QString  a3_4;
    QString  a4_1;
    QString  a4_2;
    QString  a4_3;
    QString  a4_4;
    QString  lujin;
    QString gongxu;
    explicit MainWindow(QWidget *parent = nullptr);
    QLabel* labelImage;
    void callJavaMethodPrintHello();
    QProcess* pro;

    ~MainWindow();

private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void agvtxt();
    void machinetxt();
    void joptxt();
    void on_pushButton_5_clicked();
    void a1_txt1();
    void a1_txt2();
    void a1_txt3();
    void a1_txt4();
    void a2_txt1();
    void a2_txt2();
    void a2_txt3();
    void a2_txt4();
    void a3_txt1();
    void a3_txt2();
    void a3_txt3();
    void a3_txt4();
    void a4_txt1();
    void a4_txt2();
    void a4_txt3();
    void a4_txt4();
    void lujing();
void gongxu1();


private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
