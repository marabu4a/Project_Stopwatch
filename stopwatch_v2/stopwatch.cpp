#include "stopwatch.h"
#include "ui_stopwatch.h"
QTime times;
QTimer stopWatch;
bool checkStatus;
stopwatch::stopwatch(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::stopwatch)
{
    ui->setupUi(this);
    app_style();
    times = QTime(0,0,0,0);
    connect(&stopWatch,SIGNAL(timeout()),this,SLOT(update()));
    stopWatch.setInterval(1);
    checkStatus = false;
}

stopwatch::~stopwatch()
{
    delete ui;
}

void stopwatch::app_style() {
    QPalette darkTheme;
    darkTheme.setColor(QPalette::Window, QColor(53, 53, 53));
    darkTheme.setColor(QPalette::WindowText, Qt::white);
    qApp->setPalette(darkTheme);
}

void stopwatch::on_startButton_clicked()
{
    if (checkStatus == false) {
        ui->startButton->setText("Стоп");
        checkStatus = true;
        stopWatch.start();
        ui->resetButton->setEnabled(false);
    }
    else {
        ui->startButton->setText("Старт");
        checkStatus = false;
        stopWatch.stop();
        ui->resetButton->setEnabled(true);
    }

}

void stopwatch::update() {
    times = times.addMSecs(1);
    ui->labelTime->setText(times.toString("hh:mm:ss:zzz"));

}

void stopwatch::on_resetButton_clicked()
{
    ui->labelTime->setText("00:00:00:000");
    times = QTime(0,0,0,0);
}
