#include "gamewindow.h"


GameWindow::~GameWindow() {
	delete this->board;
}


void GameWindow::keyPressEvent(QKeyEvent *event) {
	switch (event->key()) {
		case Qt::Key_A:
		case Qt::Key_Left:
			this->board->moveLeft();
			break;
		case Qt::Key_W:
		case Qt::Key_Up:
			this->board->moveUp();
			break;
		case Qt::Key_D:
		case Qt::Key_Right:
			this->board->moveRight();
			break;
		case Qt::Key_S:
		case Qt::Key_Down:
			this->board->moveDown();
			break;
		default:
			break;
	}
}
