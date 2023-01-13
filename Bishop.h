/*
* Author: Marsel Bakashob and Massil Sebba
* Date: may 6th 2022
* Description: header of bishop piece
*/
#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece{
public:
	Bishop(QString color, QGraphicsItem* parent = nullptr);

	void setDrawing();

	void movements();
private:

};

#endif

