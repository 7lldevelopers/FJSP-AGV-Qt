#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <QDebug>
#include <QFileInfo>
#include <QJsonObject>
#include <QDateTime>
#include <QDir>
#include <QPalette>
#include <QPalette>
#include <qpalette.h>
#include <QString>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPalette palette(this->palette());
    palette.setColor(QPalette::Window, QColor(122,197,205));
    this->setPalette(palette);
    ui->portEdit_2->setPlaceholderText("请输入数量...");
    ui->portEdit_3->setPlaceholderText("请输入数量...");
    ui->portEdit_4->setPlaceholderText("请输入数量...");
    connect(ui->portEdit_2, SIGNAL(textChanged(const QString &)), this, SLOT(agvtxt()));
    connect(ui->portEdit_4, SIGNAL(textChanged(const QString &)), this, SLOT(machinetxt()));
    connect(ui->portEdit_3, SIGNAL(textChanged(const QString &)), this, SLOT(joptxt()));
    //a1
    connect(ui->portEdit_5, SIGNAL(textChanged(const QString &)), this, SLOT(a1_txt1()));
    connect(ui->portEdit_22, SIGNAL(textChanged(const QString &)), this, SLOT(a1_txt2()));
    connect(ui->portEdit_26, SIGNAL(textChanged(const QString &)), this, SLOT(a1_txt3()));
    connect(ui->portEdit_14, SIGNAL(textChanged(const QString &)), this, SLOT(a1_txt4()));
    //a2
    connect(ui->portEdit_7, SIGNAL(textChanged(const QString &)), this, SLOT(a2_txt1()));
    connect(ui->portEdit_23, SIGNAL(textChanged(const QString &)), this, SLOT(a2_txt2()));
    connect(ui->portEdit_27, SIGNAL(textChanged(const QString &)), this, SLOT(a2_txt3()));
    connect(ui->portEdit_15, SIGNAL(textChanged(const QString &)), this, SLOT(a2_txt4()));
    //a3
    connect(ui->portEdit_8, SIGNAL(textChanged(const QString &)), this, SLOT(a3_txt1()));
    connect(ui->portEdit_24, SIGNAL(textChanged(const QString &)), this, SLOT(a3_txt2()));
    connect(ui->portEdit_28, SIGNAL(textChanged(const QString &)), this, SLOT(a3_txt3()));
    connect(ui->portEdit_16, SIGNAL(textChanged(const QString &)), this, SLOT(a3_txt4()));
    //a4
    connect(ui->portEdit_9, SIGNAL(textChanged(const QString &)), this, SLOT(a4_txt1()));
    connect(ui->portEdit_25, SIGNAL(textChanged(const QString &)), this, SLOT(a4_txt2()));
    connect(ui->portEdit_29, SIGNAL(textChanged(const QString &)), this, SLOT(a4_txt3()));
    connect(ui->portEdit_17, SIGNAL(textChanged(const QString &)), this, SLOT(a4_txt4()));


}

void MainWindow::callJavaMethodPrintHello()
{

pro->start("D:\\Dict\\YoudaoDict.exe");
system("python /? ");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_clicked()
{
    QString imagePath = "/home/qill/桌面/实验结果/集体流程图2.jpg";

    QFileInfo file(imagePath);
    if(!file.exists()) return;

    QImage image;
    image.load(imagePath);
    if(image.isNull()) return;

    labelImage = new QLabel(this, Qt::Dialog |Qt::WindowCloseButtonHint); /* 去掉?按钮 */
    labelImage->setWindowTitle("图片");
    labelImage->installEventFilter(this);
    /* 下面这两句代码是Label跟随图片大小变化 */
    labelImage->resize(QSize(image.width(), image.height()));
    labelImage->setPixmap(QPixmap::fromImage(image));
    /* 这两句是图片跟随label大小变化 */
    labelImage->resize(300,300);
//    labelImage->setPixmap(QPixmap::fromImage(image.scaled(300, 300, Qt::KeepAspectRatio)));
    labelImage->setFrameShape(QFrame::Box);
   labelImage->setScaledContents(true);
    labelImage->show();

}

void MainWindow::on_pushButton_4_clicked()
{
//pro->start("D:\\Dict\\YoudaoDict.exe");
//    system("cd /home/qill/桌面/华为云比赛/LinuxRelease/SDK/src/com/huawei/codecraft");
//     system("pwd");
   system("java -jar qll-idea.jar");
}

void MainWindow::agvtxt()
{
        agv=ui->portEdit_2->text();
        qDebug()<<agv;
}

void MainWindow::machinetxt()
{
  machine=ui->portEdit_4->text();
  qDebug()<<machine;
}

void MainWindow::joptxt()
{
  jop=ui->portEdit_3->text();
   qDebug()<<jop;
}



void MainWindow::on_pushButton_5_clicked()
{
     lujin=ui->textEdit->document()->toPlainText();
     qDebug()<<lujin;
     gongxu=ui->textEdit_2->document()->toPlainText();
     qDebug()<<gongxu;
    QFile file( "/home/qill/C++/FJSPAGV/1.json");
    if(!file.open(QIODevice::ReadWrite)) {
        qDebug() << "File open error";
    } else {
        qDebug() <<"File open!";
    }
    //gongjian
    int jop1=jop.toInt();
     QJsonArray jopm;
     for (int i=1;i <= jop1;i++ ) {
         QString str="00";
         QString str1=QString::number(i);;
       jopm.append(str+str1);
     }
    //AGV
     int a=agv.toInt();
     QJsonArray agvm;
     for (int i=1;i <= a;i++ ) {
         QString str="AGV";
         QString str1=QString::number(i);;
       agvm.append(str+str1);
     }
    //machine
    QJsonArray MACHINE;
    int machine1=machine.toInt();
    // 往数组中添加元素
    for (int i=1;i <= machine1;i++ ) {
        QString str="MO";
        QString str1=QString::number(i);;
      MACHINE.append(str+str1);
    }
    //MACHINE weizhi
     QJsonArray MACHINE_weizhi;
         QString str="03";
         QString str1="07";
         QString str2="09";
         QString str3="21";
       MACHINE_weizhi.append(str);
       MACHINE_weizhi.append(str1);
       MACHINE_weizhi.append(str2);
       MACHINE_weizhi.append(str3);
    //agv weizhi
    QJsonArray agv_weizhi;
    for (int i=1;i <= a;i++ ) {
      QString str="01";
      agv_weizhi.append(str);
    }
    // 工件gongxu a1
    QJsonObject likeObject1;
    likeObject1.insert("机器", "MO1");
    likeObject1.insert("时长",a1_1);

    QJsonObject likeObject2;
    likeObject2.insert("机器", "MO2");
    likeObject2.insert("时长", a1_2);
    QJsonObject likeObject3;
    likeObject3.insert("机器", "MO3");
    likeObject3.insert("时长", a1_3);
    QJsonObject likeObject4;
    likeObject4.insert("机器", "MO4");
    likeObject4.insert("时长", a1_4);
    // 定义 [ ] 对象
    QJsonArray likeArray;
    likeArray.append(likeObject1);
    likeArray.append(likeObject2);
    likeArray.append(likeObject3);
    likeArray.append(likeObject4);
    //A2
    QJsonObject likeObject5;
    likeObject5.insert("机器", "MO1");
    likeObject5.insert("时长",a2_1);

    QJsonObject likeObject6;
    likeObject6.insert("机器", "MO2");
    likeObject6.insert("时长", a2_2);
    QJsonObject likeObject7;
    likeObject7.insert("机器", "MO3");
    likeObject7.insert("时长", a2_3);
    QJsonObject likeObject8;
    likeObject8.insert("机器", "MO4");
    likeObject8.insert("时长", a2_4);
    // 定义 [ ] 对象
    QJsonArray likeArray2;
    likeArray2.append(likeObject5);
    likeArray2.append(likeObject6);
    likeArray2.append(likeObject7);
    likeArray2.append(likeObject8);
    //A3
    QJsonObject likeObject9;
    likeObject9.insert("机器", "MO1");
    likeObject9.insert("时长",a3_1);

    QJsonObject likeObject10;
    likeObject10.insert("机器", "MO2");
    likeObject10.insert("时长", a3_2);
    QJsonObject likeObject11;
    likeObject11.insert("机器", "MO3");
    likeObject11.insert("时长", a3_3);
    QJsonObject likeObject12;
    likeObject12.insert("机器", "MO4");
    likeObject12.insert("时长", a3_4);
    // 定义 [ ] 对象
    QJsonArray likeArray3;
    likeArray3.append(likeObject9);
    likeArray3.append(likeObject10);
    likeArray3.append(likeObject11);
    likeArray3.append(likeObject12);
    //A4
    QJsonObject likeObject13;
    likeObject13.insert("机器", "MO1");
    likeObject13.insert("时长",a4_1);

    QJsonObject likeObject14;
    likeObject14.insert("机器", "MO2");
    likeObject14.insert("时长", a4_2);
    QJsonObject likeObject15;
    likeObject15.insert("机器", "MO3");
    likeObject15.insert("时长", a4_3);
    QJsonObject likeObject16;
    likeObject16.insert("机器", "MO4");
    likeObject16.insert("时长", a4_4);
    // 定义 [ ] 对象
    QJsonArray likeArray4;
    likeArray4.append(likeObject13);
    likeArray4.append(likeObject14);
    likeArray4.append(likeObject15);
    likeArray4.append(likeObject16);
    //LUJIN
      QJsonArray lujin1;
      QString strr=lujin;
      QJsonArray lujing;
//      QString localTrimmed = strr.trimmed();//\t,\n,\v,\f,\r都属于simplified()处理的空白范围  去除字符串首尾的空格
      QStringList strlist=strr.split("\n");//将数据以空格拆分，并放入数组中
      for (int i=0 ;i<strlist.size() ;i++ ) {
//          QString localTrimmed = strlist.at(i).trimmed();
          qDebug()<<strlist.at(i);
          lujing.append(strlist.at(i));
      }
      strlist.size();
    lujin1.append(strlist.at(0));
// 使用QJsonObject对象插入键值对。
    //gongxu

QJsonArray goxu1;
QString trss=gongxu;
 QStringList strlist1=trss.split("\n");
 for (int i=0 ;i<strlist1.size() ;i++ ) {
//     QString localTrimmed = strlist1.at(i).trimmed();
     qDebug()<<strlist1.at(i);
     goxu1.append(strlist1.at(i));
 }

    QJsonObject jsonObject;
 jsonObject.insert("机器集合",MACHINE);
  jsonObject.insert("路径集合",lujing);
  jsonObject.insert("工件集合",jopm);
  jsonObject.insert("工件工序",goxu1);
  jsonObject.insert("AGV集合",agvm);
   jsonObject.insert("AGV初始化位置",agv_weizhi);
    jsonObject.insert("机器的位置",MACHINE_weizhi);
    jsonObject.insert("A1",likeArray);
    jsonObject.insert("A2",likeArray2);
    jsonObject.insert("A3",likeArray3);
    jsonObject.insert("A4",likeArray4);
// 使用QJsonDocument设置该json对象
    QJsonDocument jsonDoc;
    jsonDoc.setObject(jsonObject);

// 将json以文本形式写入文件并关闭文件。
    file.write(jsonDoc.toJson());
    file.close();

    qDebug() << "Write to file";
}
//a1
void MainWindow::a1_txt1()
{
        a1_1=ui->portEdit_5->text();
        qDebug()<<a1_1;
}
void MainWindow::a1_txt2()
{
        a1_2=ui->portEdit_22->text();
}
void MainWindow::a1_txt3()
{
        a1_3=ui->portEdit_26->text();
}
void MainWindow::a1_txt4()
{
        a1_4=ui->portEdit_14->text();
}
//a2
void MainWindow::a2_txt1()
{
        a2_1=ui->portEdit_7->text();
}
void MainWindow::a2_txt2()
{
        a2_2=ui->portEdit_23->text();
}
void MainWindow::a2_txt3()
{
        a2_3=ui->portEdit_27->text();
}
void MainWindow::a2_txt4()
{
        a2_4=ui->portEdit_15->text();
}
//a3
void MainWindow::a3_txt1()
{
        a3_1=ui->portEdit_8->text();
}
void MainWindow::a3_txt2()
{
        a3_2=ui->portEdit_24->text();
}
void MainWindow::a3_txt3()
{
        a3_3=ui->portEdit_28->text();
}
void MainWindow::a3_txt4()
{
        a3_4=ui->portEdit_16->text();
}
//a4
void MainWindow::a4_txt1()
{
        a4_1=ui->portEdit_9->text();
}
void MainWindow::a4_txt2()
{
        a4_2=ui->portEdit_25->text();
}
void MainWindow::a4_txt3()
{
        a4_3=ui->portEdit_29->text();
}
void MainWindow::a4_txt4()
{
    a4_4=ui->portEdit_17->text();
}

void MainWindow::lujing()
{
 lujin=ui->textEdit->document()->toPlainText();
 qDebug()<<lujin;
}

void MainWindow::gongxu1()
{
gongxu=ui->textEdit_2->document()->toPlainText();
qDebug()<<gongxu;
}



