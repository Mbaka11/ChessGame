/*
* Author: Marsel Bakashob and Massil Sebba
* Date: may 6th 2022
* Description: header of a single game of chess
*/

#ifndef GAMEOFCHESS_H
#define GAMEOFCHESS_H

#include <QGraphicsView>
#include <QGraphicsScene>

#include "ChessBoard.h"
#include "Piece.h"

class GameOfChess : public QGraphicsView {
	Q_OBJECT

public:
	GameOfChess(QWidget* parent = nullptr);

	void initChessBoard();

	void addToScene(QGraphicsItem* item);
	void removeFromScene(QGraphicsItem* item);

	QString getTurn();
	void setTurn(QString color);
	void changeTurn();

	QGraphicsTextItem* check;
	QList <Piece*> piecesInGame;

	void showMenu();

	void gameOver();
	void reset();

	Piece* selectedPiece;
	Tile* tileCollection[8][8];

public slots:
	void start();

private:
	QGraphicsScene* game;
	QString liveTurn;
	Chessboard* chessboard;
	QList<QGraphicsItem*> list;
	QGraphicsTextItem* turnOfText;
};


#endif