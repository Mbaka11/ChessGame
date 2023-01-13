/*
* Author: Marsel Bakashob and Massil Sebba
* Date: may 6th 2022
* Description: header of horse piece
*/
#ifndef HORSE_H
#define HORSE_H

#include "Piece.h"

class Horse : public Piece{
public:
	Horse(QString color, QGraphicsItem* parent = nullptr);
	
	void setDrawing();

	void movements();

private:
};

#endif

