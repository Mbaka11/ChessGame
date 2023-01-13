/*
* Author: Marsel Bakashob and Massil Sebba
* Date: may 6th 2022
* Description: header of queen piece
*/
#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen :public Piece{
public:
    Queen(QString color, QGraphicsItem* parent = 0);

    void setDrawing();

    void movements();

};

#endif

