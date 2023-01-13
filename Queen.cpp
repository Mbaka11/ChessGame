/*
* Author: Marsel Bakashob and Massil Sebba
* Date: may 6th 2022
* Description: implementation of the queen piece
*/
#include "Queen.h"
#include "GameOfChess.h"

extern GameOfChess* gameOfChess;

Queen::Queen(QString color, QGraphicsItem* parent)
	:Piece(color, parent){
	setDrawing();
}

void Queen::setDrawing() {
	if (color_ == "white") {
		setPixmap(QPixmap("ReineBlanche.png"));
	}
	else {
		setPixmap(QPixmap("ReineNoire.png"));
	}
}

void Queen::movements() {
	movements_.clear();

	int row = this->getCurrentTile()->row;
	int col = this->getCurrentTile()->colonne;
	QString teamColor = this->getColor();

	for (int i = row - 1, j = col; i >= 0; i--) {
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

	for (int i = row + 1, j = col; i <= 7; i++) {
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

	for (int i = row, j = col - 1; j >= 0; j--) {
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

	for (int i = row, j = col + 1; j <= 7; j++) {
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