#ifndef PLAYER_H
#define PLAYER_H

#include "bullet.h"
#include "counter.h"

#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QObject>

#include <QTimer>
#include <QBrush>
#include <QKeyEvent>
#include <QPainter>

class Player : public QObject, public QGraphicsEllipseItem {
    Q_OBJECT
public:
    Player(QGraphicsScene * scene, Counter * score);

    int getHealth() const;

    // QGraphicsItem interface
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    Counter * m_score;
    bool m_movingRight;
    bool m_movingLeft;

    // QGraphicsItem interface
public:
    void advance(int phase) override;
};

#endif // PLAYER_H
