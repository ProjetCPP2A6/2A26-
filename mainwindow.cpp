#include "mainwindow.h"
#include "ui_commande.h"
#include"QMessageBox"
#include"commande.h"
#include<Qstring>
#include"QDate"
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QSqlTableModel>
#include <QSqlError>
#include<QIntValidator>
#include"QRegularExpression"
#include<QTimer>
#include <QtNetwork>
#include <QtSql>
#include <QProcess>
#include <QStringList>
#include<QStandardItemModel>
#include<QPainter>
#include<QVBoxLayout>

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>

//******
#include<QFileDialog>
#include<QPainter>


#include<QSqlTableModel>
#include <QSqlError>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QDesktopServices>
#include <QUrl>
#include <QFileInfo>
#include <QtSql>
#include <QSystemTrayIcon>
#include <QIcon>
#include <QAction>
#include <QMessageBox>
#include <QDebug>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QCursor>
#include <QtCharts/QBarSet>
#include <QtCharts/QChart>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QDialog>
#include <QVBoxLayout>
#include <QInputDialog>
#include <QSqlQuery>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
SentimentAnalyzer::SentimentAnalyzer() {
    // Initialiser les mots-clés positifs et négati
    positiveWords = {
        {"heureux", 1}, {"tres bien", 1}, {"excellent", 1}, {"satisfait", 1},
        {"joyeux", 1}, {"parfait", 1}, {"merci", 1}
    };
    negativeWords = {
        {"mauvais", -1}, {"horrible", -1}, {"déçu", -1}, {"problème", -1},
        {"moche", -1}, {"triste", -1}, {"insatisfait", -1}
    };
}

#include <QRegularExpression>

int SentimentAnalyzer::analyseSentiment(const QString &text) {
    int score = 0;

    // Convertir le texte en mots en utilisant QRegularExpression
    QRegularExpression re("\\W+"); // Expression régulière pour diviser par les non-lettres
    QStringList words = text.split(re);

    // Analyser chaque mot
    for (const QString &word : words) {
        QString lowerWord = word.toLower();

        // Si le mot est positif
        if (positiveWords.contains(lowerWord)) {
            score += positiveWords[lowerWord];
        }

        // Si le mot est négatif
        if (negativeWords.contains(lowerWord)) {
            score += negativeWords[lowerWord];
        }
    }

    return score; // Score > 0 : Positif, < 0 : Négatif, = 0 : Neutre
}

QString SentimentAnalyzer::obtenirSentiment(const QString &text) {
    int score = analyseSentiment(text);

    if (score > 0)
        return "Positif";
    else if (score < 0)
        return "Négatif";
    else
        return "Neutre";
}


#include <QTabWidget>
#include <QWidget>
#include <QVBoxLayout>
/*MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    tabw = ui->tabw;
    tabCmd = ui->tabCmd;
    connect(tabw, SIGNAL(currentChanged(int)), this, SLOT(onTabChanged(int)));



    if (!ui->scrollArea->widget()->layout()) {
        QVBoxLayout *scrollLayout = new QVBoxLayout();
        ui->scrollArea->widget()->setLayout(scrollLayout);
    }

    executerScriptPython();
    mettreAJourScrollArea();
    afficherGraphiqueSentiments();

    updateCommandeStatus();
    ui->tableView_5->setAlternatingRowColors(true);
    ui->tableView_5->setModel(cmd.afficher());

    searchTimer = new QTimer(this);
    searchTimer->setInterval(1500);
    searchTimer->setSingleShot(true);  // Only trigger once after the user stops typing

    // Connect textChanged signal to start the timer
    connect(ui->lineEdit_code, &QLineEdit::textChanged, this, [=]() {
        searchTimer->start();  // Restart the timer on each text change
    });


    connect(searchTimer, &QTimer::timeout, this, &MainWindow::searchAndDisplayCommande);


        ui->idErrorLabel->setStyleSheet("QLabel { color : red; }");
        ui->idErrorLabel->setText("");


        ui->prixErrorLabel->setStyleSheet("QLabel { color : red; }");
        ui->prixErrorLabel->setText("");

        ui->clientError->setStyleSheet("QLabel { color : red; }");
        ui->clientError->setText("");

        ui->codeErrorLabel->setStyleSheet("QLabel { color : red; }");
        ui->codeErrorLabel->setText("");


        connect(ui->lineEdit_num, &QLineEdit::textChanged, this, &MainWindow::validateID);
        connect(ui->lineEdit_prix, &QLineEdit::textChanged, this, &MainWindow::validatePrix);
         //connect(ui->lineEdit_code, &QLineEdit::textChanged, this, &MainWindow::validateCode);
        connect(ui->lineEdit_client, &QLineEdit::textChanged, this, &MainWindow::validateidClient);

        connect(ui->comboBox_tri, SIGNAL(currentIndexChanged(int)),
                this, SLOT(on_comboBox_tri_currentIndexChanged(int)));
        connect(ui->pushButton_stat, &QPushButton::clicked, this, &MainWindow::genererStatistiquesParEtat);
        connect(ui->pushButton_rechercher, &QPushButton::clicked, this, &MainWindow::rechercherCommandeParCode);
        // Connexion du signal textChanged de lineEdit_code à la fonction
        connect(ui->line_code, &QLineEdit::textChanged, this, &MainWindow::mettreAJourScrollArea);


}*/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this); // Set up the UI

    // Set the model for tableView_5
    ui->tableView_6->setModel(p.Afficher());

    // Connect signals and slots for buttons
    connect(ui->pushButtonCalculer, &QPushButton::clicked, this, &MainWindow::on_pushButtonCalculer_clicked);
    connect(ui->supprimer, &QPushButton::clicked, this, &MainWindow::on_supprimer_clicked);
    connect(ui->ModifierButton, &QPushButton::clicked, this, &MainWindow::on_ModifierButton_clicked);
    connect(ui->pushButton_exporter, &QPushButton::clicked, this, &MainWindow::on_pushButton_exporter_clicked);
    connect(ui->rechercheri, &QPushButton::clicked, this, &MainWindow::on_rechercheri_clicked);
    connect(ui->Update, &QPushButton::clicked, this, &MainWindow::on_Update_clicked);

    // Tray Icon Setup
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(":/images/tray_icon.png"));
    trayIcon->show();

    // Set up tab switches
    tabw = ui->tabw;
    tabCmd = ui->tabCmd;
    connect(tabw, SIGNAL(currentChanged(int)), this, SLOT(onTabChanged(int)));

    // Set up scroll area
    if (!ui->scrollArea->widget()->layout()) {
        QVBoxLayout *scrollLayout = new QVBoxLayout();
        ui->scrollArea->widget()->setLayout(scrollLayout);
    }

    // Call external functions
    executerScriptPython();
    mettreAJourScrollArea();
    afficherGraphiqueSentiments();
    updateCommandeStatus();

    // Table View Settings
    ui->tableView_5->setAlternatingRowColors(true);
    ui->tableView_5->setModel(cmd.afficher());

    // Search Timer Setup
    searchTimer = new QTimer(this);
    searchTimer->setInterval(1500);
    searchTimer->setSingleShot(true);  // Trigger once after the user stops typing

    // Connect textChanged signal to start the timer
    connect(ui->lineEdit_code, &QLineEdit::textChanged, this, [=]() {
        searchTimer->start();
    });
    connect(searchTimer, &QTimer::timeout, this, &MainWindow::searchAndDisplayCommande);

    // Error labels for input validation
    ui->idErrorLabel->setStyleSheet("QLabel { color : red; }");
    ui->idErrorLabel->setText("");
    ui->prixErrorLabel->setStyleSheet("QLabel { color : red; }");
    ui->prixErrorLabel->setText("");
    ui->clientError->setStyleSheet("QLabel { color : red; }");
    ui->clientError->setText("");
    ui->codeErrorLabel->setStyleSheet("QLabel { color : red; }");
    ui->codeErrorLabel->setText("");

    // Connect textChanged signals for validation
    connect(ui->lineEdit_num, &QLineEdit::textChanged, this, &MainWindow::validateID);
    connect(ui->lineEdit_prix, &QLineEdit::textChanged, this, &MainWindow::validatePrix);
    connect(ui->lineEdit_client, &QLineEdit::textChanged, this, &MainWindow::validateidClient);

    // Connect comboBox for sorting
    connect(ui->comboBox_tri, SIGNAL(currentIndexChanged(int)), this, SLOT(on_comboBox_tri_currentIndexChanged(int)));

    // Connect button for generating statistics
    connect(ui->pushButton_stat, &QPushButton::clicked, this, &MainWindow::genererStatistiquesParEtat);

    // Connect search button for command search
    connect(ui->pushButton_rechercher, &QPushButton::clicked, this, &MainWindow::rechercherCommandeParCode);

    // Connect textChanged signal for line_code to update scroll area
    connect(ui->line_code, &QLineEdit::textChanged, this, &MainWindow::mettreAJourScrollArea);
}





void MainWindow::onTabChanged(int index)
{
    // Vérifiez si l'onglet sélectionné est "gestCmd" (en utilisant l'index ou le texte de l'onglet)
    if (tabw->tabText(index) == "gestCmd") {
        // Lorsque l'onglet "gestCmd" est sélectionné, afficher tabCmd
        tabCmd->show();
    } else {
        // Masquer tabCmd pour les autres onglets
        tabCmd->hide();
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_comboBox_type_activated(int index)
{
    switch (index)
    {
    case 0:
        ui->comboBox_type->setCurrentText("Produit");
        break;
    case 1:
        ui->comboBox_type->setCurrentText("Service");
        break;
    default:
        break;
    }
}
void MainWindow::on_comboBox_etat_activated(int index)
{
    switch (index)
    {
    case 0:
        ui->comboBox_etat->setCurrentText("terminee");
        break;
    case 1:
        ui->comboBox_etat->setCurrentText("en cours");
        break;
    case 2:
        ui->comboBox_etat->setCurrentText("annulee");
        break;
    default:
        break;
    }
}
void MainWindow::on_pushButton_supprimer_clicked(){
    QString idText = ui->lineEdit_code->text();

    if (idText.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID.");
        return;
    }

    //int id = idText.toInt();


    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", "Voulez-vous vraiment supprimer cet élément?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        bool test = cmd.supprimer(idText);
        if (test) {
            ui->tableView_5->setModel(cmd.afficher());
            updateCommandeStatus();
            QMessageBox::information(this, "Succès", "Suppression effectuée avec succès.");

        } else {
            QMessageBox::critical(this, "Erreur", "La suppression n'a pas été effectuée.");
        }
    }
}





void MainWindow::on_pushButton_ajouter_clicked() {
    // Récupération des données du formulaire
    QString code = ui->lineEdit_num->text();
    QString id_client = ui->lineEdit_client->text().trimmed();
    QString etat = ui->comboBox_etat->currentText();
    QString type = ui->comboBox_type->currentText();
    QDate date_commande = ui->dateEdit->date();
    float prix_total = ui->lineEdit_prix->text().toFloat();


    if (code.isEmpty() || id_client.isEmpty() || etat.isEmpty() ||
        type.isEmpty() || prix_total <= 0.0) {
        QMessageBox::critical(this, "Erreur", "Veuillez remplir tous les champs correctement.");
        return;
    }


    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM gs_client WHERE id = :id_client");
    query.bindValue(":id_client", id_client);

    if (query.exec() && query.next() && query.value(0).toInt() > 0) {

        QSqlQuery discountQuery;
        discountQuery.prepare("SELECT COUNT(*) FROM gs_commande WHERE id_client = :id_client");
        discountQuery.bindValue(":id_client", id_client);

        if (discountQuery.exec() && discountQuery.next()) {
            int nb_commandes = discountQuery.value(0).toInt();
            if (nb_commandes >= 3) {
                QMessageBox::information(this, "Réduction", "Ce client est éligible à une réduction de 10% !");
                prix_total -= prix_total * 0.1;
            }
        }


        Commande c(code, type, date_commande, prix_total, etat, id_client);
        bool test = c.ajouter();

        if (test) {

            ui->tableView_5->setModel(cmd.afficher());
            QMessageBox::information(this, tr("Succès"), tr("Ajout effectué."));


            if (etat == "terminee" || etat == "annulee") {
                envoyerEmailFeedback(id_client, code);
            }


            ui->lineEdit_num->clear();
            ui->comboBox_etat->setCurrentIndex(-1);
            ui->comboBox_type->setCurrentIndex(-1);
            ui->lineEdit_prix->clear();
            ui->dateEdit->setDate(QDate::currentDate());
            ui->lineEdit_client->clear();
        } else {
            QMessageBox::critical(this, tr("Erreur"), tr("Ajout non effectué."));
        }

       updateCommandeStatus();
    } else {
        QMessageBox::warning(this, tr("Erreur"), tr("Il n'existe pas de client avec cet ID !"));
    }
}






void MainWindow::actualiserAffichage() {
    ui->tableView_5->setModel(cmd.afficher());
}


void MainWindow::on_lineEdit_num_editingFinished() {

    QString code = ui->lineEdit_num->text();

    QSqlQuery query;
    query.prepare("SELECT prix_total, type, etat, date_commande,id_client FROM gs_commande WHERE code = :code");
    query.bindValue(":code", code);

    if (query.exec() && query.next()) {

        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, tr("code existe déjà"),
                                      tr("code existe déjà. Voulez-vous faire des modifications ?"),
                                      QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {

            ui->lineEdit_prix->setText(query.value("prix_total").toString());
            ui->comboBox_type->setCurrentText(query.value("type").toString());
            ui->comboBox_etat->setCurrentText(query.value("etat").toString());
            ui->dateEdit->setDate(query.value("date_commande").toDate());
            ui->lineEdit_client->setText(query.value("id_client").toString());
            ui->lineEdit_client->setReadOnly(true);
        } else {

            ui->lineEdit_num->clear();
        }
    }
}


void MainWindow::on_pushButton_modifier_clicked() {
    QString code= ui->lineEdit_num->text();
    float prix_total = ui->lineEdit_prix->text().toFloat();
    QString type = ui->comboBox_type->currentText();
    QString etat = ui->comboBox_etat->currentText();
    QDate date_commande = ui->dateEdit->date();

    QSqlQuery query;
    query.prepare("UPDATE gs_commande SET prix_total = :prix_total, type = :type, etat = :etat, date_commande = :date_commande WHERE code = :code");
    query.bindValue(":code", code);
    query.bindValue(":prix_total", prix_total);
    query.bindValue(":type", type);
    query.bindValue(":etat", etat);
    query.bindValue(":date_commande", date_commande);

    if (query.exec()) {
        QMessageBox::information(this, tr("Succès"), tr("Modification réussie."));
        updateCommandeStatus();
        ui->lineEdit_num->clear();
        ui->comboBox_etat->setCurrentIndex(-1);
        ui->comboBox_type->setCurrentIndex(-1);
        ui->lineEdit_prix->clear();
        ui->dateEdit->clear();
        ui->lineEdit_client->clear();
        actualiserAffichage();
    } else {
         qDebug() << "Erreur lors de la modification : " << query.lastError().text();
        QMessageBox::warning(this, tr("Erreur"), tr("Échec de la modification."));
    }
}



void MainWindow::validateidClient() {
    QString id_client = ui->lineEdit_client->text();


    static QRegularExpression regex("^(?=.*[A-Za-z])(?=.*\\d)[A-Za-z\\d]{10}$");


    if (id_client.isEmpty()) {
        ui->clientError->clear();
    } else if (!regex.match(id_client).hasMatch()) {

        ui->clientError->setText("id  doit être 10 caractères(chiffres et lettres)");
    } else {
        ui->clientError->clear();
    }
}
void MainWindow::validateID() {
    QString code = ui->lineEdit_num->text();

     static QRegularExpression regex("^[A-Za-z]{3}-\\d{3}$");

    if (code.isEmpty()) {
        ui->idErrorLabel->clear();
    } else if (!regex.match(code).hasMatch()) {
        ui->idErrorLabel->setText("code doit etre 3 caractere-3chiffres");
    } else {
        ui->idErrorLabel->clear();
    }
}
/*void MainWindow::validateCode() {
    QString code = ui->lineEdit_code->text();

    static QRegularExpression regex("^[A-Za-z]{3}-\\d{3}$");

    if (code.isEmpty()) {
        ui->codeErrorLabel->clear();
    } else if (!regex.match(code).hasMatch()) {
        ui->codeErrorLabel->setText("code doit etre 3 caractere-3chiffres");
    } else {
        ui->codeErrorLabel->clear();
    }
}*/




void MainWindow::validatePrix() {
    bool ok;

    ui->lineEdit_prix->text().toFloat(&ok);

    if (ui->lineEdit_prix->text().isEmpty()) {
        ui->prixErrorLabel->clear();
    } else if (!ok) {
        ui->prixErrorLabel->setText("Le prix doit être un nombre décimal.");
    } else {
        ui->prixErrorLabel->clear();
    }
}




void MainWindow::on_tableView_5_clicked(const QModelIndex &index) {
    if (!index.isValid())
        return;

    int row = index.row();
    QAbstractItemModel *model = ui->tableView_5->model();
    if (!model)
        return;


    QString idCommande = model->data(model->index(row, 0)).toString();
    QString type = model->data(model->index(row, 3)).toString();
    QString etat = model->data(model->index(row, 6)).toString();
    float prixTotal = model->data(model->index(row, 5)).toFloat();
    QDate dateCommande = QDate::fromString(model->data(model->index(row, 4)).toString(), "dd/MM/yyyy");


    ui->lineEdit_num->setText(idCommande);
    ui->comboBox_type->setCurrentText(type);
    ui->lineEdit_prix->setText(QString::number(prixTotal, 'f', 2));
    ui->comboBox_etat->setCurrentText(etat);
    ui->dateEdit->setDate(dateCommande);


    QString idClient = Commande::recupererIdClient(idCommande);

    if (!idClient.isEmpty()) {
        ui->lineEdit_client->setText(idClient);
    }

    ui->lineEdit_num->setEnabled(false);
    ui->lineEdit_client->setEnabled(false);
}


#include <QRegularExpression>

void MainWindow::searchAndDisplayCommande() {
    QString criterion = ui->comboBox->currentText().trimmed();
    QString value = ui->lineEdit_code->text().trimmed();
    bool valid = true;
    ui->codeErrorLabel->clear();

    if (value.isEmpty()) {
        ui->tableView_5->setModel(cmd.afficher());
        return;
    }

    QSqlQuery query;
    QString queryString;


    if (criterion == "recherche par code:") {
        QRegularExpression codeRegex("[A-Za-z]{3}-[0-9]{3}");
        if (!codeRegex.match(value).hasMatch()) {
            valid = false;
            ui->codeErrorLabel->setText("Le code doit être de la forme XXX-XXX ");
            ui->codeErrorLabel->setStyleSheet("color: red;");
        }
        queryString = "SELECT gs_commande.code, "
                      "gs_client.nom || ' ' || gs_client.prenom AS client, "
                      "gs_commande.type, "
                      "gs_commande.date_commande, "
                      "gs_commande.prix_total, "  // Prix total ajouté
                      "gs_commande.etat "
                      "FROM gs_commande "
                      "INNER JOIN gs_client ON gs_commande.id_client = gs_client.id "
                      "WHERE gs_commande.code = :value";
    }

    else if (criterion == "recherche par etat:") {
        QStringList validStates = {"en cours", "terminee", "annulee"};
        if (!validStates.contains(value.toLower())) {
            valid = false;
            ui->codeErrorLabel->setText("Erreur : L'état n'est pas valide");
            ui->codeErrorLabel->setStyleSheet("color: red;");
        }
        queryString = "SELECT gs_commande.code, "
                      "gs_client.nom || ' ' || gs_client.prenom AS client, "
                      "gs_commande.type, "
                      "gs_commande.date_commande, "
                      "gs_commande.prix_total, "  // Prix total ajouté
                      "gs_commande.etat "
                      "FROM gs_commande "
                      "INNER JOIN gs_client ON gs_commande.id_client = gs_client.id "
                      "WHERE gs_commande.etat = :value";
    }

    else if (criterion == "recherche par client:") {
        queryString = "SELECT gs_commande.code, "
                      "gs_client.nom || ' ' || gs_client.prenom AS client, "
                      "gs_commande.type, "
                      "gs_commande.date_commande, "
                      "gs_commande.prix_total, "  // Prix total ajouté
                      "gs_commande.etat "
                      "FROM gs_commande "
                      "INNER JOIN gs_client ON gs_commande.id_client = gs_client.id "
                      "WHERE gs_client.nom = :value OR gs_client.prenom = :value";
    }
    else {
        QMessageBox::critical(this, "Erreur", "Le critère de recherche n'est pas valide.");
        return;
    }

    if (valid) {
        query.prepare(queryString);
        query.bindValue(":value", value);

        if (query.exec()) {
            QStandardItemModel *model = new QStandardItemModel();

            // Définir les en-têtes de colonne dans l'ordre correct
            model->setHorizontalHeaderLabels({"Code", "Client", "Type", "Date", "Prix total", "État actuel"});

            while (query.next()) {
                QList<QStandardItem*> row;

                row.append(new QStandardItem(query.value(0).toString()));  // Code
                row.append(new QStandardItem(query.value(1).toString()));  // Client
                row.append(new QStandardItem(query.value(2).toString()));  // Type
                row.append(new QStandardItem(query.value(3).toDate().toString("dd/MM/yyyy")));  // Date
                row.append(new QStandardItem(query.value(4).toString()));  // Prix total

                // Récupérer et afficher l'état avec l'icône
                QString etat = query.value(5).toString();
                QStandardItem* etatItem = new QStandardItem(etat);

                QPixmap pixmap(20, 20);
                pixmap.fill(Qt::transparent);  // Remplir de transparence

                QPainter painter(&pixmap);
                painter.setRenderHint(QPainter::Antialiasing);  // Antialiasing pour les bords lisses
                painter.setBrush(Qt::transparent);  // Fond transparent
                painter.setPen(Qt::NoPen);  // Pas de bordure

                // Choisir la couleur selon l'état
                if (etat == "terminee") {
                    painter.setBrush(QBrush(Qt::darkGreen));  // Vert pour "terminee"
                } else if (etat == "en cours") {
                    painter.setBrush(QBrush(Qt::yellow));  // Jaune pour "en cours"
                } else if (etat == "annulee") {
                    painter.setBrush(QBrush(Qt::red));  // Rouge pour "annulee"
                }

                painter.drawEllipse(0, 0, 12, 12);  // Dessiner un cercle
                painter.end();
                QIcon icon(pixmap);
                etatItem->setIcon(icon);

                row.append(etatItem);  // Ajouter l'icône d'état

                model->appendRow(row);  // Ajouter la ligne au modèle
            }

            ui->tableView_5->setModel(model);  // Appliquer le modèle au QTableView
        }
    }
}



void MainWindow::on_comboBox_tri_currentIndexChanged(int index)
{
    QString queryStr;

    switch (index) {
    case 0:
        queryStr = "SELECT gs_commande.code, "
                   "gs_client.nom || ' ' || gs_client.prenom AS client, "
                   "gs_commande.type, "
                   "gs_commande.date_commande, "
                   "gs_commande.prix_total, "
                   "gs_commande.etat "
                   "FROM gs_commande "
                   "INNER JOIN gs_client ON gs_commande.id_client = gs_client.id "
                   "ORDER BY CASE gs_commande.type "
                   "WHEN 'produit' THEN 1 "
                   "WHEN 'service' THEN 2 "
                   "ELSE 3 END";
        break;

    case 1:
        queryStr = "SELECT gs_commande.code, "
                   "gs_client.nom || ' ' || gs_client.prenom AS client, "
                   "gs_commande.type, "
                   "gs_commande.date_commande, "
                   "gs_commande.prix_total, "
                   "gs_commande.etat "
                   "FROM gs_commande "
                   "INNER JOIN gs_client ON gs_commande.id_client = gs_client.id "
                   "ORDER BY gs_commande.date_commande DESC";
        break;

    case 2:
        queryStr = "SELECT gs_commande.code, "
                   "gs_client.nom || ' ' || gs_client.prenom AS client, "
                   "gs_commande.type, "
                   "gs_commande.date_commande, "
                   "gs_commande.prix_total, "
                   "gs_commande.etat "
                   "FROM gs_commande "
                   "INNER JOIN gs_client ON gs_commande.id_client = gs_client.id "
                   "ORDER BY CASE gs_commande.etat "
                   "WHEN 'en cours' THEN 1 "
                   "WHEN 'terminee' THEN 2 "
                   "WHEN 'annulee' THEN 3 "
                   "ELSE 4 END";
        break;

    default:
        return;
    }

    QSqlQuery query;
    if (query.exec(queryStr)) {
        QStandardItemModel *model = new QStandardItemModel();

        model->setHorizontalHeaderLabels({"Code", "Client", "Satisfaction", "Type", "Date Commande", "Prix Total", "État actuel"});

        while (query.next()) {
            QList<QStandardItem *> row;
            row.append(new QStandardItem(query.value(0).toString()));
            row.append(new QStandardItem(query.value(1).toString()));
            row.append(new QStandardItem(""));
            row.append(new QStandardItem(query.value(2).toString()));


            QString rawDate = query.value(3).toString();
            qDebug() << "Date brute extraite : " << rawDate;


            QString pureDate = rawDate.split("T").at(0);


            QDate date = QDate::fromString(pureDate, "yyyy-MM-dd");

            QString formattedDate = (date.isValid()) ? date.toString("dd/MM/yyyy") : pureDate;

            qDebug() << "Date formatée : " << formattedDate;

            row.append(new QStandardItem(formattedDate));  // Date Commande

            row.append(new QStandardItem(query.value(4).toString()));  // Prix Total
            row.append(new QStandardItem(query.value(5).toString()));  // État

            model->appendRow(row);
        }

        ui->tableView_5->setModel(model);
    }
}




void MainWindow::envoyerEmailFeedback(const QString& id_client, const QString& code_commande) {

    QSqlQuery query;
    query.prepare("SELECT e_mail FROM gs_client WHERE TRIM(id) = :id_client");
    query.bindValue(":id_client", id_client);


    if (query.exec() && query.next()) {
        QString emailClient = query.value("e_mail").toString();

        if (!emailClient.isEmpty()) {
            envoyerEmailAvecPython(emailClient, code_commande);
        } else {
            QMessageBox::warning(this, tr("Erreur"), tr("Client sans email."));
        }
    } else {
        QMessageBox::warning(this, tr("Erreur"), tr("Client non trouvé."));
    }
}


void MainWindow::envoyerEmailAvecPython(const QString& emailClient, const QString& code_commande) {

    QString pythonPath = "C:/Users/Lenovo/anaconda3/python.exe";
    QString pythonScript = QDir::toNativeSeparators("C:/Users/Lenovo/Documents/metiers/send_email.py");

    QStringList arguments;
    arguments << pythonScript << emailClient << code_commande;

    QProcess *process = new QProcess(this);

    connect(process, &QProcess::readyReadStandardOutput, [process]() {
        QString output = process->readAllStandardOutput();
        qDebug() << "Sortie du script Python:" << output;
    });

    connect(process, &QProcess::readyReadStandardError, [process]() {
        QString errorOutput = process->readAllStandardError();
        qDebug() << "Erreur du script Python:" << errorOutput;
    });

    connect(process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            [process](int exitCode, QProcess::ExitStatus exitStatus) {
                if (exitStatus == QProcess::NormalExit && exitCode == 0) {
                    qDebug() << "Script Python terminé avec succès.";
                } else {
                    qDebug() << "Script Python terminé avec une erreur.";
                }
                process->deleteLater();
            });

    process->start(pythonPath, arguments);

    if (!process->waitForStarted()) {
        qDebug() << "Erreur lors du démarrage du script Python.";
        process->deleteLater();
        return;
    }

    qDebug() << "Script Python lancé pour envoyer l'email.";
}


/*void MainWindow::mettre_a_jour_emoji_dans_tableview(const QStringList &sentiments)
{
    QStandardItemModel *model = qobject_cast<QStandardItemModel*>(ui->tableView_5->model());

    if (model) {
        if (sentiments.isEmpty() || sentiments.first() == "Aucun sentiment trouvé." || sentiments.first().isEmpty()) {
            qDebug() << "Aucun sentiment trouvé ou liste vide.";
            return;
        }

        for (int row = 0; row < model->rowCount(); ++row) {
            if (row < sentiments.size()) {
                QString sentiment = sentiments.at(row);
                model->setData(model->index(row, 2), sentiment);
            }
        }

        ui->tableView_5->viewport()->update();
        QSqlQuery query;
        query.prepare("UPDATE GS_COMMANDE SET satisfaction = :satisfaction WHERE code = :code");

        for (int row = 0; row < sentiments.size(); ++row) {
            QString sentiment = sentiments.at(row);
            QString code= ui->tableView_5->model()->data(ui->tableView_5->model()->index(row, 0)).toString();

            query.bindValue(":satisfaction", sentiment);
            query.bindValue(":code", code);

        }
    }
}*/


/*void MainWindow::on_pushButton_actualiser_clicked()
{

    QProcess process;
    QString pythonPath = "C:/Users/Lenovo/anaconda3/python.exe";
    QString pythonScript = QDir::toNativeSeparators("C:/Users/Lenovo/Documents/metiers/read_email.py");

    process.start(pythonPath, QStringList() << pythonScript);

    process.waitForFinished();

    if (process.exitStatus() != QProcess::NormalExit) {
        qWarning() << "Erreur lors de l'exécution du script Python:" << process.errorString();
        return;
    }

    QString result = process.readAllStandardOutput();
    QString errorOutput = process.readAllStandardError();

    if (result.isEmpty()) {
        qWarning() << "La sortie du script Python est vide.";
        return;
    }

    QStringList sentiments = result.split("\n", Qt::SkipEmptyParts);

    mettre_a_jour_emoji_dans_tableview(sentiments);
}*/
#include<QPdfWriter>
#include<QFileDialog>
#include<QPainter>
void MainWindow::on_pushButton_exporter_clicked()
{

    QString fileName = QFileDialog::getSaveFileName(this, tr("Exporter en PDF"), "", "*.pdf");

    if (fileName.isEmpty()) {
        return;
    }

    QPdfWriter pdfWriter(fileName);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setResolution(200);

    QPainter painter(&pdfWriter);
    painter.setRenderHint(QPainter::Antialiasing);


    QFont titleFont;
    titleFont.setPointSize(20);
    titleFont.setBold(true);
    painter.setFont(titleFont);


    QString title = "Liste des commandes";
    int yPosition = 50;
    painter.drawText(100, yPosition, pdfWriter.width() - 200, 50, Qt::AlignCenter, title);

    yPosition += 120;


    QFont font;
    font.setPointSize(14);
    painter.setFont(font);

    QFontMetrics fontMetrics(font);
    int cellHeight = fontMetrics.height() + 20;
    int rowCount = ui->tableView_5->model()->rowCount();
    int columnCount = ui->tableView_5->model()->columnCount();

    int cellWidth = pdfWriter.width() / columnCount;


    int tableWidth = columnCount * cellWidth;
    int pageWidth = pdfWriter.width();
    int xStart = (pageWidth - tableWidth) / 2;


    painter.setBrush(QColor(144, 238, 144));
    int xPosition = xStart;
    for (int col = 0; col < columnCount; ++col) {
        QString headerData = ui->tableView_5->model()->headerData(col, Qt::Horizontal).toString();
        painter.drawRect(xPosition, yPosition, cellWidth, cellHeight);
        painter.drawText(xPosition, yPosition, cellWidth, cellHeight, Qt::AlignCenter, headerData);
        xPosition += cellWidth;
    }

    painter.setBrush(Qt::NoBrush);
    yPosition += cellHeight;


    for (int row = 0; row < rowCount; ++row) {
        xPosition = xStart;

        for (int col = 0; col < columnCount; ++col) {
            QString cellData = ui->tableView_5->model()->data(ui->tableView_5->model()->index(row, col)).toString();
            painter.drawRect(xPosition, yPosition, cellWidth, cellHeight);
            painter.drawText(xPosition, yPosition, cellWidth, cellHeight, Qt::AlignCenter, cellData);
            xPosition += cellWidth;
        }

        yPosition += cellHeight;
    }

    painter.end();

    QMessageBox::information(this, "Exportation réussie", "L'affichage a été exporté en PDF avec succès.");
}
#include <QPieSeries>
#include <QChart>
#include <QChartView>
#include <QVBoxLayout>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

void MainWindow::genererStatistiquesParEtat()
{
    // Récupération des dates depuis les QDateEdit
    QDate dateDebut = ui->datedebut->date();
    QDate dateFin = ui->datefin->date();

    // Vérification des dates
    if (dateDebut > dateFin) {
        QMessageBox::warning(this, "Erreur", "La date de début doit être antérieure à la date de fin.");
        return;
    }

    // Requête SQL pour récupérer les données regroupées par état
    QSqlQuery query;
    query.prepare("SELECT etat, COUNT(*) AS nombre "
                  "FROM gs_commande "
                  "WHERE date_commande BETWEEN TO_DATE(:dateDebut, 'YYYY-MM-DD') AND TO_DATE(:dateFin, 'YYYY-MM-DD') "
                  "GROUP BY etat");

    query.bindValue(":dateDebut", dateDebut.toString("yyyy-MM-dd"));
    query.bindValue(":dateFin", dateFin.toString("yyyy-MM-dd"));


    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête:" << query.lastError().text();
        return;
    }

    // Création de la série pour le graphique
    QPieSeries *series = new QPieSeries();
    int total = 0;

    while (query.next()) {
        QString etat = query.value(0).toString();  // État (terminée, annulée, en cours)
        int nombre = query.value(1).toInt();      // Nombre de commandes pour cet état

        // Ajout des données à la série
        series->append(etat + " (" + QString::number(nombre) + ")", nombre);
        total += nombre;
    }

    // Vérification des données avant de continuer
    if (series->slices().isEmpty()) {
        QMessageBox::information(this, "Statistiques", "Aucune commande trouvée pour la période sélectionnée.");
        return;
    }

    // Afficher les labels
    for (auto slice : series->slices()) {
        slice->setLabelVisible(true);
    }

    // Création du graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques des commandes (total: " + QString::number(total) + ")");
    chart->legend()->setAlignment(Qt::AlignBottom);

    // Configuration de la vue
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Affichage dans un layout existant
    if (ui->layout_statistiques->layout() != nullptr) {
        delete ui->layout_statistiques->layout();
    }
    QVBoxLayout *layout = new QVBoxLayout(ui->layout_statistiques);
    layout->addWidget(chartView);
    ui->layout_statistiques->setLayout(layout);
}
void MainWindow::updateCommandeStatus() {
    QSqlQuery query;


    query.prepare("SELECT COUNT(*) FROM gs_commande");
    int totalCommandes = 0;
    if (query.exec() && query.next()) {
        totalCommandes = query.value(0).toInt();
    }


    query.prepare("SELECT COUNT(*) FROM gs_commande WHERE etat = 'en cours'");
    int enCoursCommandes = 0;
    if (query.exec() && query.next()) {
        enCoursCommandes = query.value(0).toInt();
    }

    query.prepare("SELECT COUNT(*) FROM gs_commande WHERE etat = 'terminee'");
    int termineCommandes = 0;
    if (query.exec() && query.next()) {
        termineCommandes = query.value(0).toInt();
    }


    query.prepare("SELECT COUNT(*) FROM gs_commande WHERE etat = 'annulee'");
    int annuleCommandes = 0;
    if (query.exec() && query.next()) {
        annuleCommandes = query.value(0).toInt();
    }


    QString labelTextTotal = QString(
                                 "<span style='font-size: 14px; color: black;'>●</span> "
                                 "<span style='font-weight: bold; color: black;'>%1</span> commande(s)"
                                 ).arg(totalCommandes);

    QString labelTextEnCours = QString(
                                   "<span style='font-size: 14px; color: yellow;'>●</span> "
                                   "<span style='font-weight: bold; color: black;'>%1</span> en cours de traitement"
                                   ).arg(enCoursCommandes);

    QString labelTextTerminee = QString(
                                    "<span style='font-size: 14px; color: green;'>●</span> "
                                    "<span style='font-weight: bold; color: black;'>%1</span> terminée(s)"
                                    ).arg(termineCommandes);

    QString labelTextAnnulee = QString(
                                   "<span style='font-size: 14px; color: red;'>●</span> "
                                   "<span style='font-weight: bold; color: black;'>%1</span> annulée(s)"
                                   ).arg(annuleCommandes);


    ui->note->setText(labelTextTotal);
    ui->note2->setText(labelTextEnCours);
    ui->note1->setText(labelTextTerminee);
    ui->note3->setText(labelTextAnnulee);
}



/*void MainWindow::executerScriptPython()
{
    // Chemin du script Python
    QString scriptPath = "C:/Users/Lenovo/Documents/metiers/read_email.py";

    // Créer un processus pour exécuter le script
    QProcess process;
    process.start("python", QStringList() << scriptPath);
    process.waitForFinished();

    // Récupérer la sortie du script pour débogage (facultatif)
    QString output = process.readAllStandardOutput();
    qDebug() << "Sortie du script Python :" << output;
}*/
void MainWindow::executerScriptPython()
{
    // Chemin du script Python
    QString pythonPath = "C:/Users/Lenovo/anaconda3/python.exe"; // Assure-toi que Python est accessible ici
    QString scriptPath = "C:/Users/Lenovo/Documents/metiers/read_email.py";

    // Liste des arguments à passer au script (si nécessaire)
    QStringList arguments;
    arguments << scriptPath;

    // Créer un processus pour exécuter le script Python
    QProcess *process = new QProcess(this);

    // Connexion pour récupérer la sortie standard (pour débogage)
    connect(process, &QProcess::readyReadStandardOutput, [process]() {
        QString output = process->readAllStandardOutput();
        qDebug() << "Sortie du script Python:" << output;
    });

    // Connexion pour récupérer la sortie d'erreur (pour débogage)
    connect(process, &QProcess::readyReadStandardError, [process]() {
        QString errorOutput = process->readAllStandardError();
        qDebug() << "Erreur du script Python:" << errorOutput;
    });

    // Connexion à la fin du processus pour savoir s'il a réussi ou échoué
    connect(process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            [process](int exitCode, QProcess::ExitStatus exitStatus) {
                if (exitStatus == QProcess::NormalExit && exitCode == 0) {
                    qDebug() << "Script Python terminé avec succès.";
                } else {
                    qDebug() << "Script Python terminé avec une erreur.";
                }
                process->deleteLater();
            });

    // Démarrer le processus avec le chemin vers Python et le script
    process->start(pythonPath, arguments);

    // Vérifier si le processus a bien démarré
    if (!process->waitForStarted()) {
        qDebug() << "Erreur lors du démarrage du script Python.";
        process->deleteLater();
        return;
    }

    qDebug() << "Script Python lancé pour exécuter le traitement.";
}




#include<QTextEdit>

    void MainWindow::mettreAJourScrollArea() {
    SentimentAnalyzer sentimentAnalyzer;

    // Récupérer le layout de la ScrollArea
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(ui->scrollArea->widget()->layout());
    if (!layout) {
        qDebug() << "Erreur : Aucun layout trouvé pour la scroll area.";
        return;
    }

    // Effacer le contenu existant
    while (QLayoutItem *item = layout->takeAt(0)) {
        delete item->widget();
        delete item;
    }

    // Charger les données depuis la base de données
    QSqlQuery query;
    query.prepare("SELECT code, nom, prenom, reponse FROM gs_commande "
                  "JOIN gs_client ON gs_commande.id_client = gs_client.id "
                  "WHERE reponse IS NOT NULL AND LENGTH(TRIM(reponse)) > 0");

    if (!query.exec()) {
        qDebug() << "Erreur lors de la récupération des commandes :" << query.lastError().text();
        return;
    }

    while (query.next()) {
        QString code = query.value("code").toString();
        QString nom = query.value("nom").toString();
        QString prenom = query.value("prenom").toString();
        QString reponse = query.value("reponse").toString();

        // Calculer le sentiment
        QString sentiment = sentimentAnalyzer.obtenirSentiment(reponse);

        // Ajouter le code de la commande
        QLabel *labelCode = new QLabel("Commande : " + code);
        labelCode->setStyleSheet("font-weight: bold; font-size: 14px; color: #1f77b4;");
        layout->addWidget(labelCode);

        // Ajouter le nom et prénom du client
        QLabel *labelClient = new QLabel("Client : " + nom + " " + prenom);
        labelClient->setStyleSheet("font-size: 14px; color: #006400;");
        layout->addWidget(labelClient);

        // Ajouter la réponse
        QTextEdit *textReponse = new QTextEdit(reponse);
        textReponse->setReadOnly(true);
        textReponse->setStyleSheet(
            "background-color: #f0f8ff; color: black; font-weight: bold; border: 2px solid #1f77b4; border-radius: 8px; padding: 10px;");
        layout->addWidget(textReponse);

        // Ajouter le sentiment
        QLabel *labelSentiment = new QLabel("Sentiment : " + sentiment);
        labelSentiment->setStyleSheet("font-size: 14px; color: " + QString(sentiment == "Positif" ? "#28a745" : (sentiment == "Négatif" ? "#dc3545" : "#ffc107")) + ";");

        layout->addWidget(labelSentiment);

        // Espacement
        layout->addSpacing(20);
    }

    ui->scrollArea->widget()->update();
}
#include <QSqlQuery>
#include <QBarSet>
#include <QBarSeries>
#include <QChartView>
#include <QChart>
#include <QPixmap>
#include <QPainter>
#include<QValueAxis>
#include<QBarCategoryAxis>

void MainWindow::afficherGraphiqueSentiments() {
    SentimentAnalyzer sentimentAnalyzer;

    int positiveCount = 0;
    int negativeCount = 0;
    int neutralCount = 0;

    // Charger les données depuis la base de données
    QSqlQuery query;
    query.prepare("SELECT reponse FROM gs_commande "
                  "JOIN gs_client ON gs_commande.id_client = gs_client.id "
                  "WHERE reponse IS NOT NULL AND LENGTH(TRIM(reponse)) > 0");

    if (!query.exec()) {
        qDebug() << "Erreur lors de la récupération des réponses :" << query.lastError().text();
        return;
    }

    while (query.next()) {
        QString reponse = query.value("reponse").toString();
        QString sentiment = sentimentAnalyzer.obtenirSentiment(reponse);

        if (sentiment == "Positif") {
            positiveCount++;
        } else if (sentiment == "Négatif") {
            negativeCount++;
        } else {
            neutralCount++;
        }
    }

    // Créer les ensembles de données pour le graphique
    QBarSet *positiveSet = new QBarSet("Satisfaits");
    QBarSet *negativeSet = new QBarSet("Non Satisfaits");
    QBarSet *neutralSet = new QBarSet("Neutres");

    *positiveSet << positiveCount;
    *negativeSet << negativeCount;
    *neutralSet << neutralCount;

    // Définir les couleurs des barres
    positiveSet->setColor(Qt::green);
    negativeSet->setColor(Qt::red);
    neutralSet->setColor(QColor(255, 165, 0)); // Couleur orange

    QBarSeries *series = new QBarSeries();
    series->append(positiveSet);
    series->append(negativeSet);
    series->append(neutralSet);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des Sentiments des Clients");
    chart->createDefaultAxes();

    // Configurer les axes
    chart->axes(Qt::Vertical).first()->setTitleText("Nombre de Clients");
    chart->axes(Qt::Horizontal).first()->setTitleText("Sentiments");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(600, 400); // Taille minimale

    // Afficher l'image dans QLabel
    if (ui->labelGraphique) {
        ui->labelGraphique->setMinimumSize(600, 400); // Taille minimale pour le label
        ui->labelGraphique->setPixmap(chartView->grab()); // Prendre une capture du graphique
        ui->labelGraphique->update(); // Mettre à jour l'affichage
    } else {
        qDebug() << "Erreur : QLabel pour le graphique non trouvé.";
    }

    // Optionnel : Si vous souhaitez ajouter le graphique à une mise en page
    // layout->addWidget(chartView); // Ajoutez cela si vous utilisez un layout
}

void MainWindow::rechercherCommandeParCode()
{
    // Récupérer le layout de la ScrollArea
    QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(ui->scrollArea->widget()->layout());
    if (!layout) {
        qDebug() << "Erreur : Aucun layout trouvé pour la scroll area.";
        return;
    }

    // Effacer le contenu existant dans la ScrollArea
    while (QLayoutItem *item = layout->takeAt(0)) {
        delete item->widget();
        delete item;
    }

    // Récupérer le code de commande entré dans le QLineEdit
    QString codeCommande = ui->line_code->text();



    // Requête SQL pour rechercher une commande par son code
    QSqlQuery query;
    query.prepare("SELECT code, nom, prenom, reponse FROM gs_commande "
                  "JOIN gs_client ON gs_commande.id_client = gs_client.id "
                  "WHERE code = :codeCommande AND reponse IS NOT NULL AND LENGTH(TRIM(reponse)) > 0");
    query.bindValue(":codeCommande", codeCommande);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la récupération des commandes :" << query.lastError().text();
        return;
    }

    // Si aucun résultat n'est trouvé
    if (!query.next()) {
        QLabel *noResultsLabel = new QLabel("Aucune commande trouvée.");
        noResultsLabel->setAlignment(Qt::AlignCenter);
        noResultsLabel->setStyleSheet("font-size: 14px; color: #ff0000; font-weight: bold;");
        layout->addWidget(noResultsLabel);
        return;
    }

    // Parcours des résultats de la requête
    QString code = query.value("code").toString();
    QString nom = query.value("nom").toString();
    QString prenom = query.value("prenom").toString();
    QString reponse = query.value("reponse").toString();

    // Label pour le code de la commande (en bleu foncé)
    QLabel *labelCode = new QLabel("Commande : " + code);
    labelCode->setStyleSheet("font-weight: bold; font-size: 14px; color: #1f77b4;");
    layout->addWidget(labelCode);

    // Label pour le nom et prénom du client (en vert)
    QLabel *labelClient = new QLabel("Client : " + nom + " " + prenom);
    labelClient->setStyleSheet("font-size: 14px; color: #006400;");
    layout->addWidget(labelClient);

    // Zone de texte pour la réponse (en noir, texte en gras)
    QTextEdit *textReponse = new QTextEdit(reponse);
    textReponse->setReadOnly(true);
    textReponse->setStyleSheet(
        "background-color: #f0f8ff; "  // Bleu clair pour le fond
        "color: black; "               // Texte en noir
        "font-weight: bold; "          // Texte en gras
        "border: 2px solid #1f77b4; " // Bordure bleue foncée
        "border-radius: 8px; "         // Coins arrondis
        "padding: 10px; "              // Espacement intérieur
        );
    layout->addWidget(textReponse);

    // Espacement entre les éléments
    layout->addSpacing(20);

}
//*************************produit

//
void MainWindow::on_Ajouter_clicked()
{
    QString nom = ui->nom->text();
    int id = ui->id->text().toInt();
    int quantite = ui->quantite->text().toInt();
    float prixdachat = ui->pa->text().toFloat();
    float prixdevente = ui->pv->text().toFloat();

    if (nom.isEmpty() || id <= 0 || quantite < 0 || prixdachat < 0 || prixdevente < 0) {
        QMessageBox::critical(this, "Erreur", "Vérifiez les données saisies.");
        return;
    }

    produit p(nom, id, quantite, prixdachat, prixdevente);
    bool test = p.Ajouter();

    if (test) {
        ui->tableView_6->setModel(p.Afficher());
        //notifyUser("Ajout réussi", "Produit ajouté avec succès.", QSystemTrayIcon::Information);
        ui->nom->clear();
        ui->id->clear();
        ui->quantite->clear();
        ui->pv->clear();
        ui->pa->clear();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du produit.");

    }
}
void MainWindow::updateHistoriqueLabel(const QString &historiqueText)
{
    // Assurez-vous que la QLabel est correctement mise à jour avec le texte
    ui->historique->setText(historiqueText);  // Ou selon le nom de votre QLabel
}


void MainWindow::refreshTableView() {
    // Exemple de code pour actualiser le tableau
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM GS_PRODUIT"); // Ou une autre requête pour récupérer les données mises à jour
    ui->tableView_6->setModel(model);
}
QLabel* MainWindow::getHistoriqueLabel()
{
    return ui->historique;  // Assurez-vous que "historiqueLabel" est un QLabel dans votre UI
}

void MainWindow::on_supprimer_clicked() {
    // Étape 1 : Récupérer l'ID du produit à supprimer
    bool ok;
    int idProduit = ui->taper->text().toInt(&ok);  // Récupère l'ID de la QLineEdit

    // Vérifier si l'ID est valide et non nul
    if (!ok || idProduit == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID différent de 0.");
        return;
    }

    // Vérifier si l'ID est positif
    if (idProduit < 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID positif.");
        return;
    }

    // Étape 2 : Vérifier si l'ID existe dans la base de données
    QSqlQuery query;
    query.prepare("SELECT * FROM GS_PRODUIT WHERE id = ?");
    query.addBindValue(idProduit);
    if (!query.exec() || !query.next()) {
        QMessageBox::warning(this, "Erreur", "Produit introuvable. Veuillez réessayer.");
        return;
    }

    // Étape 3 : Supprimer le produit de la base de données
    produit p;
    if (p.Supprimer(idProduit)) {
        // Si la suppression est réussie, afficher un message de succès
        QMessageBox::information(this, "Succès", "Produit supprimé avec succès.");
    } else {
        // Si la suppression échoue, afficher un message d'erreur
        QMessageBox::warning(this, "Erreur", "Échec de la suppression du produit.");
    }

    // Étape 4 : Actualiser la vue pour refléter la suppression
    refreshTableView();  // Actualiser la table ou la vue du produit
}




//
void MainWindow::on_ModifierButton_clicked() {
    // Étape 1 : Récupérer l'ID du produit à modifier
    int idProduit = ui->taper->text().toInt();  // Récupère l'ID de la QLineEdit

    // Vérifier si l'ID est valide
    if (idProduit == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID différent de 0.");
        return;
    }
    if (idProduit < 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID positif.");
        return;
    }

    // Étape 2 : Vérifier si l'ID existe dans la base de données
    QSqlQuery query;
    query.prepare("SELECT * FROM GS_PRODUIT WHERE id = ?");
    query.addBindValue(idProduit);
    if (!query.exec() || !query.next()) {
        QMessageBox::warning(this, "Erreur", "Produit introuvable. Veuillez réessayer.");
        return;
    }

    // Étape 3 : Demander les nouvelles valeurs (prix d'achat, quantité, prix de vente)
    bool ok;
    double nouveauPrixAchat = QInputDialog::getDouble(this, "Nouveau prix d'achat",
                                                      "Entrez le nouveau prix d'achat :",
                                                      query.value("prixdachat").toDouble(),
                                                      0.0, 10000.0, 2, &ok);

    if (!ok || nouveauPrixAchat == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un prix d'achat different de 0.");
        return;
    }

    double nouvelleQuantite = QInputDialog::getDouble(this, "Nouvelle quantité",
                                                      "Entrez la nouvelle quantité :",
                                                      query.value("quantite").toDouble(),
                                                      0.0, 10000.0, 0, &ok);
    if (!ok || nouvelleQuantite == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer une quantité différente de 0.");
        return;
    }


    double nouveauPrixVente = QInputDialog::getDouble(this, "Nouveau prix de vente",
                                                      "Entrez le nouveau prix de vente :",
                                                      query.value("prixdevente").toDouble(),
                                                      0.0, 10000.0, 2, &ok);
    if (!ok || nouveauPrixVente ==0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un prix de vente different de 0.");
        return;
    }

    // Étape 4 : Vérification de la validité des valeurs saisies
    if (nouveauPrixAchat <= 0 || nouvelleQuantite <= 0 || nouveauPrixVente <= 0) {
        QMessageBox::warning(this, "Erreur", "Les valeurs saisies doivent être positives.");
        return;
    }

    // Étape 5 : Mise à jour des valeurs dans la base de données
    query.prepare("UPDATE GS_PRODUIT SET prixdachat = ?, quantite = ?, prixdevente = ? WHERE id = ?");
    query.addBindValue(nouveauPrixAchat);
    query.addBindValue(nouvelleQuantite);
    query.addBindValue(nouveauPrixVente);
    query.addBindValue(idProduit);

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Produit modifié avec succès.");
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la mise à jour du produit : " + query.lastError().text());
    }

    // Étape 6 : Actualiser le tableau pour refléter les changements
    refreshTableView();  // Appelle une fonction qui met à jour ta vue (tableau, liste, etc.)
}



//




void MainWindow::on_rechercheri_clicked() {

    bool ok;
    int idRecherche = ui->lineEdit->text().toInt(&ok); // "lineEdit_id" est un exemple, utilisez l'ID réel de votre champ QLineEdit
    if (!ok) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide.");
        return;
    }
    produit prod;
    if (prod.rechercherParId(idRecherche)) {
        QMessageBox::information(this, "Produit trouvé", "Le produit avec l'ID " + QString::number(idRecherche) + " existe.");
    } else {
        QMessageBox::warning(this, "Produit non trouvé", "Aucun produit trouvé avec l'ID " + QString::number(idRecherche));
    }
}



//
void MainWindow::on_rechercherq_clicked() {

    bool ok;
    int quantiteRecherche= ui->lineEdit->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer une quantite valide.");
        return;
    }
    produit prod;
    if (prod.rechercheQuantite(quantiteRecherche)) {
        QMessageBox::information(this, "Produit trouvé", "Le produit avec le quantite " + QString::number(quantiteRecherche) + " existe.");
    } else {
        QMessageBox::warning(this, "Produit non trouvé", "Aucun produit trouvé avec le quantite " + QString::number(quantiteRecherche));
    }
}
//

void MainWindow::on_recherchern_clicked() {
    QString nomRecherche = ui->lineEdit->text();  // Récupérer le texte saisi par l'utilisateur

    if (nomRecherche.isEmpty()) {  // Vérifier si le champ de recherche est vide
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un nom.");
        return;
    }

    produit prod;
    if (prod.rechercherParNom(nomRecherche)) {
        QMessageBox::information(this, "Produit trouvé", "Le produit avec le nom '" + nomRecherche + "' existe.");
    } else {
        QMessageBox::warning(this, "Produit non trouvé", "Aucun produit trouvé avec le nom '" + nomRecherche + "'.");
    }
}







void MainWindow::on_Update_clicked() {
    QSqlQuery query;
    query.prepare("SELECT id, nom, quantite FROM GS_PRODUIT WHERE quantite = 0");  // Recherche des produits avec une quantité de 0
    if (query.exec()) {
        bool foundZeroQuantity = false;
        while (query.next()) {
            int id = query.value(0).toInt();
            QString nom = query.value(1).toString();

            // Afficher un message de notification
            QMessageBox::information(this, "Produit à quantité 0",
                                     QString("Le produit \"%1\" (ID: %2) a une quantité de 0.").arg(nom).arg(id));

            // Mettre à jour la base de données (optionnel) - par exemple, réapprovisionner le produit à 10
            QSqlQuery updateQuery;
            updateQuery.prepare("UPDATE GS_PRODUIT SET quantite = 10 WHERE id = :id");
            updateQuery.bindValue(":id", id);
            if (updateQuery.exec()) {
                qDebug() << "Quantité mise à jour pour le produit avec ID:" << id;
            } else {
                qDebug() << "Erreur de mise à jour pour le produit avec ID:" << id;
            }

            foundZeroQuantity = true;
        }

        if (!foundZeroQuantity) {
            QMessageBox::information(this, "Aucune mise à jour", "Il n'y a aucun produit avec une quantité de 0.");
        }

    } else {
        qDebug() << "Erreur de requête pour rechercher les produits à quantité 0: " << query.lastError().text();
        QMessageBox::critical(this, "Erreur", "Erreur lors de la recherche des produits à quantité 0.");
    }}
void MainWindow::on_exporter_clicked()
{
    // Ouvrir une boîte de dialogue pour sélectionner l'emplacement de sauvegarde
    QString fileName = QFileDialog::getSaveFileName(this, tr("Exporter en PDF"), "", "*.pdf");

    if (fileName.isEmpty()) {
        return; // Si aucun fichier n'est sélectionné
    }

    QPdfWriter pdfWriter(fileName);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setResolution(200); // Résolution de 200 DPI

    QPainter painter(&pdfWriter);
    painter.setRenderHint(QPainter::Antialiasing);

    // Définir la police pour le titre
    QFont titleFont;
    titleFont.setPointSize(20); // Taille plus grande pour le titre
    titleFont.setBold(true);
    painter.setFont(titleFont);

    // Positionner et dessiner le titre
    QString title = "Liste des produits (Quantité = 0)";
    int yPosition = 50; // Position verticale pour le titre
    painter.drawText(100, yPosition, pdfWriter.width() - 200, 50, Qt::AlignCenter, title);

    // Ajuster yPosition pour laisser de l'espace après le titre
    yPosition += 120; // Ajustez cette valeur pour contrôler l'espace après le titre

    // Définir les dimensions du tableau
    QFont font;
    font.setPointSize(14); // Taille de police pour une meilleure lisibilité
    painter.setFont(font);

    QFontMetrics fontMetrics(font);
    int cellHeight = fontMetrics.height() + 20; // Hauteur des cellules
    int columnCount = ui->tableView_5->model()->columnCount();

    // Calcul de la largeur des cellules pour remplir la page A4
    int cellWidth = pdfWriter.width() / columnCount;

    // Calcul pour centrer le tableau horizontalement
    int tableWidth = columnCount * cellWidth;  // Largeur totale du tableau
    int pageWidth = pdfWriter.width();         // Largeur de la page
    int xStart = (pageWidth - tableWidth) / 2; // Position horizontale de départ

    // Dessiner l'en-tête des colonnes avec fond vert clair
    painter.setBrush(QColor(144, 238, 144)); // Vert clair pour l'en-tête
    int xPosition = xStart;
    for (int col = 0; col < columnCount; ++col) {
        QString headerData = ui->tableView_5->model()->headerData(col, Qt::Horizontal).toString();
        painter.drawRect(xPosition, yPosition, cellWidth, cellHeight); // Cadre de la cellule d'en-tête
        painter.drawText(xPosition, yPosition, cellWidth, cellHeight, Qt::AlignCenter, headerData);
        xPosition += cellWidth; // Déplacer horizontalement pour la prochaine cellule
    }

    painter.setBrush(Qt::NoBrush); // Enlever le pinceau après avoir dessiné l'en-tête
    yPosition += cellHeight; // Déplacer la position verticale après l'en-tête

    // Filtrer les lignes pour ne dessiner que celles dont la quantité est égale à 0
    int rowCount = ui->tableView_5->model()->rowCount();
    for (int row = 0; row < rowCount; ++row) {
        // Récupérer la quantité de chaque produit (en supposant que la quantité est dans la 4e colonne, ajustez si nécessaire)
        QString quantityData = ui->tableView_5->model()->data(ui->tableView_5->model()->index(row, 4)).toString();  // 4 est l'index de la colonne "quantité"

        if (quantityData == "0") {  // Filtrer si la quantité est égale à 0
            xPosition = xStart; // Réinitialiser la position horizontale pour chaque ligne

            for (int col = 0; col < columnCount; ++col) {
                QString cellData = ui->tableView_5->model()->data(ui->tableView_5->model()->index(row, col)).toString();
                painter.drawRect(xPosition, yPosition, cellWidth, cellHeight); // Cadre de la cellule
                painter.drawText(xPosition, yPosition, cellWidth, cellHeight, Qt::AlignCenter, cellData);
                xPosition += cellWidth; // Déplacer horizontalement pour la prochaine cellule
            }

            yPosition += cellHeight; // Déplacer verticalement pour la prochaine ligne
        }
    }

    painter.end(); // Fin de la peinture du PDF

    // Message de confirmation
    QMessageBox::information(this, "Exportation réussie", "L'affichage a été exporté en PDF avec succès.");
}

void MainWindow::on_pushButtonCalculer_clicked() {
    // Récupérer l'ID du produit depuis le champ de texte
    bool conversionOk;
    int produitID = ui->taper->text().toInt(&conversionOk);  // Conversion du texte en entier

    // Si l'ID n'est pas valide ou si la conversion a échoué
    if (!conversionOk || produitID <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM GS_PRODUIT WHERE id = ?");
    query.addBindValue(produitID);
    if (!query.exec() || !query.next()) {
        QMessageBox::warning(this, "Erreur", "Produit introuvable. Veuillez réessayer.");
        return;
    }

    // Récupérer les données du produit
    QString nom = query.value(0).toString();
    double prixdachat = query.value(1).toDouble();
    double prixdevente = query.value(2).toDouble();
    int quantite = query.value(3).toInt();

    // Vérification de la quantité
    if (quantite == 0) {
        // Si la quantité est 0, on affiche un message de rupture de stock
        QMessageBox::warning(this, "Rupture de Stock", QString("Le produit \"%1\" est en rupture de stock.").arg(nom));
    } else {
        // Calcul du résultat : (prixdevente - prixdachat) * quantite
        double resultat = (prixdevente - prixdachat) * quantite;

        // Utiliser QString::number pour convertir le double en chaîne et afficher
        QString resultMessage = QString("Produit: %1\nID: %3\nPrix d'achat: %4\nPrix de vente: %5\nQuantité: 9\nRésultat du calcul: (%6 - %8) * %5 = %9")
                                    .arg(nom)               // Nom du produit
                                    .arg(produitID)         // ID du produit
                                    .arg(prixdachat)        // Prix d'achat
                                    .arg(prixdevente)       // Prix de vente
                                    .arg(quantite)          // Quantité
                                    .arg(prixdevente)       // Prix de vente (utilisé dans la formule)
                                    .arg(prixdachat)        // Prix d'achat (utilisé dans la formule)
                                    .arg(quantite)          // Quantité (utilisée dans la formule)
                                    .arg(resultat);         // Résultat du calcul

        // Afficher le message avec le calcul
        QMessageBox::information(this, "Calcul du Résultat", resultMessage);
    }
}

void MainWindow::on_pb_historique_clicked()
{
    // Afficher l'historique complet
    ui->historique->setText(ui->historique->text());
}

QString MainWindow::getHistorique()
{
    // Récupérer l'historique à partir d'une source (ici, pour simplifier, on le génère directement)
    // Vous pouvez adapter cette méthode pour récupérer des données d'une base de données ou autre
    QString historique = "Historique des actions:\n";
    QDateTime currentDateTime = QDateTime::currentDateTime();
    historique += currentDateTime.toString("yyyy-MM-dd hh:mm:ss") + " - Consultation de l'historique\n";

    // Vous pouvez aussi ajouter des actions passées ici, par exemple en récupérant des données d'une base de données
    return historique;
}


void MainWindow::on_sort_clicked()
{
    // Clear the model associated with the QTableView
    QSqlQueryModel *model = new QSqlQueryModel(this);

    // Query the database to fetch sorted stock data by stock ID (ascending order)
    QSqlQuery query;
    query.prepare("SELECT id, nom, quantite, prixdevente, prixdachat "
                  "FROM GS_PRODUIT "
                  "ORDER BY id ASC");  // Tri croissant par ID

    if (query.exec()) {
        model->setQuery(query); // Set the query to the model
        ui->tableView_6->setModel(model); // Set the model to the QTableView

        QMessageBox::information(this, "Sort Success", "Stock records sorted by ID.");
    } else {
        QMessageBox::critical(this, "Sort Error", "Failed to sort stocks by ID. " + query.lastError().text());

    }
}


void MainWindow::on_triequantite_clicked()
{
    // Clear the model associated with the QTableView
    QSqlQueryModel *model = new QSqlQueryModel(this);

    // Query the database to fetch sorted stock data by stock ID (ascending order)
    QSqlQuery query;
    query.prepare("SELECT id, nom, quantite, prixdevente, prixdachat "
                  "FROM GS_PRODUIT "
                  "ORDER BY  quantite ASC");  // Tri croissant par ID

    if (query.exec()) {
        model->setQuery(query); // Set the query to the model
        ui->tableView_6->setModel(model); // Set the model to the QTableView

        QMessageBox::information(this, "Sort Success", "Stock records sorted by quantite.");
    } else {
        QMessageBox::critical(this, "Sort Error", "Failed to sort stocks by quantite. " + query.lastError().text());

    }
}

void MainWindow::on_trieprix_clicked()
{
    // Clear the model associated with the QTableView
    QSqlQueryModel *model = new QSqlQueryModel(this);

    // Query the database to fetch sorted stock data by stock ID (ascending order)
    QSqlQuery query;
    query.prepare("SELECT id, nom, quantite, prixdevente, prixdachat "
                  "FROM GS_PRODUIT "
                  "ORDER BY  prixdachat ASC");  //

    if (query.exec()) {
        model->setQuery(query); // Set the query to the model
        ui->tableView_6->setModel(model); // Set the model to the QTableView

        QMessageBox::information(this, "Sort Success", "Stock records sorted by prixdachat.");
    } else {
        QMessageBox::critical(this, "Sort Error", "Failed to sort stocks by prixdachat. " + query.lastError().text());

    }
}

void MainWindow::on_btn_statistiques_clicked()
{
    // Requête SQL pour récupérer les données des produits (nom et quantités vendues)
    QSqlQuery query;
    query.prepare("SELECT nom, SUM(quantite) AS quantite_totale "
                  "FROM GS_PRODUIT "
                  "GROUP BY nom");

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête:" << query.lastError().text();
        return;
    }

    // Création du QBarSet pour le graphique à barres
    QBarSet *set = new QBarSet("Quantités");
    QStringList categories;  // Liste des produits

    while (query.next()) {
        QString nomProduit = query.value(0).toString();  // Nom du produit
        int quantite = query.value(1).toInt();  // Quantité totale vendue

        categories << nomProduit;  // Ajouter le nom du produit aux catégories
        *set << quantite;  // Ajouter la quantité au QBarSet
    }

    // Vérification que des données ont été récupérées
    if (set->count() == 0) {
        QMessageBox::information(this, "Statistiques", "Aucune donnée trouvée.");
        return;
    }

    // Trouver la valeur maximale pour l'axe Y
    double maxValue = 0;
    for (int i = 0; i < set->count(); ++i) {
        double value = set->at(i);
        if (value > maxValue) {
            maxValue = value;
        }
    }

    // Création de la série et du graphique à barres
    QBarSeries *series = new QBarSeries();
    series->append(set);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Quantités de produits vendus");

    // Configuration de l'axe des catégories (produits)
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Configuration de l'axe des valeurs (quantités)
    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, maxValue);  // Plage Y basée sur la valeur maximale
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Création du QChartView pour afficher le graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Affichage du graphique dans un layout existant
    if (ui->layout_statistiques->layout() != nullptr) {
        delete ui->layout_statistiques->layout();
    }
    QVBoxLayout *layout = new QVBoxLayout(ui->layout_statistiques);
    layout->addWidget(chartView);
    ui->layout_statistiques->setLayout(layout);
}
void MainWindow::appendHistorique(const QString &historiqueText)
{
    // Ajoutez l'historique à la fin du texte existant dans le label
    ui->historique->setText(ui->historique->text() + "\n" + historiqueText);
}





