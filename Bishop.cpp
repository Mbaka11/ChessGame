/*
* Author: Marsel Bakashob and Massil Sebba
* Date: may 6th 2022
* Description: implementation of the bishop piece
*/
#include "Bishop.h"
#include "GameOfChess.h"

extern GameOfChess* gameOfChess;

Bishop::Bishop(QString color, QGraphicsItem* parent)
	:Piece(color, parent) {
	setDrawing();
}

void Bishop::setDrawing() {
	if (color_ == "white") {
		setPixmap(QPixmap("FouBlanc.png"));
	}
	else {
		setPixmap(QPixmap("FouNoir.png"));
	}
}

void Bishop::movements() {
	movements_.clear();

	int row = this->getCurrentTile()->row;
	int col = this->getCurrentTile()->colonne;
	QString teamColor = this->getColor();

	for (int i = row - 1, j = col - 1; (i >= 0) && (j >= 0); i--, j--) {
		if (gameOfChess->tileCollection[i][j]->getPieceColor() == teamColor) {
			break;
		}
		else {
			movements_.append(gameOfChess->tileCollection[i][j]);
			if (isTile(movements_.last())) {
				break;
			}
		}
	}

	for (int i = row - 1, j = col + 1; (i >= 0) && (j <= 7); i--, j++) {
		if (gameOfChess->tileCollection[i][j]->getPieceColor() == teamColor) {
			break;
		}
		else {
			movements_.append(gameOfChess->tileCollection[i][j]);
			if (isTile(movements_.last())) {
				break;
			}
		}
	}

	for (int i = row + 1, j = col + 1; (i <= 7) && (j <= 7); i++, j++) {
		if (gameOfChess->tileCollection[i][j]->getPieceColor() == teamColor) {
			break;
		}
		else {
			movements_.append(gameOfChess->tileCollection[i][j]);
			if (isTile(movements_.last())) {
				break;
			}
		}
	}

	for (int i = row + 1, j = col - 1; (i <= 7) && (j >= 0); i++, j--) {
		if (gameOfChess->tileCollection[i][j]->getPieceColor() == teamColor) {
			break;
		}
		else {
			movements_.append(gameOfChess->tileCollection[i][j]);
			if (isTile(movements_.last())) {
				break;
			}
		}
	}
}