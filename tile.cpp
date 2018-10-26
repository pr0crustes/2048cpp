#include "tile.h"


Tile::Tile() : QLabel() {
	this->setAlignment(Qt::AlignCenter);
	this->setFont(QFont("Arial", 30, QFont::Bold));
	this->updateTileColor();
}


bool Tile::isFree() {
	return this->text().isEmpty();
}


void Tile::setValue(int value) {
	QString text = value == 0 ? "" : QString::number(value);
	this->setText(text);
	this->updateTileColor();
}


void Tile::doubleValue() {
	this->setValue(2 * this->asInt());
}


void Tile::addTile(Tile *tile) {
	int value = this->asInt()+ tile->asInt();
	this->setValue(value);
}


bool Tile::equalTo(const Tile *other) const {
	return this->text() == other->text();
}


void Tile::reset() {
	this->setValue(0);
}


void Tile::updateTileColor() {
	QColor color = this->definedTileColor();
	this->setAutoFillBackground(true);
	QPalette palette = this->palette();
	palette.setColor(QPalette::Background, color);
//	palette.setColor(QPalette::Window, color);
//	palette.setColor(QPalette::Foreground, color);
//	palette.setColor(this->backgroundRole(), color);
//	palette.setColor(this->foregroundRole(), color);
	this->setPalette(palette);
}


QColor Tile::definedTileColor() {
	int merges = this->mergeNumber();

	switch (merges) {
		case 0:
			return QColor(255, 255, 255);
		case 1:
			return QColor(150, 200, 255);
		case 2:
			return QColor(100, 200, 255);
		case 3:
			return QColor(50, 200, 255);
		case 4:
			return QColor(0, 200, 255);
		case 5:
			return QColor(0, 70, 255);
		case 6:
			return QColor(0, 40, 255);
		case 7:
			return QColor(50, 0, 255);
		case 8:
			return QColor(100, 0, 255);
		case 9:
			return QColor(150, 0, 255);
		case 10:
			return QColor(150, 0, 200);
		case 11:
			return QColor(150, 50, 150);
		case 12:
			return QColor(150, 100, 50);
		case 13:
			return QColor(150, 150, 50);
		case 14:
			return QColor(200, 200, 50);
		default:
			return QColor(250, 150, 50);
	}
}


int Tile::asInt() {
	return this->text().toInt();
}


int Tile::mergeNumber() {
	int value = this->asInt();

	int merges = 0;
	while (value >= 2) {
		merges++;
		value /= 2;
	}
	return merges;
}
