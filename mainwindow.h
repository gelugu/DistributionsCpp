#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "uniformdistribution.h"
#include "gaussiandistribution.h"
#include "matlabcreator.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_radioUniform_clicked();

    void on_radioGauss_clicked();

    void on_pushGaussFile_clicked();

    void on_pushCalculate_clicked();

    void on_radioN1K_clicked();

    void on_radioN10K_clicked();

    void on_pushExportMathLab_clicked();

private:
    Ui::MainWindow *ui;
    UniformDistribution *uniform;
    GaussianDistribution *gauss;

    QVector<double> dist;

    void output();
};

#endif // MAINWINDOW_H
