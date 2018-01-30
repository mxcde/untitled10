#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include<QAction>
#include<QFile>
#include<QString>
#include<QFileDialog>

#include<QClipboard>
#include<QTextDocumentWriter>
#include<QComboBox>
#include<QTextEdit>

#include<QTime>
#include<QElapsedTimer>
#include<QtPrintSupport/QPrintPreviewDialog>
#include<QtPrintSupport/QPrintDialog>

#include<QtPrintSupport/QPrinter>
#include<QHBoxLayout>

#include<QTextBlockFormat>

#include<QTextCharFormat>
#include<QColor>
#include<QColorDialog>
#include <QTextCursor>

#include<QFontDatabase>
#include<QFontComboBox>


#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>
#include <QSettings>
#include <QTextStream>
#include <QApplication>
#include <QTranslator>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public: //// menu

    void file();
    void edit();
    void formai();
    void help();
public:
    //void
public:////////  combobox
    void  firstbox();
    void  secondbox();
    void  thnox();

public: ////  text
    void textedit();


    void setCurrentFile1(const QString &fileName);
    void updateRecentFileActions1();
    QString strippedName1(const QString &fullFileName);

private slots:
    void on_toolButton_clicked();
    void newfile();
    void openfile();
    bool filesave();
    bool filesaveas();
    void fileclose();
    void loadFile1(const QString &fileName);
    void newfile1();

    void fileprint();

    void filePrintPreview();
    void printpreview(QPrinter* printer);


    bool filePrintPdf();
    void openRecentFile1();

    void initLansge();



    void textBold();
    void textUnderline();
    void textItalic();
    void textfamily(const QString &f); ///    ??
    void textsize(const QString &p);
    void textstyle(int styleIndex);
    void textcolor();
    void textAlign(QAction *a);



    void about();
    //void printpreview(QPrinter*);
public:
    bool maybesave();
    void setcurrentfilename(const QString &filename);

private:
    void mergeFormatOnWordOrSelection(const QTextCharFormat &format);
    void colorchanged(const QColor &c);
    Ui::MainWindow *ui;
    QToolBar *tb;
    QToolBar *tb1;
    QToolBar *tb2;
    QToolBar *tb3;
    QTextEdit *Qtext;
    QString filename;



    QAction *td;
    QAction *line;
    QAction *Italic;

    QAction *left0;
    QAction *right0;
    QAction *center0;
    QAction *justify;
    QAction *color;

    QAction *textline;
    QAction *actionUndo,
            *actionRedo;
    QAction *recentFileActions[5];
    QAction *separatorAction1;
};



#endif // MAINWINDOW_H
