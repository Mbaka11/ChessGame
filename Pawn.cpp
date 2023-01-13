/*
* Author: Marsel Bakashob and Massil Sebba
* Date: may 6th 2022
* Description: implementation of the pawn piece
*/

#include "Pawn.h"
#include "GameOfChess.h"

extern GameOfChess* gameOfChess;

Pawn::Pawn(QString color, QGraphicsItem* parent)
	:Piece(color, parent){
	setDrawing();
	isFirstMove = true;
}

void Pawn::setDrawing() {
	if (color_ == "white") {
		setPixmap(QPixmap("PionBlanc.png"));
	}
	else {
		setPixmap(QPixmap("PionNoir.png"));
	}
}

void Pawn::movements() {
	movements_.clear();

	int row = this->getCurrentTile()->row;
	int col = this->getCurrentTile()->colonne;

	if (this->getColor() == "white") {
		if ((col > 0) && (row > 0) && (gameOfChess->tileCollection[row -1 ][col - 1]->getPieceColor() == "black")) {
			movements_.append(gameOfChess->tileCollection[row - 1][col - 1]);
			isTile(movements_.last());
		}
		else if ((col < 7) && (row > 0) && (gameOfChess->tileCollection[row - 1][col + 1]->getPieceColor() == "black")) {
			movements_.append(gameOfChess->tileCollection[row - 1][col + 1]);
			isTile(movements_.last());

		}
		else if ((row > 0) && !(gameOfChess->tileCollection[row - 1][col]->getIsUsedByAPiece())) {
			movements_.append(gameOfChess->tileCollection[row - 1][col]);
			isTile(movements_.last());

			if ((isFirstMove) && !(gameOfChess->tileCollection[row - 2][col]->getIsUsedByAPiece())) {
				movements_.append(gameOfChess->tileCollection[row - 2][col]);
				isTile(movements_.last());
			}
		}
	}
	else {
		if ((col > 0) && (row < 7) && (gameOfChess->tileCollection[row + 1][col - 1]->getPieceColor() == "white")) {
			movements_.append(gameOfChess->tileCollection[row + 1][col - 1]);
			isTile(movements_.last());
		}
		else if ((col < 7) && (row < 7) && (gameOfChess->tileCollection[row + 1][col + 1]->getPieceColor() == "white")) {
			movements_.append(gameOfChess->tileCollection[row + 1][col + 1]);
			isTile(movements_.last());
		}
		else if ((row < 7) && !(gameOfChess->tileCollection[row + 1][col]->getIsUsedByAPiece())) {
			movements_.append(gameOfChess->tileCollection[row + 1][col]);
			isTile(movements_.last());

			if ((isFirstMove) && !(gameOfChess->tileCollection[row + 2][col]->getIsUsedByAPiece())) {
				movements_.append(gameOfChess->tileCollection[row + 2][col]);
				isTile(movements_.last());
			}
		}
	}
}