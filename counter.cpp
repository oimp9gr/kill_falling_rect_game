#include "counter.h"
#include "settings.h"

#include <QFont>

Counter::Counter(const QString & label, int startingNumber, QGraphicsItem * parent)
    : QGraphicsTextItem(parent)
    , m_label(label)
{
    m_counter = startingNumber;

    setPlainText(QString("%1: %2").arg(m_label).arg(QString::number(m_counter)));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));

    static int id = 0;

    setPos(20, 20 + 40 * id);
    id++;
}

void Counter::increase(){
    ++m_counter;
    setPlainText(QString("%1: %2").arg(m_label, QString::number(m_counter)));
}

void Counter::decrease(){
    --m_counter;
    setPlainText(QString("%1: %2").arg(m_label, QString::number(m_counter)));

    if (!m_counter)
        emit becomeZero();
}

int Counter::getCounter() const {
    return m_counter;
}
