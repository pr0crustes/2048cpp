#ifndef BOARD_H
#define BOARD_H

#include "tile.h"

#include <QWidget>
#include <QGridLayout>
#include <QVector>
#include <QRandomGenerator>
#include <QMessageBox>


class Board : public QWidget {
		Q_OBJECT

	public:
		explicit Board(int size, int scale, QWidget *parent = nullptr)
			: QWidget(parent), moved(true), boardSize(size), boardScale(scale) {}
		void setupBoard();
		void resetBoard();
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();

	private:
		bool moved;
		int boardSize;
		int boardScale;
		QVector<Tile *> tiles;

		Tile* tile(int row, int col);
		QVector<Tile *> freeTiles();
		QVector<Tile *> tilesAroundTile(int row, int col);
		bool inRange(int row, int col);
		bool isMovePossible();
		void moveTile(int row, int col, int rowChange, int colChange);
		void afterMovement();
		void showLoosePopUp();
		void addRandomTile();

};

#endif // BOARD_H
