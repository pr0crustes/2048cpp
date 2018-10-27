#ifndef TILE_H
#define TILE_H

#include <QLabel>
#include <QColor>


class Tile : public QLabel {

	public:
		Tile();
		bool isFree();
		bool equalTo(const Tile* other) const;
		void addTile(Tile* tile);
		void setValue(int value = 0);

	private:
		int tileValue;
		QColor definedTileColor();
		void updateTile();
		void updateTileColor();

};

#endif // TILE_H
