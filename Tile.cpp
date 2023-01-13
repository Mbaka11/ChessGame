/*
* Author: Marsel Bakashob and Massil Sebba
* Date: may 6th 2022
* Description: implementation of a single tile of a chessboard composed by 64 tiles
*/
#include "Tile.h"
#include "GameOfChess.h"
#include "King.h"

extern GameOfChess* gameOfChess;

Tile::Tile(QGraphicsItem* parent)
	: QGraphicsRectItem(parent){
	setRect(0, 0, 100, 100);
	brush_.setStyle(Qt::SolidPattern);
	setIsUsedByAPiece(false);
	setPieceColor("Has no piece");
	currentPiece = nullptr;
}

void Tile::mousePressEvent(QGraphicsSceneMouseEvent* event) {
	if ((currentPiece == gameOfChess->selectedPiece) && (currentPiece)) {
		currentPiece->mousePressEvent(event);
		return;
	}
	
	else if (gameOfChess->selectedPiece) {
		if (this->getPieceColor() == gameOfChess->selectedPiece->getColor()) {
			return;
		}
		QList<Tile*> movList = gameOfChess->selectedPiece->movementsList();

		int check = 0;
		for (size_t i = 0, n = movList.size(); i < n; i++) {
			if (movList[i] == this) {
				check++;
			}
		}

		if (check == 0) {
			return;
		}

		gameOfChess->selectedPiece->fade();

		gameOfChess->selectedPiece->isFirstMove = false;

		if (this->getIsUsedByAPiece()) {
			this->currentPiece->setIsInGame(false);
			this->currentPiece->setCurrentTile(nullptr);
		}

		gameOfChess->selectedPiece->getCurrentTile()->setIsUsedByAPiece(false);
		gameOfChess->selectedPiece->getCurrentTile()->currentPiece = nullptr;
		gameOfChess->selectedPiece->getCurrentTile()->resetToBaseColor();
		placePiece(gameOfChess->selectedPiece);

		gameOfChess->selectedPiece = nullptr;

		gameOfChess->changeTurn();
		analyseForCheck();
	}

	else if (this->getIsUsedByAPiece()) {
		this->currentPiece->mousePressEvent(event);
	}
}

void Tile::setColor(QColor color) {
	brush_.setColor(color);
	setBrush(color);
}

void Tile::placePiece(Piece* piece) {
	piece->setPos(x() + 50 - piece->pixmap().width() / 2, y() + 50 - piece->pixmap().width() / 2);
	piece->setCurrentTile(this);
	setIsUsedByAPiece(true, piece);
	currentPiece = piece;
}

void Tile::resetToBaseColor() {
	setColor(color_);
}

void Tile::setBaseColor(QColor qColor) {
	color_ = qColor;
	setColor(color_);
}

bool Tile::getIsUsedByAPiece() {
	return isUsedByAPiece_;
}

void Tile::setIsUsedByAPiece(bool isNowUsed, Piece* piece) {
	isUsedByAPiece_ = isNowUsed;
	if (isNowUsed) {
		setPieceColor(piece->getColor());
	}
	else {
		setPieceColor("N/A");
	}
}

QString Tile::getPieceColor() {
	return chessPieceColor_;
}

void Tile::setPieceColor(QString newColor) {
	chessPieceColor_ = newColor;
}

void Tile::analyseForCheck() {
	int c = 0;
	QList<Piece*> piecesList = gameOfChess->piecesInGame;
	
	for (size_t i = 0, n = piecesList.size(); i < n; i++) {
		King* king = dynamic_cast<King*>(piecesList[i]);

		if (king) {
			continue;
		}

		piecesList[i]->movements();
		piecesList[i]->fade();

		QList<Tile*> tilesList = piecesList[i]->movementsList();

		for (size_t j = 0, n = tilesList.size(); j < n; j++) {
			King* king = dynamic_cast<King*>(tilesList[j]->currentPiece);

			if (king) {
				if (king->getColor() == piecesList[i]->getColor()) {
					continue;
				}
				tilesList[j]->setColor(Qt::blue);
				piecesList[i]->getCurrentTile()->setColor(Qt::darkRed);

				if (!gameOfChess->check->isVisible()) {
					gameOfChess->check->setVisible(true);
				}
				else {
					tilesList[j]->resetToBaseColor();
					piecesList[i]->getCurrentTile()->resetToBaseColor();
					gameOfChess->gameOver();
				}
				c++;
			}
		}
	}
	if (!c) {
		gameOfChess->check->setVisible(false);
		for (size_t i = 0, n = piecesList.size(); i < n; i++) {
			piecesList[i]->getCurrentTile()->resetToBaseColor();
		}
	}
}