#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QComboBox>
#include "aplikacjasymulatora.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    AplikacjaSymulatora aplikacja;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void odswiezTabele(QTableWidget* odswiezanaTabela, char dataType);
    void odswiezCBox(QComboBox *odswiezanyQBox, char dataType);
    ~MainWindow() override;

private slots:
    void on_punktAddBtn_clicked();

    void on_punktRemoveBtn_clicked();

    void on_pretAddBtn_clicked();

private:
    Ui::MainWindow *ui;
};



















#endif // MAINWINDOW_H
