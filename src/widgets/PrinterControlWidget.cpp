#include "widgets/PrinterControlWidget.h"
#include <QDebug>

namespace ORNL {

PrinterControlWidget::PrinterControlWidget(QWidget *parent)
    : QWidget(parent), m_communicator(new PrinterCommunicator(this)){

    // 初始化UI组件
    m_moveXButton = new QPushButton ("Move X" , this);
    m_moveYButton = new QPushButton ("Move Y" , this);
    m_moveZButton = new QPushButton ("Move Z" , this);

    m_homeButton = new QPushButton("Home Printer", this);
    m_startPrintButton = new QPushButton("Start Print", this);
    m_stopPrintButton = new QPushButton("Stop Print", this);

    m_loadButton = new QPushButton("Load Path", this);
    m_enableButton = new QPushButton("Enable", this);
    m_disableButton = new QPushButton("Disable", this);

    m_enableButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    m_disableButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    m_loadButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);


    m_xInput = new QLineEdit(this);
    m_xInput->setPlaceholderText("Enter X value");

    m_yInput = new QLineEdit(this);
    m_yInput->setPlaceholderText("Enter Y value");

    m_zInput = new QLineEdit(this);
    m_zInput->setPlaceholderText("Enter Z value");

    m_logDisplay = new QTextEdit(this);
    m_logDisplay->setReadOnly(true);


    //温度显示组件
    m_tempLabel1 = new QLabel("Temperature: -- °C", this);
    m_tempLabel2 = new QLabel("Temperature: -- °C", this);
    m_tempLabel3 = new QLabel("Temperature: -- °C", this);
    m_tempLabel4 = new QLabel("Temperature: -- °C", this);

    // 初始化定时器
    m_timer = new QTimer(this);

    // 启动定时器
    m_timer->start();

    setupLayout();


    // 连接按钮与槽函数
    connect(m_moveXButton, &QPushButton::clicked, this, &PrinterControlWidget::moveX);
    connect(m_moveYButton, &QPushButton::clicked, this, &PrinterControlWidget::moveY);
    connect(m_moveZButton, &QPushButton::clicked, this, &PrinterControlWidget::moveZ);
    connect(m_homeButton, &QPushButton::clicked, this, &PrinterControlWidget::homePrinter);
    connect(m_startPrintButton, &QPushButton::clicked, this, &PrinterControlWidget::startPrint);
    connect(m_stopPrintButton, &QPushButton::clicked, this, &PrinterControlWidget::stopPrint);


    // 连接定时器的timeout信号到更新温度的槽函数
    connect(m_timer, &QTimer::timeout, this, &PrinterControlWidget::updateTemperature);

    // 连接与打印机通信的信号和槽
    connect(this, &PrinterControlWidget::sendCommandToPrinter, m_communicator, &PrinterCommunicator::sendCommand);
    connect(m_communicator, &PrinterCommunicator::printerResponse, this, &PrinterControlWidget::onPrinterResponse);
}

PrinterControlWidget::~PrinterControlWidget() = default;

void PrinterControlWidget::setupLayout(){

    // 创建布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *controlLayout = new QHBoxLayout;
    QHBoxLayout *moveLayout = new QHBoxLayout;
    QHBoxLayout *statusLayout = new QHBoxLayout;

    controlLayout->addWidget(m_enableButton);
    controlLayout->addWidget(m_disableButton);
    controlLayout->addWidget(m_loadButton);

    moveLayout->addWidget(new QLabel("Move X"));
    moveLayout->addWidget(m_xInput);
    moveLayout->addWidget(m_moveXButton);

    moveLayout->addWidget(new QLabel("Move Y:"));
    moveLayout->addWidget(m_yInput);
    moveLayout->addWidget(m_moveYButton);

    moveLayout->addWidget(new QLabel("Move Z:"));
    moveLayout->addWidget(m_zInput);
    moveLayout->addWidget(m_moveZButton);

    statusLayout->addWidget(m_tempLabel1);
    statusLayout->addWidget(m_tempLabel2);
    statusLayout->addWidget(m_tempLabel3);
    statusLayout->addWidget(m_tempLabel4);



     // 设定定时器的间隔为1秒（1000毫秒）
    m_timer->setInterval(1000);

    mainLayout->addLayout(controlLayout);
    mainLayout->addLayout(moveLayout);
    mainLayout->addLayout(statusLayout);


    // 添加按钮
    mainLayout->addWidget(m_homeButton);
    mainLayout->addWidget(m_startPrintButton);
    mainLayout->addWidget(m_stopPrintButton);
    // mainLayout->addWidget(m_enableButton);
    // mainLayout->addWidget(m_disableButton);

    // 日志显示
    mainLayout->addWidget(m_logDisplay);
}



    //函数实现
void PrinterControlWidget::moveX()
{
    QString command = QString("G1 X%1").arg(m_xInput->text());
    emit sendCommandToPrinter(command);
}

void PrinterControlWidget::moveY()
{
    QString command = QString("G1 Y%1").arg(m_yInput->text());
    emit sendCommandToPrinter(command);
}

void PrinterControlWidget::moveZ()
{
    QString command = QString("G1 Z%1").arg(m_zInput->text());
    emit sendCommandToPrinter(command);
}

void PrinterControlWidget::homePrinter()
{
    QString command = "G28";  // 回归到原点的指令
    emit sendCommandToPrinter(command);
}

void PrinterControlWidget::startPrint()
{
    // 开始打印的逻辑
    emit sendCommandToPrinter("M140 S60");  // 示例命令，设置床温
    m_logDisplay->append("Starting print...");
}
void PrinterControlWidget::stopPrint()
{
    // 停止打印的逻辑
    emit sendCommandToPrinter("M112");  // 停止所有动作的急停命令
    m_logDisplay->append("Stopping print...");
}

void PrinterControlWidget::onPrinterResponse(const QString &response)
{
    m_logDisplay->append(response);  // 显示来自打印机的响应
}

double PrinterControlWidget::getHardwareTemperature()
{
    // 模拟从硬件读取温度数据，实际应用中替换为真实的硬件接口
    // 假设这里返回一个随机温度值，范围为20.0到80.0
    return 20.0 + static_cast<double>(qrand() % 6000) / 100.0;  // 20.0 - 80.0 随机值
}


void PrinterControlWidget::updateTemperature()
{
    // 从硬件获取当前温度
    double currentTemperature = getHardwareTemperature();

    // 更新标签上的显示文本
    m_tempLabel1->setText(QString("Temperature: %1 °C").arg(currentTemperature, 0, 'f', 2));
    m_tempLabel2->setText(QString("Temperature: %1 °C").arg(currentTemperature, 0, 'f', 2));
    m_tempLabel3->setText(QString("Temperature: %1 °C").arg(currentTemperature, 0, 'f', 2));
    m_tempLabel4->setText(QString("Temperature: %1 °C").arg(currentTemperature, 0, 'f', 2));


    // 输出到调试窗口
    qDebug() << "Updated temperature: " << currentTemperature;
}



}
