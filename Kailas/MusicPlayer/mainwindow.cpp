#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAudioOutput>
#include <QStyle>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create Media Player and Audio Output
    M_Player = new QMediaPlayer(this);
    M_AudioOutput = new QAudioOutput(this);
    M_Player->setAudioOutput(M_AudioOutput);

    // Set initial volume
    M_AudioOutput->setVolume(ui->horizontalSlider_Volume_Control->value() / 100.0);

    // Set play/pause icons
    ui->pushButton_Play->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->pushButton_Pause->setIcon(style()->standardIcon(QStyle::SP_MediaPause));

    // Apply UI styling
    this->setStyleSheet("background-color: #2E2E2E; color: white;");

    ui->pushButton_Play->setStyleSheet(
        "QPushButton {"
        "background-color: #4CAF50;"
        "color: white;"
        "border-radius: 10px;"
        "padding: 8px;"
        "font-size: 16px;"
        "}"
        "QPushButton:hover { background-color: #45a049; }"
        );

    ui->pushButton_Pause->setStyleSheet(
        "QPushButton {"
        "background-color: #F44336;"
        "color: white;"
        "border-radius: 10px;"
        "padding: 8px;"
        "font-size: 16px;"
        "}"
        "QPushButton:hover { background-color: #d32f2f; }"
        );

    ui->horizontalSlider_Volume_Control->setStyleSheet(
        "QSlider::groove:horizontal {"
        "background: #5a5a5a;"
        "height: 8px;"
        "border-radius: 4px;"
        "}"
        "QSlider::handle:horizontal {"
        "background: #FFD700;"
        "border: 2px solid white;"
        "width: 15px;"
        "margin: -5px 0;"
        "border-radius: 7px;"
        "}"
        );

    ui->lbl_Value_File_Name->setStyleSheet(
        "QLabel {"
        "font-size: 18px;"
        "color: #FFD700;"
        "font-weight: bold;"
        "border: 2px solid white;"
        "border-radius: 5px;"
        "padding: 5px;"
        "background-color: rgba(255, 255, 255, 0.1);"
        "}"
        );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_FIle_triggered()
{
    QString FileName = QFileDialog::getOpenFileName(this, tr("Select Audio File"), "", tr("MP3 Files (*.mp3 *.MP3)"));

    if (FileName.isEmpty()) {
        qDebug() << "No file selected!";
        return;
    }

    qDebug() << "Selected file:" << FileName;

    M_Player->setSource(QUrl::fromLocalFile(FileName));

    QFileInfo File(FileName);
    ui->lbl_Value_File_Name->setText(File.fileName());
}

void MainWindow::on_pushButton_Play_clicked()
{
    if (isPaused) {
        M_Player->play();  // Resume from paused position
    } else {
        M_Player->setPosition(0);  // Start from the beginning if it's a new file
        M_Player->play();
    }
    isPaused = false;
}

void MainWindow::on_pushButton_Pause_clicked()
{
    if (M_Player->playbackState() == QMediaPlayer::PlayingState) {
        M_Player->pause();
        isPaused = true;
    }
}

void MainWindow::on_horizontalSlider_Volume_Control_valueChanged(int value)
{
    M_AudioOutput->setVolume(value / 100.0);
}


