#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>

#include "Item.h"
#include "GridviewModel.h"
#include "Constants.h"
#include "AStarAlgorithm.h"

class AppController : public QObject
{
        Q_OBJECT
        Q_PROPERTY(int sizeMap READ sizeMap)
        int sizeMap() {
            return ::sizeMap;
        }
    public:
        explicit AppController(QQmlApplicationEngine *engine, QObject *parent = nullptr);

    signals:

    public slots:
        void initGridviewModel();
        void clickedCell(const int &index,const int &type);
        void clickedBtnStart();
        void clickedBtnReset();

    private:
        QQmlApplicationEngine *m_engine;
        GridviewModel m_gridviewModel;
        AStarAlgorithm m_aStar;

        int m_startIdx;
        int m_endIdx;
};

#endif // APPCONTROLLER_H
