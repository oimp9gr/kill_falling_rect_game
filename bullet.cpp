#include "bullet.h"
#include "settings.h"

#include <QTimer>
#include <QGraphicsScene>
#include <enemy.h>

Bullet::Bullet(Counter * score) : m_score(score)
{
    setRect(0,0,BULLET_SIZE,BULLET_SIZE);
}

void Bullet::advance(int phase)
{
    if (phase == 0) return;

    setPos(x(), y() - BULLET_SPEED);
    auto items = collidingItems();

    // нужен, чтобы обработать ситуацию, когда пуля пересекает сразу несколько объектов
    bool isCollided = false;

    for (auto item: items) {
        if (dynamic_cast<Enemy *>(item)) {
            m_score->increase();
            scene()->removeItem(item);
            isCollided = true;
        }
    }

    if (isCollided) {
        scene()->removeItem(this);
        return;
    }

    if (y() + BULLET_SIZE < 0) {
        scene()->removeItem(this);
    }
}
