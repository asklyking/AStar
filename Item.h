#ifndef ITEM_H
#define ITEM_H

#include <QObject>

enum ItemType {
    NORMAL,
    OBSTACLE,
    PATH
};


class Item
{
    public:
        Item();
        Item(const QString color);

        QString color() const;
        void setColor(const QString &color);

        bool isObstacle() const;
        void setIsObstacle(bool isObstacle);

    private:
        QString m_color;
        bool m_isObstacle;
};

#endif // ITEM_H
