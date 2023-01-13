/*
* Author: Marsel Bakashob and Massil Sebba
* Date: may 6th 2022
* Description: header of a single tile on the chessboard composed of 64 tiles
*/
#ifndef TILE_H
#define TILE_H

#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>

#include "Piece.h"

class Piece;

class Tile : public QGraphicsRectItem {
public:
	Tile(QGraphicsItem* parent = nullptr);
	~Tile() = default;

	void mousePressEvent(QGraphicsSceneMouseEvent* event);

	void setColor(QColor newColor);
	void placePiece(Piece* piece);

	void resetToBaseColor();
	void setBaseColor(QColor qColor);

	bool getIsUsedByAPiece();
	void setIsUsedByAPiece(bool isNowUsed, Piece* piece = nullptr);

	QString getPieceColor();
	void setPieceColor(QString newColor);

	void analyseForCheck();

	int row;
	int colonne;
	Piece* currentPiece;

private:
	QBrush brush_;
	QColor color_;
	bool isUsedByAPiece_;
	QString chessPieceColor_;

};

#endif