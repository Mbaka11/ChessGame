/*
* Author: Marsel Bakashob and Massil Sebba
* Date: may 6th 2022
* Description: header of rook piece
*/
#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook :public Piece{
public:
    Rook(QString color, QGraphicsItem* parent = 0);

    void setDrawing();

    void movements();

};

#endif 