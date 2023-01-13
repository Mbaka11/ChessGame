/*
* Author: Marsel Bakashob and Massil Sebba
* Date: may 6th 2022
* Description: header of the buttons on the homepage
*/

#ifndef HOMEPAGEBUTTON_H
#define HOMEPAGEBUTTON_H

#include <QGraphicsSceneMouseEvent> 
#include <QGraphicsRectItem>

class HomepageButton : public QObject, public QGraphicsRectItem {
	Q_OBJECT
public:
	HomepageButton(QString name, QGraphicsItem* parent = nullptr);
	~HomepageButton() = default;

	void mousePressEvent(QGraphicsSceneMouseEvent* event);

signals :
	void clicked();

private:
	QGraphicsTextItem* message_;
};

#endif 