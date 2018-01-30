#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   // tb  = new QToolBar;
   // tb1 = new QToolBar;
    //tb2 = new QToolBar;
    //tb3 = new QToolBar;
    Qtext = new QTextEdit;
   // addToolBar(tb1);

   // addToolBar(tb2);
   // addToolBar(tb3);

    //   tb  换行
  //  tb->setAllowedAreas(Qt::TopToolBarArea|Qt::BottomToolBarArea);
   // addToolBarBreak(Qt::TopToolBarArea);
  //  addToolBar(tb);


  //  setToolButtonStyle(Qt::ToolButtonFollowStyle);
   // file();
  //  edit();
   // formai();
   // help();
    textedit();
   // firstbox();
   // secondbox();
//    thnox();
    //tb->add




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newfile1()
{
    MainWindow *other = new MainWindow;
    other->setMinimumSize(700,900);
    other->show();
}

void MainWindow::file()
{

    QIcon newIcon = QIcon::fromTheme("document-new",
                                     QIcon("C:\\Users\\ZhuQiang\\Documents\\untitled10\\image\\filenew.png"));
    QMenu *menu = new QMenu(tr("File"),this);
    menuBar()->addMenu(menu);
    QAction *a;
    a = new QAction(newIcon,tr("new"),this);
    bool flag=connect(a,SIGNAL(triggered()),this,SLOT(newfile()));
    a->setPriority(QAction::LowPriority);
    tb1->addAction(a);



    menu->addAction(a);
    //menu->addSeparator();

    QAction *b;
    QIcon openIcon = QIcon::fromTheme("document-open",
                                     QIcon("C:\\Users\\ZhuQiang\\Documents\\untitled10\\image\\fileopen.png"));
    b = new QAction(openIcon,tr("open"),this);
    connect(b,SIGNAL(triggered()),this,SLOT(openfile()));
    menu->addAction(b);
    tb1->addAction(b);
    menu->addSeparator();

    QAction *c;
    QIcon saveIcon = QIcon::fromTheme("document-save",
                                     QIcon("C:\\Users\\ZhuQiang\\Documents\\untitled10\\image\\filesave.png"));
    c = new QAction(saveIcon,tr("save"),this);
    connect(c,SIGNAL(triggered()),this,SLOT(filesave()));
    menu->addAction(c);
    tb1->addAction(c);
    //menu->addSeparator();

    QAction *d;
    d = new QAction(tr("saveas"),this);
    connect(d,SIGNAL(triggered()),this,SLOT(filesaveas()));
    menu->addAction(d);
    menu->addSeparator();

    QAction *f;
    QIcon printIcon = QIcon::fromTheme("document-save",
                                     QIcon("C:\\Users\\ZhuQiang\\Documents\\untitled10\\image\\fileprint.png"));
    f = new QAction(printIcon,tr("print"),this);
   // connect(f,SIGNAL(triggered()),this,SLOT(filesaveas()));
    menu->addAction(f);
    tb1->addAction(f);
    connect(f,SIGNAL(triggered()),this,SLOT(fileprint()));

    QAction *h;
    QIcon printviewIcon = QIcon::fromTheme("document-save",
                                     QIcon("C:\\Users\\ZhuQiang\\Documents\\untitled10\\image\\fileprint.png"));
    h =new QAction(printviewIcon,tr("printview"),this);
    menu->addAction(h);
    tb1->addAction(h);
    connect(h,SIGNAL(triggered()),this,SLOT(filePrintPreview()));

    QAction *g;
    QIcon pdfIcon = QIcon::fromTheme("document-save",
                                     QIcon("C:\\Users\\ZhuQiang\\Documents\\untitled10\\image\\exportpdf.png"));
    g = new QAction(pdfIcon,tr("Export PDF"),this);
    connect(g,SIGNAL(triggered()),this,SLOT(filePrintPdf()));
    menu->addAction(g);
    tb1->addAction(g);
    menu->addSeparator();


    QAction *e;
    e = new QAction(tr("quit"),this);
    connect(e,SIGNAL(triggered()),this,SLOT(close()));
    menu->addAction(e);
   // menu->addSeparator();

    for (int i = 0; i < 5; ++i) {
        recentFileActions[i] = new QAction(this);
        recentFileActions[i]->setVisible(false);
       connect(recentFileActions[i], SIGNAL(triggered()),
                this, SLOT(openRecentFile1()));
    }

    separatorAction1 = menu->addSeparator();

    for (int i = 0; i < 5; ++i)
        menu->addAction(recentFileActions[i]);





    return ;

}

void MainWindow::edit() /////       点击按钮没有反应
{

    QMenu *menu1 = new QMenu(tr("edit"),this);
    menuBar()->addMenu(menu1);


    QAction *b;
    QIcon undoIcon = QIcon::fromTheme("document-save",
                                     QIcon("C:\\Users\\ZhuQiang\\Documents\\untitled10\\image\\editundo.png"));
    b =actionUndo= new QAction(undoIcon,tr("undo"),this);

    b->setShortcut(QKeySequence::Undo);
    menu1->addAction(b);
    tb2->addAction(b);
    menu1->addSeparator();
    connect(actionUndo,SIGNAL(triggered()),Qtext,SLOT(undo()));


    QIcon redoIcon = QIcon::fromTheme("document-save",
                                     QIcon("C:\\Users\\ZhuQiang\\Documents\\untitled10\\image\\editredo.png"));
    b = actionRedo =new QAction(redoIcon,tr("redo"),this);
    menu1->addAction(b);
    b->setPriority(QAction::LowPriority);
    b->setShortcut(QKeySequence::Redo);
    tb2->addAction(b);
    menu1->addSeparator();
    connect(actionRedo,SIGNAL(triggered()),Qtext,SLOT(redo()));

    QAction *d;
    QIcon cutIcon = QIcon::fromTheme("document-save",
                                     QIcon("C:\\Users\\ZhuQiang\\Documents\\untitled10\\image\\editcut.png"));
    d = new QAction(cutIcon,tr("cut"),this);
    d->setShortcut(QKeySequence::Cut);
    menu1->addAction(d);
    tb2->addAction(d);
    menu1->addSeparator();
    connect(d,SIGNAL(triggered()),Qtext,SLOT(cut()));

    QAction *e;
    QIcon copyIcon = QIcon::fromTheme("document-save",
                                     QIcon("C:\\Users\\ZhuQiang\\Documents\\untitled10\\image\\editcopy.png"));
    e = new QAction(copyIcon,tr("copy"),this);
    e->setShortcut(QKeySequence::Copy);
    menu1->addAction(e);
    tb2->addAction(e);
    menu1->addSeparator();
    connect(e,SIGNAL(triggered()),Qtext,SLOT(copy()));

    QAction *f;
    QIcon pasteIcon = QIcon::fromTheme("document-save",
                                     QIcon("C:\\Users\\ZhuQiang\\Documents\\untitled10\\image\\editpaste.png"));
    f = new QAction(pasteIcon,tr("paste"),this);
    f->setShortcut(QKeySequence::Paste);
    tb2->addAction(f);
    menu1->addAction(f);
    connect(f,SIGNAL(triggered()),Qtext,SLOT(paste()));


}

void MainWindow::formai()
{
    QMenu *menu1 = new QMenu(tr("format"),this);
    menuBar()->addMenu(menu1);
    //menu1->addSeparator();

    QIcon boldeIcon = QIcon::fromTheme("document-textbold",
                                     QIcon("C:\\Users\\ZhuQiang\\Documents\\untitled10\\image\\textbold.png"));
    td = new QAction(boldeIcon,tr("bold"),this);
    td->setShortcut(Qt::CTRL+Qt::Key_B);
    td->setPriority(QAction::LowPriority);
    QFont  Bold;
    Bold.setBold(true);
    td->setFont(Bold);
    connect(td,SIGNAL(triggered()),this,SLOT(textBold()));

    tb3->addAction(td);
    menu1->addAction(td);
    td->setCheckable(true);




    QIcon ItalicIcon = QIcon::fromTheme("document-save",
                                     QIcon("C:\\Users\\ZhuQiang\\Documents\\untitled10\\image\\textitalic.png"));
    Italic = new QAction(ItalicIcon,tr("Italic"),this);
    Italic->setPriority(QAction::LowPriority);
    Italic->setShortcut(Qt::CTRL+Qt::Key_I);
    QFont italic;
    italic.setItalic(true);
    Italic->setFont(italic);
    connect(Italic,SIGNAL(triggered()),this,SLOT(textItalic()));

    menu1->addAction(Italic);
    tb3->addAction(Italic);
    Italic->setCheckable(true);





    QIcon UnderLineIcon = QIcon::fromTheme("document-save",
                                     QIcon("C:\\Users\\ZhuQiang\\Documents\\untitled10\\image\\textunder.png"));
    line = new QAction(UnderLineIcon,tr("UnderLine"),this);
    line->setPriority(QAction::LowPriority);
    line->setShortcut(Qt::CTRL+Qt::Key_U);

    QFont  undline;
    undline.setUnderline(true);
    line->setFont(undline);
    connect(line,SIGNAL(triggered()),this,SLOT(textUnderline()));

    menu1->addAction(line);
    tb3->addAction(line);
    line->setCheckable(true);


    tb3->addSeparator();
    menu1->addSeparator();


    QActionGroup  *grp = new QActionGroup(this);
    connect(grp,SIGNAL(triggered(QAction*)),this,SLOT(textAlign(QAction*)));

    if(QApplication::isLeftToRight())
    {
        left0 = new QAction(QIcon::fromTheme("justify-left",QIcon("C:\\Users\\ZhuQiang\\Documents\\untitled10\\image\\textleft.png")),
                            tr("&Left"),grp);
        center0 =new QAction(QIcon::fromTheme("justify-center",QIcon("C:\\Users\\ZhuQiang\\Documents\\untitled10\\image\\textcenter.png")),
                             tr("&Center"),grp);

        right0 = new QAction(QIcon::fromTheme("justify-right",QIcon("C:\\Users\\ZhuQiang\\Documents\\untitled10\\image\\textright.png")),
                             tr("&Right"),grp);
    }
    else
    {
        right0 = new QAction(QIcon::fromTheme("justify-right",QIcon("C:\\Users\\ZhuQiang\\Documents\\untitled10\\image\\textright.png")),
                                 tr("&Right"),grp);
        center0 =new QAction(QIcon::fromTheme("justify-center",QIcon("C:\\Users\\ZhuQiang\\Documents\\untitled10\\image\\textcenter.png")),
                             tr("&Center"),grp);
        left0 = new QAction(QIcon::fromTheme("justify-left",QIcon("C:\\Users\\ZhuQiang\\Documents\\untitled10\\image\\textleft.png")),
                            tr("&Left"),grp);
    }

        QIcon justifyIcon = QIcon::fromTheme("document-save",
                                     QIcon("C:\\Users\\ZhuQiang\\Documents\\untitled10\\image\\textjustify.png"));
        justify = new QAction(justifyIcon,tr("Justify"),this);

        left0->setShortcut(Qt::CTRL+Qt::Key_L);
        left0->setCheckable(true);
        left0->setPriority(QAction::LowPriority);

        right0->setShortcut(Qt::CTRL+Qt::Key_R);
        right0->setCheckable(true);
        right0->setPriority(QAction::LowPriority);

        center0->setShortcut(Qt::CTRL+Qt::Key_E);
        center0->setCheckable(true);
        center0->setPriority(QAction::LowPriority);

        justify->setShortcut(Qt::CTRL+Qt::Key_J);
        justify->setCheckable(true);
        justify->setPriority(QAction::LowPriority);

        tb3->addActions(grp->actions());
        menu1->addActions(grp->actions());

        menu1->addAction(justify);
        tb3->addAction(justify);


        menu1->addSeparator();

        QPixmap pix(16,16);
        pix.fill(Qt::black);
        color = new QAction(pix,tr("Color"),this);
        connect(color,SIGNAL(triggered()),this,SLOT(textcolor()));
        tb3->addAction(color);
        menu1->addAction(color);





/*


    QIcon LeftIcon = QIcon::fromTheme("document-save",
                                     QIcon("C:\\Users\\ZhuQiang\\Documents\\untitled10\\image\\textleft.png"));
    left0 = new QAction(LeftIcon,tr("Left"),this);
    left0->setPriority(QAction::LowPriority);
    left0->setShortcut(Qt::CTRL+Qt::Key_L);
    QFont left1;
    //left1.set

    menu1->addAction(left0);
    tb3->addAction(left0);

    QAction *f;
    QIcon rightIcon = QIcon::fromTheme("document-save",
                                     QIcon("C:\\Users\\ZhuQiang\\Documents\\untitled10\\image\\textright.png"));
    f = new QAction(rightIcon,tr("Right"),this);
    menu1->addAction(f);
    tb3->addAction(f);

    QAction *g;
    QIcon centerIcon = QIcon::fromTheme("document-save",
                                     QIcon("C:\\Users\\ZhuQiang\\Documents\\untitled10\\image\\textcenter.png"));
    g = new QAction(centerIcon,tr("Center"),this);
    menu1->addAction(g);
    tb3->addAction(g);

    QAction *h;
    QIcon justifyIcon = QIcon::fromTheme("document-save",
                                     QIcon("C:\\Users\\ZhuQiang\\Documents\\untitled10\\image\\textjustify.png"));
    h = new QAction(justifyIcon,tr("Justify"),this);
    menu1->addAction(h);
    tb3->addAction(h);

    tb3->addSeparator();
    menu1->addSeparator();

    QAction *i;
    QPixmap pix(16,16);
    pix.fill(Qt::black);
    i = new QAction(pix,tr("Color"),this);
    menu1->addAction(i);
    tb3->addAction(i);
*/


}

void MainWindow::help()
{
    QMenu *menu1 = new QMenu(tr("help"),this);
    menuBar()->addMenu(menu1);
    QAction *b;
    b = new QAction(tr("about"),this);
    menu1->addAction(b);
    connect(b,SIGNAL(triggered()),this,SLOT(about()));

    QAction *c;
    c = new QAction(tr("about qt"),this);
    menu1->addAction(c);
    connect(c,SIGNAL(triggered()),qApp,SLOT(aboutQt()));
}

void MainWindow::firstbox()
{
   QHBoxLayout *layout = new QHBoxLayout;
   QComboBox *box1 =new QComboBox;
   tb->addWidget(box1);
   box1->setMinimumSize(80,5);
   box1->addItem("Standard");
   box1->addItem("Bullet List (Disc)");
   box1->addItem("Bullet List (Circle)");
   box1->addItem("Bullet List (Square)");
   box1->addItem("Ordered List (Decimal)");
   box1->addItem("Ordered List (Alpha lower)");
   box1->addItem("Ordered List (Alpha upper)");
   box1->addItem("Ordered List (Roman lower)");
   box1->addItem("Ordered List (Roman upper)");;

   connect(box1,SIGNAL(activated(int)),this,SLOT(textstyle(int)));

}

void MainWindow::secondbox()
{
    QFontComboBox *box1 =new QFontComboBox;
    tb->addWidget(box1);
    box1->setMinimumSize(80,5);
    connect(box1,SIGNAL(activated(QString)),this,SLOT(textfamily(QString)));


}

void MainWindow::thnox()
{
    QComboBox *box1 =new QComboBox;
    tb->addWidget(box1);
    box1->setEditable(true);

    QFontDatabase db;
    foreach (int size, db.standardSizes())
    {
      box1->addItem(QString::number(size));
    }
    connect(box1,SIGNAL(activated(QString)),this,SLOT(textsize(QString)));
    box1->setCurrentIndex(box1->findText(QString::number(QApplication::font().pointSize())));
}

void MainWindow::textedit()
{
   setCentralWidget(Qtext);

}

void MainWindow::setCurrentFile1(const QString &fileName)
{
/*
 *
 *
 *    curFile = fileName;
     if (curFile.isEmpty())
         setWindowTitle(tr("Recent Files"));
     else
         setWindowTitle(tr("%1 - %2").arg(strippedName(curFile))
                                     .arg(tr("Recent Files")));
     QSettings settings("Trolltech", "Recent Files Example");
     QStringList files = settings.value("recentFileList").toStringList();
     files.removeAll(fileName);
     files.prepend(fileName);
     while (files.size() > MaxRecentFiles)
         files.removeLast();
     settings.setValue("recentFileList", files);
     foreach (QWidget *widget, QApplication::topLevelWidgets()) {
         MainWindow *mainWin = qobject_cast<MainWindow *>(widget);
         if (mainWin)
             mainWin->updateRecentFileActions();
     }
 *
 */
    filename = fileName;
    if (filename.isEmpty())
    {
        setWindowTitle(tr("recent files"));
    }
    else
    {
        setWindowTitle(tr("%1 - %2").arg(strippedName1(filename)).arg(tr("recent files")));
    }
    QSettings settings("Trolltech ","recent fileexamples");
    QStringList files = settings.value("recentfilelist").toStringList();
    files.removeAll(fileName);
    files.prepend(fileName);
    while(files.size() > 5)
    {
        files.removeLast();
    }
    settings.setValue("recentfilelist",files);
    foreach (QWidget *widget,QApplication::topLevelWidgets())
    {
        MainWindow *mainwin = qobject_cast<MainWindow *>(widget);
        if(mainwin)
        {
            mainwin->updateRecentFileActions1();
        }
    }






}

void MainWindow::updateRecentFileActions1()
{
/*
 * QSettings settings("Trolltech", "Recent Files Example");
     QStringList files = settings.value("recentFileList").toStringList();
     int numRecentFiles = qMin(files.size(), (int)MaxRecentFiles);
     for (int i = 0; i < numRecentFiles; ++i) {
         QString text = tr("&%1 %2").arg(i + 1).arg(strippedName(files[i]));
         recentFileActions[i]->setText(text);
         recentFileActions[i]->setData(files[i]);
         recentFileActions[i]->setVisible(true);
     }
     for (int j = numRecentFiles; j < MaxRecentFiles; ++j)
         recentFileActions[j]->setVisible(false);
     separatorAction->setVisible(numRecentFiles > 0);
 *
 *
 *
 */

    QSettings settings("Trolltech","Recent files example");
    QStringList files = settings.value("recentfilelist").toStringList();
    int numrecentfiles = qMin(files.size(),5);
    for (int i=0;i<numrecentfiles;i++)
    {
        QString text = tr("&%1 %2").arg(i+1).arg(strippedName1(files[i]));
        recentFileActions[i]->setText(text);
        recentFileActions[i]->setData(files[i]);
        recentFileActions[i]->setVisible(true);
    }
    for (int j = numrecentfiles;j < 5;j++)
    {
        recentFileActions[j]->setVisible(false);
    }
    separatorAction1->setVisible(numrecentfiles>0);
}

QString MainWindow::strippedName1(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}



void MainWindow::on_toolButton_clicked()
{


}

void MainWindow::newfile()
{
//////////  first  save()
/// clear()   ->  new
///
    if (maybesave())////    判断是否需要保存
    {

    setcurrentfilename(QString());

    QElapsedTimer t;
    t.start();
    while(t.elapsed()<2000)
        QCoreApplication::processEvents();


    Qtext->clear();


    return ;
    }
}

void MainWindow::openfile()
{
  QString fn = QFileDialog::getOpenFileName(this,tr(""),QString(),tr("HTML-Files(*htm*.html);;All Files(*)"));
  if(!fn.isEmpty())
  {
      ///  load
  }
}

bool MainWindow::filesave()
{
    if(filename.isEmpty())
    {
        return filesaveas();
    }
    QTextDocumentWriter writer(filename);
    bool success = writer.write(Qtext->document());
    if(success)
    {
        Qtext->document()->setModified(false);
    }
    //setCurrentFile1(fn);
    return success;




}

bool MainWindow::filesaveas()
{
    QString fn =QFileDialog::getSaveFileName(this,tr("save as.."),QString(),
                                             tr("ODF files (*.odt);;HTML-Files(*.htm* .html;;All Files(*)"));
    if(fn.isEmpty())
    {
        return false;
    }
    if(!(fn.endsWith(".odt",Qt::CaseInsensitive )|| fn.endsWith(".htm",Qt::CaseInsensitive) || fn.endsWith(".html",Qt::CaseInsensitive)))
    {
        fn +=".odt";
    }
    setCurrentFile1(fn);
    return filesave();


}

void MainWindow::fileclose()
{

}

void MainWindow::loadFile1(const QString &fileName)
{
    /*
      File file(fileName);
     if (!file.open(QFile::ReadOnly | QFile::Text)) {
         QMessageBox::warning(this, tr("Recent Files"),
                              tr("Cannot read file %1:\n%2.")
                              .arg(fileName)
                              .arg(file.errorString()));
         return;
     }
     QTextStream in(&file);
     QApplication::setOverrideCursor(Qt::WaitCursor);
     textEdit->setPlainText(in.readAll());
     QApplication::restoreOverrideCursor();
     setCurrentFile(fileName);
     statusBar()->showMessage(tr("File loaded"), 2000);
    */

    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
       QMessageBox::warning(this,tr("Recent Files"),
           tr("cannot read files %1:\n%2.")
           .arg(fileName)
              .arg(file.errorString()));
       return ;
    }
    QTextStream in(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    Qtext->setPlainText(in.readAll());
    QApplication::restoreOverrideCursor();
    setCurrentFile1(fileName);
    statusBar()->showMessage(tr("file loaded"),2000);



}

void MainWindow::fileprint()
{
#ifndef QT_NO_PRINTER
    QPrinter printer(QPrinter::HighResolution);
    QPrintDialog *dlg = new QPrintDialog(&printer,this);
    if(Qtext->textCursor().hasSelection())
    {
        dlg->addEnabledOption(QAbstractPrintDialog::PrintSelection);
    }

    dlg->setWindowTitle(tr("print document"));
    if(dlg->exec() == QDialog::Accepted)
    {
        Qtext->print(&printer);
    }
    delete dlg;
#endif
}

void MainWindow::filePrintPreview()
{
#ifndef QT_NO_PRINTER
    QPrinter printer(QPrinter::HighResolution);
    QPrintPreviewDialog preview(&printer,this);
    connect(&preview,SIGNAL(paintRequested(QPrinter*)),SLOT(printpreview(QPrinter*)));
    preview.exec();
#endif
}

void MainWindow::printpreview(QPrinter* printer)
{
 #ifdef QT_NO_PRINTER
    Q_UNUSED(printer);
 #else
    Qtext->print(printer);
 #endif
}

bool MainWindow::filePrintPdf()
{
    QString  filename = QFileDialog::getSaveFileName(this,"Export  PDF",QString(),".pdf");
    if(!filename.isEmpty())
    {
        if (QFileInfo(filename).suffix().isEmpty())
        {
            filename.append(".pdf");
        }
        QPrinter printer1(QPrinter::HighResolution);
        printer1.setOutputFormat(QPrinter::PdfFormat);
        printer1.setOutputFileName(filename);
        Qtext->document()->print(&printer1);
    }
    return  true;

}

void MainWindow::openRecentFile1()
{
    QAction *action = qobject_cast<QAction*>(sender());
    if (action)
    {
        loadFile1(action->data().toString());
    }
}

void MainWindow::initLansge()
{


}





void MainWindow::textBold()
{
    QTextCharFormat fmt;
    fmt.setFontWeight(td->isChecked() ? QFont::Bold:QFont::Normal);
    mergeFormatOnWordOrSelection(fmt);
}

void MainWindow::textUnderline()
{
  QTextCharFormat fmt;
  fmt.setFontUnderline(line->isChecked());
  mergeFormatOnWordOrSelection(fmt);
}

void MainWindow::textItalic()
{
  QTextCharFormat fmt;
  fmt.setFontItalic(Italic->isChecked());
  mergeFormatOnWordOrSelection(fmt);
}

void MainWindow::textfamily(const QString &f)
{
   QTextCharFormat fmt;
   fmt.setFontFamily(f);
   mergeFormatOnWordOrSelection(fmt);
}

void MainWindow::textsize(const QString &p)
{
   qreal pointsize = p.toFloat();
   if(p.toFloat() > 0)
   {
       QTextCharFormat fmt;
       fmt.setFontPointSize(pointsize);
       mergeFormatOnWordOrSelection(fmt);
   }
}

void MainWindow::textstyle(int styleIndex)
{
   QTextCursor  cursor = Qtext->textCursor();

   if(styleIndex != 0)
   {
   QTextListFormat::Style style = QTextListFormat::ListDisc;

   switch(styleIndex)
   {
   case 1:
       style = QTextListFormat::ListDisc;
       break;
   case 2:
       style = QTextListFormat::ListCircle;
       break;
   case 3:
       style = QTextListFormat::ListSquare;
       break;
   case 4:
       style = QTextListFormat::ListDecimal;
       break;
   case 5:
       style = QTextListFormat::ListLowerAlpha;
       break;
   case 6:
       style = QTextListFormat::ListUpperAlpha;
       break;
   case 7:
       style = QTextListFormat::ListLowerRoman;
       break;
   case 8:
       style = QTextListFormat::ListUpperRoman;
       break;
   default:
       break;
   }
   cursor.beginEditBlock();

   QTextBlockFormat blockfmt = cursor.blockFormat();
   QTextListFormat listFmt;
   if(cursor.currentList())
   {
       //listFmt = cursor.currentList();     ????????
   }
   else
   {
       listFmt.setIndent(blockfmt.indent()+1);
       blockfmt.setIndent(0);
       cursor.setBlockFormat(blockfmt);
   }
   listFmt.setStyle(style);

   cursor.createList(listFmt);

   cursor.endEditBlock();
   }
   else
   {
       QTextBlockFormat bfmt;
       bfmt.setObjectIndex(-1);
       cursor.mergeBlockFormat(bfmt);
   }
}

void MainWindow::textcolor()
{
    QColor  col = QColorDialog::getColor(Qtext->textColor(),this);
    if(!col.isValid())
    {
        return ;
    }
    QTextCharFormat  fmt;
    fmt.setForeground(col);
    mergeFormatOnWordOrSelection(fmt);
    colorchanged(col);


}
void MainWindow::colorchanged(const QColor &c)
{
    QPixmap pix(16,16);
    pix.fill(c);
    color->setIcon(pix);
}

void MainWindow::textAlign(QAction *a)
{
   if(a == left0)
   {
     Qtext->setAlignment(Qt::AlignLeft | Qt::AlignAbsolute);
   }
   else if(a == center0)
   {
       Qtext->setAlignment(Qt::AlignCenter);
   }
   else if(a == right0)
   {
     Qtext->setAlignment(Qt::AlignRight | Qt::AlignAbsolute);
   }
   else if(a == justify)
   {
       Qtext->setAlignment(Qt::AlignJustify);
   }




}

void MainWindow::about()
{
    QMessageBox::about(this,tr("About"),tr("This example demonstrates Qt's"
                                           "rich text editing facilities in action,providing an example"
                                           "document for you to experiment with"));

}

bool MainWindow::maybesave()
{
    if (!Qtext->document()->isModified())//  文件没有
    {
        return true;
    }
    if(filename.startsWith(QLatin1String(":/")))///  ？
    {
        return true;
    }

    QMessageBox::StandardButton ret;

    ret = QMessageBox::warning(this,tr("Application"),tr("the document has been modified.\n"
                                                         "do you want to save your changes?"),
                               QMessageBox::Save | QMessageBox::Discard|QMessageBox::Cancel);


    if(ret == QMessageBox::Save)
    {
         return filesave();
    }
    else if (ret == QMessageBox::Cancel)
    {
        return false;
    }
    return true;


}

void MainWindow::setcurrentfilename(const QString &filename)
{
    this->filename = filename;
    Qtext->document()->setModified(false);

    QString shownName;
    if (filename.isEmpty())
    {
        shownName = "untitled.text";
    }
    else
    {
        shownName = QFileInfo(filename).fileName();
    }

    setWindowTitle(tr("%1[*]-%2").arg(shownName).arg(tr("rich text")));
    setWindowModified(false);
}

void MainWindow::mergeFormatOnWordOrSelection(const QTextCharFormat &format)
{
     QTextCursor cursor = Qtext->textCursor();
     if(!cursor.hasSelection())
     {
         cursor.select(QTextCursor::WordUnderCursor);
     }
     cursor.mergeCharFormat(format);
     Qtext->mergeCurrentCharFormat(format);


}





















