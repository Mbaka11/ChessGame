/*
* Author: Marsel Bakashob and Massil Sebba
* Date: may 6th 2022
* Description: header of pawn piece
*/
#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece{
public:
	Pawn(QString color, QGraphicsItem* parent = nullptr);

	void setDrawing();

	void movements();
private:

};

#endif
