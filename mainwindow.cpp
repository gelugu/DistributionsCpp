#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QDir"

// конструктор окна
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	// ui отвечает за отображение элементов интерфейса 
	// setupUi настраивает интерфейс для отображения
    ui->setupUi(this);

    // активируем опцию по умолчанию и прячем остальные
    ui->radioUniform->setChecked(true);
    ui->groupGauss->setEnabled(false);
    ui->radioN1K->setChecked(true);
    ui->checkIsNegative->setChecked(true);

    // устанавливаем ненулевые значения в поля ввода
    ui->spinUniformX->setValue(0);
    ui->spinUniformA->setValue(2);
    ui->spinGaussE->setValue(1);
    ui->spinGaussSigma->setValue(2);

    // экземпляры классов для расчётов распределений
    uniform = new UniformDistribution(ui->spinUniformA->value(), ui->spinUniformX->value());
    gauss = new GaussianDistribution(ui->spinGaussSigma->value(), ui->spinGaussE->value());

    // отображение результата
    this->dist = this->uniform->getOutput();
    this->output();
}

// деструктор окна
MainWindow::~MainWindow()
{
    delete ui;
}

// обработчики событий нажатия на кнопки
void MainWindow::on_radioUniform_clicked()
{
    // делаем поля ввода для равномерного распределения активными
    ui->groupUniform->setEnabled(true);

    // а поля для гауссса неактивными
    ui->groupGauss->setEnabled(false);
}

void MainWindow::on_radioGauss_clicked()
{
    // делаем поля ввода для гаусса распределения активными
    ui->groupGauss->setEnabled(true);

    // а поля для равномерного неактивными
    ui->groupUniform->setEnabled(false);
}

void MainWindow::on_pushCalculate_clicked()
{
    long time;

    if (ui->radioUniform->isChecked()) {
        // записываем пользовательские значения
        uniform->setX(ui->spinUniformX->value());
        uniform->setA(ui->spinUniformA->value());

        time = uniform->calculate(ui->checkIsNegative->isChecked());

        dist = uniform->getOutput();
    } else {
        // записываем пользовательские значения
        gauss->setSigma(ui->spinGaussSigma->value());
        gauss->setE(ui->spinGaussE->value());

        time = gauss->calculate(ui->checkIsNegative->isChecked());

        dist = gauss->getOutput();
    }


    // очищаем вывод
    ui->textOutput->clear();
    // выводим текущий результат
    this->output();


    // выводим время в соответствующее поле для отображение времени
    // если меньше одной секунды, то так и выводим
    if (time < 1)
        ui->labelTimeOutput->setText("<1 s");
    // если не болье (а меньше не может быть по логике) то выводим время
    else
        ui->labelTimeOutput->setText(QString::number(time) + " s");
}

void MainWindow::on_pushExportMathLab_clicked()
{
    // используем статический метод класса MatlabCreator для создания файла
    // первым параметром передаём встроенный в QT метод, который возвращает путь к файлу
    // вторым параметром передаём массив
    MatlabCreator::createFile(QFileDialog::getSaveFileName(this, tr("Open File"),
                                                           QDir::home().path(),
                                                           tr("Matlab file *.m")),
                              this->dist);
}

// вспомогательный метод для вывода информации в окно программы
void MainWindow::output()
{
    // создаём переменную-счётчки
    int i = 0;

    // функция для перебора элементов вектора
    // первый параметр - значение, с которым мы будем работать из тела функции (создаётся прямо тут)
    // второы - сам массив, который будем перебирать
    foreach(double num, dist) {
        // образаемся к интерфейсу, затем к текстовому полю, затем (append) дабавляем новую строку
        // QString::number(++i) это наша переменная счётчик, переведённая в строку, так же с num
        // ".\t" - точка и таб (отступ)
        ui->textOutput->append(QString::number(++i) + ".\t" + QString::number(num));
    }
}

// выбор опции "1000 значений"
void MainWindow::on_radioN1K_clicked()
{
    // пересоздаём объекты распределений, потому что изменилось n, число элементов
    this->uniform = new UniformDistribution(this->ui->spinUniformX->value(), this->ui->spinUniformA->value());
    this->gauss = new GaussianDistribution(ui->spinGaussE->value(), ui->spinGaussSigma->value());
}

// выбор опции "10 000 значений"
void MainWindow::on_radioN10K_clicked()
{
    // пересоздаём объекты распределений, потому что изменилось n, число элементов
    this->uniform = new UniformDistribution(this->ui->spinUniformX->value(), this->ui->spinUniformA->value(), 10000);
    this->gauss = new GaussianDistribution(ui->spinGaussE->value(), ui->spinGaussSigma->value(), 10000);
}
