#ifndef GRIDVIEWMODEL_H
#define GRIDVIEWMODEL_H

#include <QObject>
#include <QAbstractListModel>

#include "Item.h"
#include "Constants.h"
#include "Move.h"

class GridviewModel : public QAbstractListModel
{
        Q_OBJECT

    public:
        enum ItemRoles {
            ColorRole = Qt::UserRole + 1
        };

        explicit GridviewModel(QObject *parent = nullptr);

    signals:

    public slots:


        void addItemToList(const Item item);
        void updateItemAtIndex(const Item &item, const int &idx, const int &type);
        const Item getItemAtIndex(const int idx);
        void convertTo2dArr(Item arrMatrix[sizeMap][sizeMap]);
        void resetList();

        QVariant data(const QModelIndex &index, int role) const;
        int rowCount(const QModelIndex &parent = QModelIndex()) const;
        QHash<int,QByteArray> roleNames() const;

    private:
        QList<Item> m_listModel;
};

#endif // GRIDVIEWMODEL_H
