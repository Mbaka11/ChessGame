/*
* Author: Marsel Bakashob and Massil Sebba
* Date: may 6th 2022
* Description: header of one piece
*/
#ifndef PIECE_H
#define PIECE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

#include "Tile.h"

class Tile;

class Piece : public QGraphicsPixmapItem{
public:
	Piece(QString color, QGraphicsItem* parent = nullptr);
	~Piece() = default;

	void mousePressEvent(QGraphicsSceneMouseEvent* event);

	void setCurrentTile(Tile* tile);
	Tile* getCurrentTile();

	QString getColor();
	void setColor(QString newColor);
	void fade();

	bool getIsInGame();
	void setIsInGame(bool isStillInGame);

	bool isTile(Tile* tile);

	QList<Tile*> movementsList();

	virtual void setDrawing() = 0;
	virtual void movements() = 0;

	bool isFirstMove;

protected:
	QString color_ = "N/A";
	Tile* currentTile_;
	QList<Tile*> movements_;
	bool isInGame_;
};

#endif

