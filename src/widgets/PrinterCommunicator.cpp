#include "widgets/PrinterCommunicator.h"
#include <QDebug>

namespace ORNL{

PrinterCommunicator::PrinterCommunicator(QObject *parent)
    : QObject(parent){}


void PrinterCommunicator::sendCommand(const QString &command)
{
    qDebug() << "Sending command to printer:" << command;

    // 调用一个模拟的函数来处理与打印机的通信
    mockPrinterCommunication(command);
}

void PrinterCommunicator::mockPrinterCommunication(const QString &command)
{
    // 模拟打印机的响应，可以替换为实际的串口通信或网络通信逻辑
    QString response = QString("Printer executed command: %1").arg(command);
    emit printerResponse(response);
}



}
