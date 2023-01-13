/*
* Author: Marsel Bakashob and Massil Sebba
* Date: may 6th 2022
* Description: header of the chessboard
*/
#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "Piece.h"

#include <QGraphicsRectItem>

class Chessboard {
public:
	Chessboard();
	~Chessboard() = default;

	void showTiles(int x, int y);

	void initWhite();
	void initBlack();

	void addPiece();
	void reset();

private:
	QList<Piece*> white;
	QList<Piece*> black;
};

#endif


