#include "GridviewModel.h"

GridviewModel::GridviewModel(QObject *parent) : QAbstractListModel(parent)
{

}

void GridviewModel::addItemToList(const Item item)
{
    beginInsertRows(QModelIndex(),rowCount(),rowCount());
    m_listModel.append(item);
    endInsertRows();
}

void GridviewModel::updateItemAtIndex(const Item &item, const int &idx, const int &type)
{
    Q_UNUSED(item)
    switch (type) {
        case NORMAL:
            m_listModel[idx].setColor("red");
            break;
        case OBSTACLE:
            m_listModel[idx].setIsObstacle(true);
            m_listModel[idx].setColor("gray");
            break;
        case PATH:
            m_listModel[idx].setColor("blue");
            break;
        default:
            break;
    }

    dataChanged(index(idx),index(idx));
}

const Item GridviewModel::getItemAtIndex(const int idx)
{
    return m_listModel.at(idx);
}

void GridviewModel::convertTo2dArr(Item arrMatrix[sizeMap][sizeMap])
{
    for(int i=0; i< sizeMap*sizeMap; i++){
        arrMatrix[i/sizeMap][i%sizeMap] = m_listModel[i];
    }
}

void GridviewModel::resetList()
{
    //    foreach (Item item, m_listModel) {
    //        item.setColor("white");
    //        //        dataChanged(index(ind),index(idx));
    //    }

    for(int i=0;i< m_listModel.length();i++){
        m_listModel[i].setColor("white");
        dataChanged(index(i),index(i));
    }
}

QVariant GridviewModel::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() >= m_listModel.count()){
        return QVariant();
    }
    if(role == ColorRole){
        return m_listModel.at(index.row()).color();
    }

    return QVariant();
}

int GridviewModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_listModel.count();
}

QHash<int, QByteArray> GridviewModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[ColorRole] = strColor;
    return roles;
}
