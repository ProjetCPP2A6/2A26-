#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"commande.h"
#include "produit.h"
#include <QMainWindow>
#include"QLabel"
#include<QTimer>
#include<QScrollArea>
#include <QProxyStyle>

#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>
#include <QUrl>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QtCharts/QBarSet>
#include <QtCharts/QChart>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class SentimentAnalyzer {
public:
    QMap<QString, int> positiveWords;
    QMap<QString, int> negativeWords;

    SentimentAnalyzer();

    int analyseSentiment(const QString &text);
    QString obtenirSentiment(const QString &text);
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Rendre updateHistoriqueLabel publique
    void updateHistoriqueLabel(const QString &historiqueText);
    void appendHistorique(const QString &historiqueText);


private slots:
    void on_pushButton_ajouter_clicked();
    void on_pushButton_supprimer_clicked();
    void on_comboBox_type_activated(int index);
    void on_comboBox_etat_activated(int index);

    void on_lineEdit_num_editingFinished();
    void on_tableView_5_clicked(const QModelIndex &index);
    void on_pushButton_modifier_clicked();
    void validateID();
    void validatePrix();
    //void validateCode();
    void validateidClient();
    void searchAndDisplayCommande();
    void on_comboBox_tri_currentIndexChanged(int index);
    void envoyerEmailFeedback(const QString &id_client, const QString &code_commande) ;
    void envoyerEmailAvecPython(const QString& emailClient, const QString& code);
    //void mettre_a_jour_emoji_dans_tableview(const QStringList &emojis);
   // void on_pushButton_actualiser_clicked();
    void on_pushButton_exporter_clicked();
    void genererStatistiquesParEtat();
    void updateCommandeStatus();
    void mettreAJourScrollArea();
    void executerScriptPython();
    void rechercherCommandeParCode();
    //void on_pushButton_analyse_clicked();
    void afficherGraphiqueSentiments();
    void onTabChanged(int index);
    //***
    void on_Ajouter_clicked();
    void on_supprimer_clicked();
    void on_rechercheri_clicked();
    void on_rechercherq_clicked();
    void on_recherchern_clicked();
    void on_exporter_clicked();
    void on_Update_clicked();
    void on_btn_statistiques_clicked();
    void refreshTableView();
    void on_ModifierButton_clicked();
    void on_pushButtonCalculer_clicked();

    void on_pb_historique_clicked();
    void on_sort_clicked();
    void on_trieprix_clicked();
    void on_triequantite_clicked();
    QString getHistorique();
    QLabel* getHistoriqueLabel();




private:
    Ui::MainWindow *ui;
    Commande cmd,c;
    void actualiserAffichage();
    QLabel *idErrorLabel;    // Error label for ID
    QLabel *prixErrorLabel;
    //QLabel *codeErrorLabel;
    QLabel *clientError;
    QTimer *searchTimer;
    QTabWidget *tabw;
    QTabWidget *tabCmd;

    //***
    produit p;
    QSystemTrayIcon *trayIcon;





};

#endif // MAINWINDOW_H
