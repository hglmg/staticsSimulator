#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QComboBox>
#include <QButtonGroup>
#include <QSpinBox>
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
    QButtonGroup *axisBlokRadioGroup = nullptr;
    enum {prety, podpory, punkty, sily,obcKonstrukcyjne,momenty};
    Ui::MainWindow *ui;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void odswiezTabele(QTableWidget* odswiezanaTabela, int);
    void odswiezCBox(QComboBox *odswiezanyQBox, char dataType);
    void odswiezSBox(QSpinBox *odswiezanySBox, char dataType);
    void odswiezUI();// wiecej info o tej metodzie w *.cpp
    ~MainWindow() override;

private slots:
    void on_punktAddBtn_clicked();
    void on_punktRemoveBtn_clicked();

    void on_pretAddBtn_clicked();
    void on_pretRemoveBtn_clicked();

    void on_podporaAddBtn_clicked();
    void on_podporaRemoveBtn_clicked();

    void on_obcPunktAddBtn_clicked();
    void on_obcPunktRemoveBt_clicked();

    void on_momentAddBtn_2_clicked();
    void on_momentRemoveBtn_2_clicked();

};



















#endif // MAINWINDOW_H
