/*
* Author: Marsel Bakashob and Massil Sebba
* Date: may 6th 2022
* Description: implementation of the horse piece
*/
#include "Horse.h"
#include "GameOfChess.h"

extern GameOfChess* gameOfChess;

Horse::Horse(QString color, QGraphicsItem* parent)
	: Piece(color, parent){
	setDrawing();
}

void Horse::setDrawing() {
	if (color_ == "white") {
		setPixmap(QPixmap("CavalierBlanc.png"));
	}
	else {
		setPixmap(QPixmap("CavalierNoir.png"));
	}
}

void Horse::movements() {
	movements_.clear();

	int row = this->getCurrentTile()->row;
	int col = this->getCurrentTile()->colonne;
	QString teamColor = this->getColor();
	int i;
	int j;

	i = row - 2;
	j = col - 1;

	if ((i >= 0) && (j >= 0) && (gameOfChess->tileCollection[i][j]->getPieceColor() != teamColor)) {
		movements_.append(gameOfChess->tileCollection[i][j]);
		if (movements_.last()->getIsUsedByAPiece()) {
			movements_.last()->setColor(Qt::red);
		}
		else {
			movements_.last()->setColor(Qt::darkRed);
		}
	}

	i = row - 2;
	j = col + 1;

	if ((i >= 0) && (j <= 7) && (gameOfChess->tileCollection[i][j]->getPieceColor() != teamColor)) {
		movements_.append(gameOfChess->tileCollection[i][j]);
		if (movements_.last()->getIsUsedByAPiece()) {
			movements_.last()->setColor(Qt::red);
		}
		else {
			movements_.last()->setColor(Qt::darkRed);
		}
	}

	i = row + 2;
	j = col - 1;

	if ((i <= 7) && (j >= 0) && (gameOfChess->tileCollection[i][j]->getPieceColor() != teamColor)) {
		movements_.append(gameOfChess->tileCollection[i][j]);
		if (movements_.last()->getIsUsedByAPiece()) {
			movements_.last()->setColor(Qt::red);
		}
		else {
			movements_.last()->setColor(Qt::darkRed);
		}
	}

	i = row + 2;
	j = col + 1;

	if ((i <= 7) && (j <= 7) && (gameOfChess->tileCollection[i][j]->getPieceColor() != teamColor)) {
		movements_.append(gameOfChess->tileCollection[i][j]);
		if (movements_.last()->getIsUsedByAPiece()) {
			movements_.last()->setColor(Qt::red);
		}
		else {
			movements_.last()->setColor(Qt::darkRed);
		}
	}

	i = row - 1;
	j = col - 2;

	if ((i >= 0) && (j >= 0) && (gameOfChess->tileCollection[i][j]->getPieceColor() != teamColor)) {
		movements_.append(gameOfChess->tileCollection[i][j]);
		if (movements_.last()->getIsUsedByAPiece()) {
			movements_.last()->setColor(Qt::red);
		}
		else {
			movements_.last()->setColor(Qt::darkRed);
		}
	}

	i = row + 1;
	j = col - 2;

	if ((i <= 7) && (j >= 0) && (gameOfChess->tileCollection[i][j]->getPieceColor() != teamColor)) {
		movements_.append(gameOfChess->tileCollection[i][j]);
		if (movements_.last()->getIsUsedByAPiece()) {
			movements_.last()->setColor(Qt::red);
		}
		else {
			movements_.last()->setColor(Qt::darkRed);
		}
	}

	i = row - 1;
	j = col + 2;

	if ((i >= 0) && (j <= 7) && (gameOfChess->tileCollection[i][j]->getPieceColor() != teamColor)) {
		movements_.append(gameOfChess->tileCollection[i][j]);
		if (movements_.last()->getIsUsedByAPiece()) {
			movements_.last()->setColor(Qt::red);
		}
		else {
			movements_.last()->setColor(Qt::darkRed);
		}
	}

	i = row + 1;
	j = col + 2;

	if ((i <= 7) && (j <= 7) && (gameOfChess->tileCollection[i][j]->getPieceColor() != teamColor)) {
		movements_.append(gameOfChess->tileCollection[i][j]);
		if (movements_.last()->getIsUsedByAPiece()) {
			movements_.last()->setColor(Qt::red);
		}
		else {
			movements_.last()->setColor(Qt::darkRed);
		}
	}
}