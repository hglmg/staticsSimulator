#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->punktyTable->setRowCount(255);
    ui->pretyTable->setRowCount(255);
    ui->podporyTable->setRowCount(255);
    ui->obcPunktTable->setRowCount(255);
    ui->obcKonstrTable->setRowCount(255);
    aplikacja.uruchom();
    aplikacja.getSilnik()->konfiguruj((aplikacja.getSchemat()));
    aplikacja.getSilnik()->rozwiaz();
    aplikacja.getSilnik()->wypisz();
    ui->frame->dodajKsztalty(aplikacja.getSchemat());
    odswiezUI();
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
    case 'l':
        for (Pret* wybrany : aplikacja.getSchemat()->zwrocPrety())
        {
            //odswiezanaTabela->insertRow(i);
            odswiezanaTabela->setItem(i, 0, new QTableWidgetItem( QString::fromStdString( wybrany->getNazwa() ) ));
            odswiezanaTabela->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(wybrany->getPPocz()->getNazwa())));
            odswiezanaTabela->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(wybrany->getPKonc()->getNazwa())));
            ++i;
        }
        break;
    case 's':
        for (Podpora* wybrana : aplikacja.getSchemat()->zwrocPodpory())
        {
            std::string blokOsi = "";
            std::string blokObr;
            odswiezanaTabela->setItem(i, 0, new QTableWidgetItem( QString::fromStdString( wybrana->zwrocPunkt()->getNazwa() ) ));
            if (wybrana->zwrocBlok_x()) blokOsi += "X ";
            if (wybrana->zwrocBlok_y()) blokOsi += "Y";
            odswiezanaTabela->setItem(i, 1, new QTableWidgetItem( QString::fromStdString( blokOsi ) ));
            if (wybrana->zwrocBlok_obr()) blokObr = '+';
            else blokObr = '-';
            odswiezanaTabela->setItem(i, 2, new QTableWidgetItem( QString::fromStdString( blokObr ) ));
        }
        break;
    default:
        return;
        break;
    }
}

void MainWindow::odswiezCBox(QComboBox *odswiezanyQBox, char dataType)
{


    odswiezanyQBox->clear();
    std::string temp;
    switch (dataType)
    {
    case 'p':
        for (Punkt *wybrany : aplikacja.getSchemat()->zwrocPunkty())
        {
            temp = wybrany->getNazwa() + ":\t(" + std::to_string(wybrany->getX()) + ", " + std::to_string(wybrany->getY())+ ')';
            odswiezanyQBox->addItem(QString::fromStdString(temp));
        }
        break;
    case 'l':
        for (Pret *wybrany : aplikacja.getSchemat()->zwrocPrety())
        {
            temp = wybrany->getNazwa() + ":\t[(" + std::to_string(wybrany->getPPocz()->getX()) + ", " + std::to_string(wybrany->getPPocz()->getY()) + "); (" + std::to_string(wybrany->getPKonc()->getX()) + ", " + std::to_string(wybrany->getPKonc()->getY()) + ')';
            odswiezanyQBox->addItem(QString::fromStdString(temp));
        }
        break;
    default:
        break;
    }
}

void MainWindow::odswiezSBox(QSpinBox *odswiezanySBox, char dataType)
{
    odswiezanySBox->clear();
    switch (dataType)
    {
    case 'p':
        odswiezanySBox->setRange(0, aplikacja.getSchemat()->zwrocPunkty().size());
        break;
    case 'l':
        odswiezanySBox->setRange(0, aplikacja.getSchemat()->zwrocPrety().size());
        break;
    case 's':
        odswiezanySBox->setRange(0, aplikacja.getSchemat()->zwrocPodpory().size());
        break;
    case 'k':
        break;
    case 'o':
        odswiezanySBox->setRange(0, aplikacja.getSchemat()->zwrocObciazenia().size());
        break;
    default:
        return;
        break;
    }
}

void MainWindow::odswiezUI()
{
    //do tej metody wbijamy WSZYSTKO co musi byc odsiwezone, zeby zamiast robic monolity w kazdym
    //slocie guzika to masz jedna ladna metode

    ui->frame->update();
    odswiezTabele(ui->punktyTable, 'p');
    odswiezTabele(ui->pretyTable, 'l');
    odswiezTabele(ui->podporyTable, 's');
    odswiezCBox(ui->pretStartPointComboBox, 'p');
    odswiezCBox(ui->pretEndPointComboBox, 'p');
    odswiezCBox(ui->obcPunktGroupBox, 'p');
    odswiezCBox(ui->pretObcComboBox, 'l');
    odswiezCBox(ui->punktPodporyComboBox, 'p');
    odswiezSBox(ui->pktRemoveSBox, 'p');
    odswiezSBox(ui->pretRemoveSBox, 'l');
    odswiezSBox(ui->obcPktRemoveSBox, 'o');
    odswiezSBox(ui->obcKRemoveSBox, 'k');

}





void MainWindow::on_punktAddBtn_clicked()
{
    aplikacja.getKonstruktor()->dodajPunkt(ui->punktXCoordSpinBox->value(), ui->punktYCoordSpinBox->value(), ui->punktNameEdit->text().toStdString());
    odswiezUI();
        // std::cout<<nowy->getX()<<"\t"<<nowy->getY()<<"\t";
}
//i postaraj się nie robić takich piętrusów jak w 73 - zrób kilka zmiennych pomicbuiczych, kod jest przejżystrzy

void MainWindow::on_punktRemoveBtn_clicked()
{
    aplikacja.getSchemat()->kasujWybranyPkt(ui->pktRemoveSBox->value()-1);
    odswiezUI();
}

void MainWindow::on_pretAddBtn_clicked()
{
    std::string nazwa = (ui->pretNameLineEdit->text().toStdString());
    int indexPocz = (ui->pretStartPointComboBox->currentIndex());
    int indexKonc= (ui->pretEndPointComboBox->currentIndex());
    Punkt* pocz = aplikacja.getSchemat()->zwrocPunkty()[indexPocz];
    Punkt* konc = aplikacja.getSchemat()->zwrocPunkty()[indexKonc];
    double E = (ui->ELineEdit->text().toDouble());
    double d = (ui->dLineEdit->text().toDouble());
    aplikacja.getKonstruktor()->dodajPret(pocz, konc, E, d, nazwa);
    odswiezUI();
}

void MainWindow::on_pretRemoveBtn_clicked()
{
    aplikacja.getSchemat()->kasujWybranyPret(ui->pretRemoveSBox->value()-1);
    odswiezUI();
}

