#include "board.h"


void Board::setupBoard() {
	QGridLayout* layout = new QGridLayout;

	for (int i = 0; i < this->boardSize * this->boardSize; i++) {
		Tile* tile = new Tile();
//#define DEBUG_BOARD  // DEBUG_BOARD is for testing colors.
#ifdef DEBUG_BOARD
		if (i == 0) {
			tile->setValue(2);
		} else {
			tile->addTile(this->tiles[i - 1]);
			tile->addTile(this->tiles[i - 1]);
		}
#endif
		tile->setFixedSize(this->boardScale, this->boardScale);
		layout->addWidget(tile, i / this->boardSize, i % this->boardSize);
		this->tiles << tile;
	}

	this->setLayout(layout);

	this->afterMovement();
}


void Board::resetBoard() {
	foreach (Tile* tile, this->tiles) {
		tile->setValue();
	}
	this->addRandomTile();
}


void Board::afterMovement() {
	if (this->moved) {
		this->addRandomTile();
		this->moved = false;
		if (!this->isMovePossible()) {
			this->showLoosePopUp();
		}
	}
}


void Board::showLoosePopUp() {
	int popup = QMessageBox::question(this, "Game Over", "You Lost!", QMessageBox::Ok);

	switch (popup) {
		case QMessageBox::Ok:
			this->resetBoard();
			break;
		default:
			break;
	}
}


void Board::moveTile(int row, int col, int rowChange, int colChange) {
	Tile* tile = this->tile(row, col);
	if (tile && !tile->isFree()) {
		Tile* nextTile = this->tile(row + rowChange, col + colChange);
		if (nextTile) {
			if (tile->equalTo(nextTile) || nextTile->isFree()) {
				nextTile->addTile(tile);
				tile->setValue();
				this->moved = true;
			}
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
	for (int r = this->boardSize; r >= 0; r--) {
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

	foreach (Tile* tile, this->tiles) {
		if (tile->isFree()) {
			freeTiles << tile;
		}
	}

	return freeTiles;
}


QVector<Tile *> Board::tilesAroundTile(int row, int col) {
	QVector<Tile *> tilesAround;

	for (int i = -1; i <= 1; i += 2) {
		Tile* tile = this->tile(row + i, col);
		if (tile) {
			tilesAround << tile;
		}
		tile = this->tile(row, col + i);
		if (tile) {
			tilesAround << tile;
		}
	}
	return tilesAround;
}


void Board::addRandomTile() {
	QVector<Tile *> freeTiles = this->freeTiles();

	if (freeTiles.length() > 0) {
		int randomNumber = QRandomGenerator::global()->bounded(freeTiles.length());
		Tile* randomTile = freeTiles[randomNumber];
		randomTile->setValue(2);
	}
}


bool Board::isMovePossible() {
	for (int r = 0; r < this->boardSize; r++) {
		for (int c = 0; c < this->boardSize; c++) {
			Tile* tile = this->tile(r, c);
			if (tile) {
				if (tile->isFree()) {
					return true;
				}
				QVector<Tile *> adjacents = this->tilesAroundTile(r, c);
				foreach (Tile* adjacent, adjacents) {
					if (tile->equalTo(adjacent)) {
						return true;
					}
				}
			}
		}
	}
	return false;
}
