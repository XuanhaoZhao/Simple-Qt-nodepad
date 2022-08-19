#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("notepad tab");
    this->setCentralWidget((ui->textEdit));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    currentFile.clear();
    this->setWindowTitle("notepad");
    ui->textEdit->setText("");
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open file");
    QFile file(fileName);
    currentFile = fileName;
    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"Warning","Cannot open file: " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void MainWindow::on_actionSave_As_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Save as ");
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
       QMessageBox::warning(this,"Warning","Cannot open file: " + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}

void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer;
    printer.setPrinterName("Print Name");
    QPrintDialog pDialog(&printer,this);
    if(QDialog::Rejected == pDialog.exec()){
        QMessageBox::warning(this, "Warning", "Cannot access printer");
        return;
    }
    ui->textEdit->print(&printer);
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionFont_triggered()
{
    bool check;
    // get font
    QFont font = QFontDialog::getFont(&check, QFont("Times", 12), this);
    if(true == check){
        // change font
        ui->textEdit->setFont(font);
    }else{
        return;
    }
}

void MainWindow::on_actionColor_triggered()
{
    QColor color = QColorDialog::getColor(Qt::green, this, "Select Color");
         if (color.isValid())
         {
            // change color
            ui->textEdit->setTextColor(color);
         }
         else
         {
           // QMessageBox::information(this,"Error Message","Color is unvalid!       ");
           return;
         }
}

void MainWindow::on_actionDate_triggered()
{
    QDateTime current = QDateTime::currentDateTime();
    QString time = current.toString("yyyy-MM-dd hh:mm:ss");
    ui->textEdit->append(time);
}

void MainWindow::on_actionAuthor_triggered()
{
    QDesktopServices::openUrl(QUrl("https://xuanhaozhao.github.io"));
}

void MainWindow::on_actionQt_triggered()
{
    QMessageBox::aboutQt(this, "AboutQt");
}

