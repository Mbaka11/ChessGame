/*
* Author: Marsel Bakashob and Massil Sebba
* Date: may 6th 2022
* Description: implementation of one piece
*/
#include "Piece.h"
#include "GameOfChess.h"
#include "King.h"

extern GameOfChess* gameOfChess;

Piece::Piece(QString color, QGraphicsItem* parent)
	:QGraphicsPixmapItem(parent) {
	color_ = color;
	isInGame_ = true;
	isFirstMove = true;
}

void Piece::mousePressEvent(QGraphicsSceneMouseEvent* event) {
	if (this == gameOfChess->selectedPiece) {
		gameOfChess->selectedPiece->getCurrentTile()->resetToBaseColor();
		gameOfChess->selectedPiece->fade();
		gameOfChess->selectedPiece = nullptr;

		return;
	}
	else if ((!getIsInGame()) || (gameOfChess->getTurn() != this->getColor()) && (!gameOfChess->selectedPiece)) {
		return;
	}
	else if (!gameOfChess->selectedPiece) {
		gameOfChess->selectedPiece = this;
		gameOfChess->selectedPiece->getCurrentTile()->setColor(Qt::red);
		gameOfChess->selectedPiece->movements();
	}
	else if (this->getColor() != gameOfChess->selectedPiece->getColor()) {
		this->getCurrentTile()->mousePressEvent(event);
	}
}
void Piece::setCurrentTile(Tile* tile) {
	currentTile_ = tile;
}

Tile* Piece::getCurrentTile() {
	return currentTile_;
}

QString Piece::getColor() {
	return color_;
}

void Piece::setColor(QString newColor) {
	color_ = newColor;
}

void Piece::fade() {
	for (size_t i = 0, n = movements_.size(); i < n; i++) {
		movements_[i]->resetToBaseColor();
	}
}

bool Piece::getIsInGame() {
	return isInGame_;
}

bool Piece::isTile(Tile* tile) {
	if (tile->getIsUsedByAPiece()) {
		King* king = dynamic_cast<King*>(movements_.last()->currentPiece);
		if (king) {
			tile->setColor(Qt::green);
		}
		else {
			tile->setColor(Qt::red);
		}
		return true;
	}
	else {
		movements_.last()->setColor(Qt::darkRed);
	}
	return false;
}

void Piece::setIsInGame(bool isStillInGame) {
	isInGame_ = isStillInGame;
}

QList<Tile*> Piece::movementsList() {
	return movements_;
}

