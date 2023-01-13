/*
* Author: Marsel Bakashob and Massil Sebba
* Date: may 6th 2022
* Description: implementation of the chessboard
*/
#include "ChessBoard.h"
#include "Tile.h"
#include "GameOfChess.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Pawn.h"
#include "Horse.h"

#include <QColor>
#include <cstdlib>
#include <ctime>

extern GameOfChess* gameOfChess;

Chessboard::Chessboard() {
	initBlack();
	initWhite();
}

void Chessboard::showTiles(int x, int y) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Tile* tile = new Tile();
			gameOfChess->tileCollection[i][j] = tile;
			tile->row = i;
			tile->colonne = j;
			tile->setPos(x + 100 * j, y + 100 * i);

			if ((i + j) % 2 == 0) {
				tile->setBaseColor(QColor(183, 131, 80, 255)); 
			}
			else {
				tile->setBaseColor(QColor(82, 51, 19, 255));
			}
			gameOfChess->addToScene(tile);
		}
	}
}

void Chessboard::addPiece() {

	srand(time(0));

	int randomNumber = (rand() % 3) + 1;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Tile* tile = gameOfChess->tileCollection[i][j];
			if (randomNumber == 1) {
				if (i == 2 && j == 1) {
					Piece* piece = new Rook("black");

					tile->placePiece(piece);
					gameOfChess->piecesInGame.append(piece);
					gameOfChess->addToScene(piece);
				}

				if (i == 0 && j == 3) {
					Piece* piece = new King("black");

					tile->placePiece(piece);
					gameOfChess->piecesInGame.append(piece);
					gameOfChess->addToScene(piece);
				}

				if (i == 1 && j == 5) {
					Piece* piece = new Queen("white");

					tile->placePiece(piece);
					gameOfChess->piecesInGame.append(piece);
					gameOfChess->addToScene(piece);
				}

				if (i == 3 && j == 3) {
					Piece* piece = new King("white");

					tile->placePiece(piece);
					gameOfChess->piecesInGame.append(piece);
					gameOfChess->addToScene(piece);
				}
			}

			else if (randomNumber == 2) {
				if (i == 0 && j == 1) {
					Piece* piece = new King("black");

					tile->placePiece(piece);
					gameOfChess->piecesInGame.append(piece);
					gameOfChess->addToScene(piece);
				}

				if (i == 1 && j == 1) {
					Piece* piece = new Rook("black");

					tile->placePiece(piece);
					gameOfChess->piecesInGame.append(piece);
					gameOfChess->addToScene(piece);
				}

				if (i == 2 && j == 2) {
					Piece* piece = new King("white");

					tile->placePiece(piece);
					gameOfChess->piecesInGame.append(piece);
					gameOfChess->addToScene(piece);
				}

				if (i == 3 && j == 0) {
					Piece* piece = new Queen("white");

					tile->placePiece(piece);
					gameOfChess->piecesInGame.append(piece);
					gameOfChess->addToScene(piece);
				}
			}

			else if (randomNumber == 3){
				if (i == 0  && j == 4) {
					Piece* piece = new Queen("black");

					tile->placePiece(piece);
					gameOfChess->piecesInGame.append(piece);
					gameOfChess->addToScene(piece);
				}

				if (i == 3 && j == 6) {
					Piece* piece = new King("black");

					tile->placePiece(piece);
					gameOfChess->piecesInGame.append(piece);
					gameOfChess->addToScene(piece);
				}
				if (i == 1 && j == 6) {
					Piece* piece = new King("white");

					tile->placePiece(piece);
					gameOfChess->piecesInGame.append(piece);
					gameOfChess->addToScene(piece);
				}

				if (i == 1 && j == 7) {
					Piece* piece = new Rook("white");

					tile->placePiece(piece);
					gameOfChess->piecesInGame.append(piece);
					gameOfChess->addToScene(piece);
				}

			}

			//Partie pour avoir un jeu dechec normal de 0

			//if (i < 2) {
			//	static int nbBlackTile;

			//	tile->placePiece(black[nbBlackTile]);
			//	gameOfChess->piecesInGame.append(black[nbBlackTile]);
			//	gameOfChess->addToScene(black[nbBlackTile++]);
			//}
			//if (i > 5) {
			//	static int nbWhiteTile;

			//	tile->placePiece(white[nbWhiteTile]);
			//	gameOfChess->piecesInGame.append(white[nbWhiteTile]);
			//	gameOfChess->addToScene(white[nbWhiteTile++]);
			//}
		}
	}
}

void Chessboard::initWhite() {
	Piece* piece;

	for (int i = 0; i < 8; i++) {
		piece = new Pawn("white");
		white.append(piece);
	}

	piece = new Rook("white");
	white.append(piece);

	piece = new Horse("white");
	white.append(piece);

	piece = new Bishop("white");
	white.append(piece);

	piece = new Queen("white");
	white.append(piece);

	piece = new King("white");
	white.append(piece);

	piece = new Bishop("white");
	white.append(piece);

	piece = new Horse("white");
	white.append(piece);

	piece = new Rook("white");
	white.append(piece);
}

void Chessboard::initBlack() {
	Piece* piece;

	piece = new Rook("black");
	black.append(piece);

	piece = new Horse("black");
	black.append(piece);

	piece = new Bishop("black");
	black.append(piece);

	piece = new Queen("black");
	black.append(piece);

	piece = new King("black");
	black.append(piece);

	piece = new Bishop("black");
	black.append(piece);

	piece = new Horse("black");
	black.append(piece);

	piece = new Rook("black");
	black.append(piece);

	for (int i = 0; i < 8; i++) {
		piece = new Pawn("black");
		black.append(piece);
	}
}

void Chessboard::reset() {
	int indexBlack = 0; 
	int indexWhite = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Tile* tile = gameOfChess->tileCollection[i][j];

			tile->setIsUsedByAPiece(false);
			tile->setPieceColor("N/A");
			tile->currentPiece = nullptr;

			if (i < 2) {
				tile->placePiece(black[indexBlack]);
				black[indexBlack]->setIsInGame(true);
				black[indexBlack]->isFirstMove = true;
				gameOfChess->piecesInGame.append(black[indexBlack++]);
			}
			else if (i > 5) {
				tile->placePiece(white[indexWhite]);
				white[indexWhite]->setIsInGame(true);
				white[indexWhite]->isFirstMove = true;
				gameOfChess->piecesInGame.append(white[indexWhite++]);
			}
		}
	}
}