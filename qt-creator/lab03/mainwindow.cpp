#include <QDebug>
#include <QFileDialog>
#include <QMdiSubWindow>
#include <QTextEdit>
#include <QtWidgets>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutdialog.h"
#include "mdichild.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    aboutDialog = new AboutDialog(this);

    setupActions();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFile()
{
    MdiChild *child = new MdiChild;

    // Осталось добавить функцию разархивации :(

    ui->mdiArea->addSubWindow(child);
    child->show();
    child->parentWidget()->resize(500, 500);
}

void MainWindow::openAboutDialog()
{
    aboutDialog->exec();
}

void MainWindow::setupActions()
{
    connect(ui->openFileAction, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(ui->showAboutAction, SIGNAL(triggered()), this, SLOT(openAboutDialog()));
}

