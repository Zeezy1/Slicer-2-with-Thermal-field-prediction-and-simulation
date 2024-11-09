#ifndef PRINTERCONTROLWIDGET_H
#define PRINTERCONTROLWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QTimer>
#include "PrinterCommunicator.h"  // 与3D打印机通信的接口类

namespace ORNL{

class PrinterControlWidget : public QWidget{
    Q_OBJECT

    public:

    explicit PrinterControlWidget(QWidget *parent = nullptr);
    ~PrinterControlWidget();


    private:
    PrinterCommunicator *m_communicator;  // 用于与打印机通信的类

    // 控制面板上的UI组件
    QPushButton *m_moveXButton;
    QPushButton *m_moveYButton;
    QPushButton *m_moveZButton;
    QPushButton *m_homeButton;
    QPushButton *m_startPrintButton;
    QPushButton *m_stopPrintButton;
    QPushButton *m_loadButton;
    QPushButton *m_enableButton;
    QPushButton *m_disableButton;


    QLineEdit *m_xInput;
    QLineEdit *m_yInput;
    QLineEdit *m_zInput;

    QTextEdit *m_logDisplay;  // 显示路径数据或日志信息

    QLabel *m_tempLabel1; // 显示温度的标签
    QLabel *m_tempLabel2;
    QLabel *m_tempLabel3;
    QLabel *m_tempLabel4;
    QTimer *m_timer;      // 定时器，用于定时更新温度

    // 模拟获取硬件温度的函数，实际使用中可以替换为实际硬件接口
    double getHardwareTemperature();


    // 初始化UI布局
    void setupLayout();

    private slots:
    void moveX();
    void moveY();
    void moveZ();
    void homePrinter();
    void startPrint();
    void stopPrint();
    void updateTemperature();  // 更新温度的槽函数

    // 用于处理与打印机的通信
    void onPrinterResponse(const QString &response);

signals:
    void sendCommandToPrinter(const QString &command);  // 发送指令到打印机的信号
    };




}



#endif // PRINTERCONTROLWIDGET_H
