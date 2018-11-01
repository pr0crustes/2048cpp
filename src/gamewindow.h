#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "board.h"
#include "utility.h"

#include <QKeyEvent>
#include <QMainWindow>


class GameWindow : public QMainWindow {
		Q_OBJECT

	public:
		explicit GameWindow(QWidget *parent = 0, int size = 5, int scale = 100)
			: QMainWindow(parent), board(new Board(size, scale)) {
			this->board->setupBoard();
			this->setCentralWidget(board);
			this->setWindowTitle("2048cpp");
			Utility::centralizeWidget(this);
		}
		~GameWindow();

	protected:
		void keyPressEvent(QKeyEvent *event);

	private:
		Board* board;

};

#endif // GAMEWINDOW_H
