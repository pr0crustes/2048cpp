#include "startwindow.h"

#include <QLineEdit>


void StartWindow::drawGUI() {

	QVBoxLayout* vlayout = new QVBoxLayout();

	QLabel* label = new QLabel("Select The Board Size:");
	vlayout->addWidget(label);

	this->sizeComboBox = new QComboBox();
	for (int i = 0; i < 6; i++) {
		this->sizeComboBox->insertItem(i, QString::number(i + 2));
	}
	this->sizeComboBox->setCurrentIndex(2);
	vlayout->addWidget(this->sizeComboBox);

	QPushButton* startButton = new QPushButton();
	startButton->setText("Play");
	this->connect(startButton, &QPushButton::released, this, &StartWindow::startGame);
	vlayout->addWidget(startButton);

	QWidget* widget = new QWidget();
	widget->setLayout(vlayout);

	this->setCentralWidget(widget);

	Utility::centralizeWidget(this);
}


void StartWindow::startGame() {
	int selectedSize = this->sizeComboBox->currentText().toInt();
	GameWindow* window = new GameWindow(0, selectedSize);
	window->show();
	this->hide();
}
