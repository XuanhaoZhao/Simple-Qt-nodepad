#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QFileDialog>
#include <QString>
#include <QPrinter>
#include <QPrintDialog>
#include <QFont>
#include <QColor>
#include <QFontDialog>
#include <QColorDialog>
#include <QDateTime>
#include <QDesktopServices>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_As_triggered();
    void on_actionPrint_triggered();
    void on_actionExit_triggered();
    void on_actionCopy_triggered();
    void on_actionPaste_triggered();
    void on_actionCut_triggered();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
    void on_actionFont_triggered();
    void on_actionColor_triggered();
    void on_actionDate_triggered();
    void on_actionAuthor_triggered();
    void on_actionQt_triggered();
private:
    Ui::MainWindow *ui;
    QString currentFile = "";
};
#endif // MAINWINDOW_H
