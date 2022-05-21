#ifndef BULLET_H
#define BULLET_H

#include "counter.h"

#include <QObject>
#include <QGraphicsRectItem>

class Bullet : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Bullet(Counter * score);
    virtual ~Bullet() {}

private:
    Counter * m_score;

    // QGraphicsItem interface
public:
    void advance(int phase) override;
};

#endif // BULLET_H
