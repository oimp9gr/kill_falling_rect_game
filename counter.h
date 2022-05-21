#ifndef COUNTER_H
#define COUNTER_H

#include <QGraphicsTextItem>
#include <QObject>
#include <QString>

class Counter : public QGraphicsTextItem
{
    Q_OBJECT
public:
    Counter(const QString & label, int startingNumber = 10, QGraphicsItem * parent = nullptr);
    void decrease();
    void increase();
    int getCounter() const;

signals:
    void becomeZero();

private:
    int m_counter;
    QString m_label;
};

#endif // COUNTER_H
