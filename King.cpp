/*
* Author: Marsel Bakashob and Massil Sebba
* Date: may 6th 2022
* Description: implementation of the king piece
*/
#include "King.h"
#include "GameOfChess.h"
#include "Pawn.h"

extern GameOfChess* gameOfChess;

King::King(QString color, QGraphicsItem* parent)
	: Piece(color, parent){
	setDrawing();
}

void King::setDrawing() {
	if (color_ == "white") {
		setPixmap(QPixmap("RoiBlanc.png"));
	}
	else {
		setPixmap(QPixmap("RoiNoir.png"));
	}
}

void King::movements() {
	movements_.clear();

	int row = this->getCurrentTile()->row;
	int col = this->getCurrentTile()->colonne;
	QString teamColor = this->getColor();

	if ((col > 0) && (row > 0) && !(gameOfChess->tileCollection[row - 1][col - 1]->getPieceColor() == teamColor)) {
		movements_.append(gameOfChess->tileCollection[row - 1][col - 1]);
		gameOfChess->tileCollection[row - 1][col - 1]->setColor(Qt::darkRed);

		if (movements_.last()->getIsUsedByAPiece()) {
			movements_.last()->setColor(Qt::red);
		}
	}
	else if ((col < 7) && (row > 0) && !(gameOfChess->tileCollection[row - 1][col + 1]->getPieceColor() == teamColor)) {
		movements_.append(gameOfChess->tileCollection[row - 1][col + 1]);
		gameOfChess->tileCollection[row - 1][col + 1]->setColor(Qt::darkRed);

		if (movements_.last()->getIsUsedByAPiece()) {
			movements_.last()->setColor(Qt::red);
		}
	}
	else if ((col > 0) && (row < 7) && !(gameOfChess->tileCollection[row + 1][col - 1]->getPieceColor() == teamColor)) {
		movements_.append(gameOfChess->tileCollection[row + 1][col - 1]);
		gameOfChess->tileCollection[row - 1][col + 1]->setColor(Qt::darkRed);

		if (movements_.last()->getIsUsedByAPiece()) {
			movements_.last()->setColor(Qt::red);
		}
	}
	else if ((col < 7) && (row < 7) && !(gameOfChess->tileCollection[row + 1][col + 1]->getPieceColor() == teamColor)) {
		movements_.append(gameOfChess->tileCollection[row + 1][col + 1]);
		gameOfChess->tileCollection[row + 1][col + 1]->setColor(Qt::darkRed);

		if (movements_.last()->getIsUsedByAPiece()) {
			movements_.last()->setColor(Qt::red);
		}
	}
	else if ((row > 0) && !(gameOfChess->tileCollection[row - 1][col]->getPieceColor() == teamColor)) {
		movements_.append(gameOfChess->tileCollection[row - 1][col]);
		gameOfChess->tileCollection[row - 1][col]->setColor(Qt::darkRed);

		if (movements_.last()->getIsUsedByAPiece()) {
			movements_.last()->setColor(Qt::red);
		}
	}
	else if ((row < 7) && !(gameOfChess->tileCollection[row + 1][col]->getPieceColor() == teamColor)) {
		movements_.append(gameOfChess->tileCollection[row + 1][col]);
		gameOfChess->tileCollection[row + 1][col]->setColor(Qt::darkRed);

		if (movements_.last()->getIsUsedByAPiece()) {
			movements_.last()->setColor(Qt::red);
		}
	}
	else if ((col > 0) && !(gameOfChess->tileCollection[row][col - 1]->getPieceColor() == teamColor)) {
		movements_.append(gameOfChess->tileCollection[row][col - 1]);
		gameOfChess->tileCollection[row][col - 1]->setColor(Qt::darkRed);

		if (movements_.last()->getIsUsedByAPiece()) {
			movements_.last()->setColor(Qt::red);
		}
	}
	else if ((col < 7) && !(gameOfChess->tileCollection[row][col + 1]->getPieceColor() == teamColor)) {
		movements_.append(gameOfChess->tileCollection[row][col + 1]);
		gameOfChess->tileCollection[row][col + 1]->setColor(Qt::darkRed);

		if (movements_.last()->getIsUsedByAPiece()) {
			movements_.last()->setColor(Qt::red);
		}
	}

	analyseSafeMovements();
}

void King::analyseSafeMovements() {
	QList<Piece*> pieceList = gameOfChess->piecesInGame;

	for (size_t i = 0, n = pieceList.size(); i < n; i++) {
		if (pieceList[i]->getColor() != this->getColor()) {
			QList <Tile*> tileList = pieceList[i]->movementsList();
			
			for (size_t j = 0, n = tileList.size(); j < n; j++) {
				Pawn* pawn = dynamic_cast<Pawn*> (pieceList[i]);

				if (pawn) {
					continue;
				}
				else {
					for (size_t m = 0, n = movements_.size(); m < n; m++) {
						if (tileList[j] == movements_[m]) {
							movements_[m]->setColor(Qt::green);
						}
					}
				}
			}
		}
	}
}