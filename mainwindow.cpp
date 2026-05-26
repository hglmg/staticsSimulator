#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->punktyTable->setRowCount(255);
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
    int i = 0;
    switch (dataType) {
    case 'p':
        for (Punkt* wybrany : aplikacja.getSchemat()->zwrocPunkty())
        {
            //odswiezanaTabela->insertRow(i);
            odswiezanaTabela->setItem(i, 0, new QTableWidgetItem( QString::fromStdString( wybrany->getNazwa() ) ));
            odswiezanaTabela->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(std::to_string(wybrany->getX()))));
            odswiezanaTabela->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(std::to_string(wybrany->getY()))));
            wybrany->wypisz();
            ++i;
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
    odswiezTabele(ui->punktyTable, 'p');\
        // std::cout<<nowy->getX()<<"\t"<<nowy->getY()<<"\t";
}


void MainWindow::on_punktRemoveBtn_clicked()
{
    aplikacja.getSchemat()->kasujPunktKonc();
    odswiezTabele(ui->punktyTable, 'p');
}

