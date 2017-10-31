#include "Item.h"

Item::Item()
{

}

Item::Item(const QString color) :
    m_color(color),
    m_isObstacle(false)
{

}

QString Item::color() const
{
    return m_color;
}

void Item::setColor(const QString &color)
{
    m_color = color;
}

bool Item::isObstacle() const
{
    return m_isObstacle;
}

void Item::setIsObstacle(bool isObstacle)
{
    m_isObstacle = isObstacle;
}
