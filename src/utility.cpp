#include "utility.h"


void Utility::centralizeWidget(QWidget *widget) {
	widget->adjustSize();
	widget->setGeometry(
		QStyle::alignedRect(
			Qt::LeftToRight,
			Qt::AlignCenter,
			widget->size(),
			QGuiApplication::screens().first()->availableGeometry()
		)
	);
}
