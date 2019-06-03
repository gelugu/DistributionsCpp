#include "mainwindow.h"
#include <QApplication>

// точка входа в приложение
int main(int argc, char *argv[])
{
	// создание экземпляра класса QApplcation, которое строит приложение
    QApplication a(argc, argv);

	// создание экземпляра класса MainWindow, которое создаёт окно
    MainWindow w;

	// метод show отображает окно в операционной системе
    w.show();
	
	// выход из приложения
    return a.exec();
}
