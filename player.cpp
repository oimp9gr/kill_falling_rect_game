#include "player.h"
#include "settings.h"

#include <QStyleOptionGraphicsItem>

Player::Player(QGraphicsScene *scene, Counter * score)
    : m_score(score)
    , m_movingRight(false)
    , m_movingLeft(false)
{
    setRect(0, 0, PLAYER_SIZE, PLAYER_SIZE);
    setPos(scene->width() / 2 - rect().width() / 2, scene->height() - rect().height());

    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}

void Player::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left) {
        m_movingLeft = true;
    } else if (event->key() == Qt::Key_Right) {
        m_movingRight = true;
    } else if (event->key() == Qt::Key_Space) {
        auto * bullet = new Bullet(m_score);
        bullet->setPos(x() + this->rect().width() / 2, y());
        scene()->addItem(bullet);
    }
}

void Player::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
        m_movingLeft = false;
    else if (event->key() == Qt::Key_Right)
        m_movingRight = false;
}

void Player::advance(int phase)
{
    if (phase == 0) return;

    if (m_movingLeft && x() - PLAYER_SPEED >= 0)
        setPos(x() - PLAYER_SPEED, y());

    if (m_movingRight && x() + rect().width() + PLAYER_SPEED <= VIEW_WIDTH)
        setPos(x() + PLAYER_SPEED, y());
}
