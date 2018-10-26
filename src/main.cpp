#include "gamewindow.h"

#include <QApplication>
#include <QScreen>
#include <QDesktopWidget>
#include <QStyle>


int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	GameWindow w;

	w.adjustSize();
	w.setGeometry(
		QStyle::alignedRect(
			Qt::LeftToRight,
			Qt::AlignCenter,
			w.size(),
			QGuiApplication::screens().first()->availableGeometry()
		)
	);

	w.show();
	return a.exec();
}
