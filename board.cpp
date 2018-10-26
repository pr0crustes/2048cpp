#include "board.h"


void Board::setupBoard() {
	QGridLayout* layout = new QGridLayout;

	for (int i = 0; i < this->boardSize * this->boardSize; i++) {
		Tile* tile = new Tile();
		tile->setFixedSize(this->boardScale, this->boardScale);
		layout->addWidget(tile, i / this->boardSize, i % this->boardSize);
		this->tiles << tile;
	}

	this->setLayout(layout);

	this->afterMovement();
}


void Board::afterMovement() {
	if (this->moved) {
		this->addRandomTile();
		this->moved = false;
	}
}


void Board::moveTile(int row, int col, int rowChange, int colChange) {
	Tile* tile = this->tile(row, col);
	if (tile && !tile->isFree()) {
		Tile* nextTile = this->tile(row + rowChange, col + colChange);
		if (nextTile) {
			if (tile->equalTo(nextTile)) {
				tile->reset();
				nextTile->doubleValue();
			} else if (nextTile->isFree()) {
				nextTile->addTile(tile);
				tile->reset();
			}

			this->moved = true;
			this->moveTile(row + rowChange, col + colChange, rowChange, colChange);
		}
	}
}


void Board::moveUp() {
	for (int r = 1; r < this->boardSize; r++) {
		for (int c = 0; c < this->boardSize; c++) {
			this->moveTile(r, c, -1, 0);
		}
	}
	this->afterMovement();
}


void Board::moveDown() {
	for (int r = this->boardSize - 2; r >= 0; r--) {
		for (int c = 0; c < this->boardSize; c++) {
			this->moveTile(r, c, 1, 0);
		}
	}
	this->afterMovement();
}


void Board::moveLeft() {
	for (int r = 0; r < this->boardSize; r++) {
		for (int c = 1; c < this->boardSize; c++) {
			this->moveTile(r, c, 0, -1);
		}
	}
	this->afterMovement();
}


void Board::moveRight() {
	for (int r = 0; r < this->boardSize; r++) {
		for (int c = this->boardSize; c >= 0; c--) {
			this->moveTile(r, c, 0, 1);
		}
	}
	this->afterMovement();
}


Tile* Board::tile(int row, int col) {
	if (this->inRange(row, col)) {
		return this->tiles[this->boardSize * row + col];
	}
	return nullptr;
}


bool Board::inRange(int row, int col) {
	bool positive = row >= 0 && col >= 0;
	bool upper = row < this->boardSize && col < this->boardSize;
	return positive && upper;
}


QVector<Tile *> Board::freeTiles() {
	QVector<Tile *> freeTiles;

	for (int i = 0; i < this->tiles.length(); i++) {
		Tile * tile = this->tiles[i];
		if (tile->isFree()) {
			freeTiles << tile;
		}
	}

	return freeTiles;
}


void Board::addRandomTile() {
	QVector<Tile *> freeTiles = this->freeTiles();

	if (freeTiles.length() > 0) {
		int randomNumber = QRandomGenerator::global()->bounded(freeTiles.length());
		Tile* randomTile = freeTiles[randomNumber];
		randomTile->setValue(2);
	}
}








