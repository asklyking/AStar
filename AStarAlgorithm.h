#ifndef ASTARALGORITHM_H
#define ASTARALGORITHM_H

#include <QObject>
#include <QDebug>
#include <QtMath>

#include "Constants.h"
#include "Move.h"
#include "Item.h"

class AStarAlgorithm : public QObject
{
        Q_OBJECT
    public:
        explicit AStarAlgorithm(QObject *parent = nullptr);

    signals:

    public slots:
        QList<Move> findBestPath(Item arrMatrix[sizeMap][sizeMap],int startIdx,int endIdx);
        Move findBestMove(Item arrMatrix[sizeMap][sizeMap], Move &startMove, const Move &endMove);
        qreal calculateEuclideanDistance(const Move &startMove, const Move &endMove);

    private:
        QList<Move> m_listPath;
};

#endif // ASTARALGORITHM_H
