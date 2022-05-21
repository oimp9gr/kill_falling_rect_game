#include "enemy.h"
#include "settings.h"

#include <QGraphicsScene>

Enemy::Enemy(Counter * heroHealth): m_heroHealth(heroHealth)
{
    setRect(0, 0, ENEMY_SIZE, ENEMY_SIZE);

    setPos(rand() % static_cast<int>(VIEW_WIDTH - rect().width()), 0);
}

void Enemy::advance(int phase)
{
    if (phase == 0) return;

    setPos(x(), y() + ENEMY_SPEED);

    if (y() >= VIEW_HEIGHT) {
        m_heroHealth->decrease();

        scene()->removeItem(this);
        delete this;
    }
}
