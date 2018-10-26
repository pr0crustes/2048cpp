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
		void doubleValue();
		void setValue(int value);
		void reset();

	private:
		QColor definedTileColor();
		void updateTileColor();
		int asInt();
		int mergeNumber();

};

#endif // TILE_H
