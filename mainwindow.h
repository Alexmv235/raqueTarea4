#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QLineEdit"
#include "QPushButton"
#include "QLabel"
#include "QLine"
#include "QTextEdit"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLineEdit *inDistancia,*inVelcidad;
    QPushButton *btnCorrer;
    QLine *line;
    QLabel *runnerMan;
    QString valorV,valorD;

    //
    void moveIt(float t);


private slots:
    void setValues();
};
#endif // MAINWINDOW_H
