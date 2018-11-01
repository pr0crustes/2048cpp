#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include "gamewindow.h"
#include "utility.h"

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>


class StartWindow : public QMainWindow {
		Q_OBJECT

	public:
		explicit StartWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
			this->drawGUI();
			this->setWindowTitle("2048cpp");
		}

	private:
		QComboBox* sizeComboBox;
		void drawGUI();
		void startGame();
};

#endif // STARTWINDOW_H
