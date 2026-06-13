#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    axisBlokRadioGroup = new QButtonGroup(this);
    axisBlokRadioGroup->addButton(ui->xAxisSelect, 0);
    axisBlokRadioGroup->addButton(ui->yAxisSelect, 1);

    ui->punktyTable->setRowCount(255);
    ui->pretyTable->setRowCount(255);
    ui->podporyTable->setRowCount(255);
    ui->obcPunktTable->setRowCount(255);
    ui->obcKonstrTable->setRowCount(255);
    ui->momentTable_2->setRowCount(255);
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

void MainWindow::odswiezTabele(QTableWidget* odswiezanaTabela, int dataType)
{
    odswiezanaTabela->clearContents();
    int i = 0;
    switch (dataType) {
    case punkty: // dodałem enuma bo lepiej wygląda i jest czytelniejszy
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
    case prety:
        for (Pret* wybrany : aplikacja.getSchemat()->zwrocPrety())
        {
            //odswiezanaTabela->insertRow(i);
            odswiezanaTabela->setItem(i, 0, new QTableWidgetItem( QString::fromStdString( wybrany->getNazwa() ) ));
            odswiezanaTabela->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(wybrany->getPPocz()->getNazwa())));
            odswiezanaTabela->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(wybrany->getPKonc()->getNazwa())));
            ++i;
        }
        break;
    case podpory:
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
    case sily:
    {
        for (Obciazenie* obc : aplikacja.getSchemat()->zwrocObciazenia())
        {

            if (obc->typ == silaSkupiona)
            {
                odswiezanaTabela->setItem(i, 0, new QTableWidgetItem( QString::fromStdString( obc->getNazwa() ) ));
                std::string nazwa = obc->getPunkt()->getNazwa() +" (" + std::to_string(obc->getPunkt()->getX()) + "," + std::to_string(obc->getPunkt()->getY()) + ")";
                odswiezanaTabela->setItem(i, 1, new QTableWidgetItem( QString::fromStdString( nazwa)));
                i++;
            }
        }
        break;
    case momenty:
        for (Obciazenie* obc : aplikacja.getSchemat()->zwrocObciazenia())
        {

            if (obc->typ == momentSkupiony)
            {
                odswiezanaTabela->setItem(i, 0, new QTableWidgetItem( QString::fromStdString( obc->getNazwa() ) ));
                std::string nazwa = obc->getPunkt()->getNazwa() +" (" + std::to_string(obc->getPunkt()->getX()) + "," + std::to_string(obc->getPunkt()->getY()) + ")";
                odswiezanaTabela->setItem(i, 1, new QTableWidgetItem( QString::fromStdString( nazwa)));
                i++;
            }
        }
        break;
    case obcKonstrukcyjne:
        for (Obciazenie* obc : aplikacja.getSchemat()->zwrocObciazenia())
        {

            if (obc->typ == konstrukcyjne)
            {
                odswiezanaTabela->setItem(i, 0, new QTableWidgetItem( QString::fromStdString( obc->getNazwa() ) ));
                std::string nazwa = obc->getPret()->getNazwa();
                odswiezanaTabela->setItem(i, 1, new QTableWidgetItem( QString::fromStdString(nazwa)));
                i++;
            }


        }
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
    case punkty:
        for (Punkt *wybrany : aplikacja.getSchemat()->zwrocPunkty())
        {
            temp = wybrany->getNazwa() + ":\t(" + std::to_string(wybrany->getX()) + ", " + std::to_string(wybrany->getY())+ ')';
            odswiezanyQBox->addItem(QString::fromStdString(temp));
        }
        break;
    case prety:
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
    case punkty:
        odswiezanySBox->setRange(0, aplikacja.getSchemat()->zwrocPunkty().size());
        break;
    case prety:
        odswiezanySBox->setRange(0, aplikacja.getSchemat()->zwrocPrety().size());
        break;
    case podpory:
        odswiezanySBox->setRange(0, aplikacja.getSchemat()->zwrocPodpory().size());
        break;
    case obcKonstrukcyjne:
        odswiezanySBox->setRange(0, aplikacja.getSchemat()->indekxyObciazen().size());
        break;
    case sily:
        odswiezanySBox->setRange(0, aplikacja.getSchemat()->indekxySil().size());
        break;
    case momenty:
        odswiezanySBox->setRange(0, aplikacja.getSchemat()->indekxyMomentow().size());
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
    odswiezTabele(ui->punktyTable, punkty);
    odswiezTabele(ui->pretyTable, prety);
    odswiezTabele(ui->podporyTable, podpory);
    odswiezTabele(ui->obcPunktTable, sily);
    odswiezTabele(ui->momentTable_2, momenty);
    odswiezTabele(ui->obcKonstrTable, obcKonstrukcyjne);

    odswiezCBox(ui->pretStartPointComboBox, punkty);
    odswiezCBox(ui->pretEndPointComboBox, punkty);
    odswiezCBox(ui->obcPunktGroupBox, punkty);
    odswiezCBox(ui->pretObcComboBox, prety);
    odswiezCBox(ui->punktPodporyComboBox, punkty);
    odswiezCBox(ui->momentGroupBox_2, punkty);

    odswiezSBox(ui->pktRemoveSBox, punkty);
    odswiezSBox(ui->pretRemoveSBox, prety);
    odswiezSBox(ui->obcPktRemoveSBox, sily);
    odswiezSBox(ui->obcKRemoveSBox, obcKonstrukcyjne);
    odswiezSBox(ui->momentRemoveSBox, momenty);


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
    //qDebug() << "indeksy: " << ui->pretStartPointComboBox->currentIndex() << "\t" << ui->pretEndPointComboBox->currentIndex();
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


void MainWindow::on_podporaAddBtn_clicked()
{
    std::string nazwa = ui->podporaNameEdit->text().toStdString();
    int indexPkt = ui->punktPodporyComboBox->currentIndex();
    Punkt* pktPodpory = aplikacja.getSchemat()->zwrocPunkty()[indexPkt];
    aplikacja.getKonstruktor()->dodajPodpore(pktPodpory, ui->podporaTypeComboBox->currentIndex(), axisBlokRadioGroup->checkedId());
    odswiezUI();

}


void MainWindow::on_podporaRemoveBtn_clicked()
{
    aplikacja.getSchemat()->kasujWybranaPodpore(ui->podpRemoveSBox->value()-1);
    odswiezUI();
}


void MainWindow::on_obcPunktAddBtn_clicked()
{
    std::string nazwa = ui->obcPunktNameEdit->text().toStdString();
    double x = ui->obcPunktXSpinBox->text().toDouble();
    double y = ui->obcPunktYSpinBox->text().toDouble();
    int index = ui->obcPunktGroupBox->currentIndex();
    Punkt* punkt = aplikacja.getSchemat()->zwrocPunkty()[index];
    Obciazenie* nowe = new ObcPunktowe(x, y, punkt, nazwa);
    aplikacja.getSchemat()->dodajObciazenie(nowe);
    odswiezUI();

}

void MainWindow::on_obcPunktRemoveBt_clicked()
{
    aplikacja.getSchemat()->kasujWybranaObciazenie(ui->obcPktRemoveSBox->value()-1);
    odswiezUI();
}

void MainWindow::on_momentAddBtn_2_clicked()
{
    std::string nazwa = ui->momentNameEdit_2->text().toStdString();
    double wartosc = ui->momentSpinBox_2->text().toDouble();
    int index = ui->punktPodporyComboBox->currentIndex();
    Punkt* punkt = aplikacja.getSchemat()->zwrocPunkty()[index];
    Obciazenie* nowy = new MomentSkupiony(wartosc, punkt, nazwa);
    aplikacja.getSchemat()->dodajObciazenie(nowy);
    odswiezUI();
}

void MainWindow::on_momentRemoveBtn_2_clicked()
{
    aplikacja.getSchemat()->kasujWybranaObciazenie(ui->momentRemoveSBox->value()-1);
    odswiezUI();
}

















