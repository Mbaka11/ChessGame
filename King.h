/*
* Author: Marsel Bakashob and Massil Sebba
* Date: may 6th 2022
* Description: header of king piece
*/
#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece{
public:
	King(QString color, QGraphicsItem* parent = nullptr);

	void setDrawing();

	void analyseSafeMovements();

	void movements();

private:
};

#endif 
