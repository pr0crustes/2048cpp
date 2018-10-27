#include "tile.h"


Tile::Tile() : QLabel(), tileValue(0) {
	this->setAlignment(Qt::AlignCenter);
	this->setFont(QFont("Arial", 30, QFont::Bold));
	this->updateTile();
}


bool Tile::isFree() {
	return this->tileValue == 0;
}


void Tile::setValue(int value) {
	this->tileValue = value;
	this->updateTile();
}


void Tile::addTile(Tile *tile) {
	this->setValue(this->tileValue + tile->tileValue);
}


bool Tile::equalTo(const Tile *other) const {
	return this->tileValue == other->tileValue;
}


void Tile::updateTile() {
	QString text = this->isFree() ? QString() : QString::number(this->tileValue);
	this->setText(text);
	this->updateTileColor();
}


void Tile::updateTileColor() {
	QColor color = this->definedTileColor();
	this->setAutoFillBackground(true);
	QPalette palette = this->palette();
	palette.setColor(QPalette::Background, color);
	this->setPalette(palette);
}


QColor Tile::definedTileColor() {
	switch (this->tileValue) {
		case 0:
			return QColor(255, 255, 255);
		case 2:
			return QColor(150, 200, 255);
		case 4:
			return QColor(100, 200, 255);
		case 8:
			return QColor(50, 200, 255);
		case 16:
			return QColor(0, 200, 255);
		case 32:
			return QColor(0, 70, 255);
		case 64:
			return QColor(0, 40, 255);
		case 128:
			return QColor(50, 0, 255);
		case 256:
			return QColor(100, 0, 255);
		case 512:
			return QColor(150, 0, 255);
		case 1024:
			return QColor(150, 0, 200);
		case 2048:
			return QColor(150, 50, 150);
		case 4096:
			return QColor(150, 100, 50);
		case 8192:
			return QColor(150, 150, 50);
		case 16384:
			return QColor(200, 200, 50);
		default:
			return QColor(250, 150, 50);
	}
}
