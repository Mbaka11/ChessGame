/*
* Author: Marsel Bakashob and Massil Sebba
* Date: may 6th 2022
* Description: implementation of the homepage buttons
*/
#include "HomepageButton.h"

#include <QGraphicsTextItem>
#include <QBrush>

HomepageButton::HomepageButton(QString name, QGraphicsItem* parent)
	:QGraphicsRectItem(parent) {
	setRect(0, 0, 200, 50);
	QBrush brush;
	brush.setStyle(Qt::SolidPattern);
	brush.setColor(Qt::darkRed);
	setBrush(brush);

	message_ = new QGraphicsTextItem(name, this);
	int xPosition = rect().width()/2 - message_->boundingRect().width() / 2 ;
	int yPosition = rect().height() / 2 - message_->boundingRect().height() / 2;
	
	message_->setPos(xPosition, yPosition);
	message_->setDefaultTextColor(Qt::white);

	setAcceptHoverEvents(true);
}

void HomepageButton::mousePressEvent(QGraphicsSceneMouseEvent* event) {
	if (event) {
		emit clicked();
	}
}


