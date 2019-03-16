#ifndef STOPWATCH_H
#define STOPWATCH_H
#include <QMainWindow>
#include <QTime>
#include <QTimer>
#include <QElapsedTimer>
extern QTime times;
extern QTimer stopWatch;
extern bool checkStatus;
namespace Ui {
class stopwatch;
}

class stopwatch : public QMainWindow
{
    Q_OBJECT



public:
    explicit stopwatch(QWidget *parent = nullptr);
    ~stopwatch();
private slots:
    void on_startButton_clicked();
    void update();
    void app_style();
    void on_resetButton_clicked();

private:
    Ui::stopwatch *ui;
};



#endif // STOPWATCH_H
