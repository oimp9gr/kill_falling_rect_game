#ifndef ENEMY_H
#define ENEMY_H

#include "counter.h"

#include <QGraphicsRectItem>
#include <QTimer>
#include <QGraphicsSimpleTextItem>

class Enemy: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Enemy(Counter * heroHealth);

private:
    Counter * m_heroHealth;

    // QGraphicsItem interface
public:
    void advance(int phase) override;
};

#endif // ENEMY_H
