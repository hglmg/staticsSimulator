#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    aplikacja.uruchom();
    aplikacja.getSilnik()->konfiguruj((aplikacja.getSchemat()));
    aplikacja.getSilnik()->rozwiaz();
    aplikacja.getSilnik()->wypisz();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::odswiezTabele(QTableWidget* odswiezanaTabela, char dataType)
{
    odswiezanaTabela->clearContents();
    switch (dataType) {
    case 'p':
        for (Punkt* wybrany : aplikacja.getSchemat()->zwrocPunkty())
        {
            odswiezanaTabela->insertRow(odswiezanaTabela->rowCount());
            odswiezanaTabela->setItem(odswiezanaTabela->columnCount()-1, 0, new QTableWidgetItem(QString::fromStdString(wybrany->getNazwa())));
            odswiezanaTabela->setItem(odswiezanaTabela->columnCount()-1, 1, new QTableWidgetItem(wybrany->getX()));
            odswiezanaTabela->setItem(odswiezanaTabela->columnCount()-1, 2, new QTableWidgetItem(wybrany->getY()));
        }
        break;
    default:
        return;
        break;
    }
}

void MainWindow::on_punktAddBtn_clicked()
{
    Punkt* nowy = new Punkt(ui->punktXCoordSpinBox->value(), ui->punktYCoordSpinBox->value(), ui->punktNameEdit->text().toStdString());
    aplikacja.getSchemat()->dodajPunkt(nowy);
    odswiezTabele(ui->punktyTable, 'p');
}


void MainWindow::on_punktRemoveBtn_clicked()
{
    aplikacja.getSchemat()->kasujPunktKonc();
    odswiezTabele(ui->punktyTable, 'p');
}

