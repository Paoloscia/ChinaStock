#ifndef GUI_H
#define GUI_H
#include <QWidget>
#include<QGridLayout>
#include<QMenuBar>
#include<QVBoxLayout>
#include<QGroupBox>
#include<QHBoxLayout>
#include<QLabel>
#include<QFormLayout>
#include<QLineEdit>
#include<QPushButton>
#include<QFile>
#include<QMessageBox>
#include<QCloseEvent>
#include"viewlistaclienti.h"
#include"deeppointer.h"
#include"cliente.h"
#include"piscina.h"
#include"palestra.h"
#include"vip.h"

class mainwindow : public QWidget
{
    Q_OBJECT

public:
    mainwindow(QWidget *parent =nullptr);
    void mostraClienti(const QStringList);
    const QString getParolaCercata() const;
    void nessunSelezionato();
    void visualizzaDettagliCliente(deepPointer<cliente>) const;
    void resetDettCliente() const;
    bool isSelected() const;
    unsigned int getIndexSelected() const;
    void resetColoreFiltro() const;

public slots:
    void richiestaRimoz();
    void showInfoCliente();
    void richiestaPDF();
    void coloriFiltroPalestra();
    void coloriFiltroPiscina();
    void coloriFiltroScheda();
    void coloriFiltrocorso();
    void coloriFiltroVip();
    void coloriFiltroStudente();
    void coloriFiltroMinorenne();
    void coloriFiltroMaggiorenne();
    void closeButton();

private:
    QVBoxLayout* mainLayout, *verticalDxLayout, *verticalSxLayout;
    QHBoxLayout* divH, *hLeftBottoni, *imageLayout;
    QPushButton* All,*palestraCheckFiltro,*piscinaCheckFiltro,*checkfiltrominorenne,*checkfiltromaggiorenne,*deseleziona,*checkfiltrostudente,*checkVip,*checkfiltrocorsopiscina,*checkfiltroschedapalestra;
    QLineEdit* lineCerca;
    QPushButton* addButton,*modButton,*removeButton, *stampaPDFCliente;
    viewListaClienti *listaClienti;
    QLabel *nomeClienteLabel, *cognomeClienteLabel,*codiceFClienteLabel,* LuogoDNLabel,*residenzaClienteLabel,*viaClienteLabel, *telefonoClienteLabel, *mailClienteLabel, *datadNClienteLabel,*studenteClienteLabel,*AbbonamentoPiscinaLabel, *nomeIstruttorePiscinaLabel,*corsoNuotoClienteLabel, *AbbonamentoPalestraLabel,*nomeIstruttorePalestraLabel,*schedaPalestraClienteLabel;
    QGroupBox* piscinaGroup,* palestraGroup, *filtriGroup;
    void setMainWindowStyle();
    void closeEvent(QCloseEvent*) override;

signals:
    void signStampaPDFCliente(const unsigned int);
    void signOpenAddWindow();
    void infoWindow();
    void signOpenModWindow();
    void cercaRuntime();
    void salvaFileMenu();
    void signEsportaCsvClienti();
    void signEsportaPDFClienti();
    void richiestaRimozCliente(const unsigned int);
    void richiestaShowCliente(const unsigned int);
    void filtroPiscina();
    void filtroTutti();
    void filtroPalestra();
    void filtroMaggiorenne();
    void filtroMinorenne();
    void filtroStudente();
    void controllaModificato();
    void filtroVip();
    void filtroCorsoNuoto();
    void filtroSchedaPalestra();
};

#endif // GUI_H
