#include <QApplication>

#include "enemy.h"
#include "player.h"
#include "counter.h"
#include "settings.h"

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSimpleTextItem>

#include <QTimer>
#include <QMessageBox>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    auto * scene = new QGraphicsScene(0,0,VIEW_WIDTH,VIEW_HEIGHT);
    scene->setStickyFocus(true) ; // чтобы при нажатии на сцену фокус не сбрасывался

    auto * view = new QGraphicsView(scene);
    // устанавливаем фиксированный размер view равный размеру сцены
    view->setFixedSize(scene->sceneRect().size().toSize());

    // отключаем скролл бар
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    auto * score = new Counter("Score", 0);
    auto * health = new Counter("Health", HEALTH);
    scene->addItem(score);
    scene->addItem(health);

    auto * player = new Player(scene, score);
    scene->addItem(player);

    auto * spawnTimer = new QTimer();
    QObject::connect(spawnTimer,&QTimer::timeout,[&](){
        auto * enemy = new Enemy(health);
        scene->addItem(enemy);
    });
    spawnTimer->start(ENEMY_SPAWN_TIME);

    auto * animationTimer = new QTimer();
    QObject::connect(animationTimer,&QTimer::timeout,scene, &QGraphicsScene::advance);
    animationTimer->start(1000/FRAMES_PER_SECOND);

    QObject::connect(health, &Counter::becomeZero, [&](){
        auto * messageBox = new QMessageBox();
        messageBox->setText(QString("Your score: %1").arg(QString::number(score->getCounter())));
        messageBox->setToolTip("Game over!");
        messageBox->exec();
        QApplication::exit();
    });

    view->show();
    return a.exec();
}
