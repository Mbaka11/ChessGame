/*
* Author: Marsel Bakashob and Massil Sebba
* Date: may 6th 2022
* Description: implementation of a single game of chess
*/
#include "GameOfChess.h"
#include "HomepageButton.h"
#include "King.h"

#include <QPixmap>

GameOfChess::GameOfChess(QWidget* parent)
	: QGraphicsView(parent){

	game = new QGraphicsScene();
	game->setSceneRect(0, 0, 900, 900);

	setFixedSize(900, 900);
	setScene(game);

	QBrush brush;
	brush.setStyle(Qt::SolidPattern);
	brush.setColor(Qt::white);
	setBackgroundBrush(brush);

	selectedPiece = nullptr;

	turnOfText = new QGraphicsTextItem();
	turnOfText->setPos(width() / 2 - 100, 10);
	turnOfText->setZValue(1);
	turnOfText->setDefaultTextColor(Qt::darkGray);
	turnOfText->setFont(QFont("", 20));
	turnOfText->setPlainText("Turn : white");

	check = new QGraphicsTextItem();
	check->setPos(width() / 2 - 100, 860);
	check->setZValue(4);
	check->setDefaultTextColor(Qt::red);
	check->setFont(QFont("", 20));
	check->setPlainText("Check ");
	check->setVisible(false);

	setTurn("white");
}

void GameOfChess::initChessBoard(){
	chessboard = new Chessboard();
	chessboard->showTiles(width() / 2 - 400, 50);
}


void GameOfChess::addToScene(QGraphicsItem* item) {
	game->addItem(item);
}

void GameOfChess::removeFromScene(QGraphicsItem* item) {
	game->removeItem(item);
}

QString GameOfChess::getTurn() {
	return liveTurn;
}

void GameOfChess::setTurn(QString color) {
	liveTurn = color;
}

void GameOfChess::changeTurn() {
	if (getTurn() == "white") {
		setTurn("black");

		QBrush brush;
		brush.setStyle(Qt::SolidPattern);
		brush.setColor(Qt::black);
		setBackgroundBrush(brush);
	}
	else {
		setTurn("white");

		QBrush brush;
		brush.setStyle(Qt::SolidPattern);
		brush.setColor(Qt::white);
		setBackgroundBrush(brush);
	}
	turnOfText->setPlainText("Turn : " + getTurn());
}

void GameOfChess::start() {
	for (size_t i = 0, n = list.size(); i < n; i++) {
		removeFromScene(list[i]);
	}

	addToScene(turnOfText);

	addToScene(check);
	chessboard->addPiece();
}

void GameOfChess::showMenu() {
	initChessBoard();

	QGraphicsTextItem* title = new QGraphicsTextItem("INF1015 Project : Chess");
	title->setFont(QFont("arial", 50));

	title->setPos(width() / 2 - title->boundingRect().width() / 2, 150);
	addToScene(title);
	list.append(title);

	HomepageButton* playButton = new HomepageButton("Play");
	playButton->setPos(width() / 2 - playButton->boundingRect().width() / 2, 300);
	connect(playButton, SIGNAL(clicked()), this, SLOT(start()));
	addToScene(playButton);
	list.append(playButton);

	HomepageButton* exitButton = new HomepageButton("Exit");
	exitButton->setPos(width() / 2 - exitButton->boundingRect().width() / 2, 375);
	connect(exitButton, SIGNAL(clicked()), this, SLOT(close()));
	addToScene(exitButton);

	list.append(exitButton);
}

void GameOfChess::gameOver() {
	setTurn("white");
	piecesInGame.clear();
	chessboard->reset();
}

void GameOfChess::reset() {
	QList<QGraphicsItem*> items = game->items();

	for (size_t i = 0, n = items.size(); i < n; i++) {
		if (items[i] != check) {
			removeFromScene(items[i]);
		}
	}
}