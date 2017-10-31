#include "AppController.h"

AppController::AppController(QQmlApplicationEngine *engine, QObject *parent) : QObject(parent),
    m_engine(engine),
    m_startIdx(-1),
    m_endIdx(-1)
{
    initGridviewModel();
    m_engine->rootContext()->setContextProperty("gridviewModel",&m_gridviewModel);
}

void AppController::initGridviewModel()
{
    for(int i=0; i< ::sizeMap * ::sizeMap; i++){
        Item item("white");
        m_gridviewModel.addItemToList(item);
    }
}

void AppController::clickedCell(const int &index, const int &type)
{
    const Item item = m_gridviewModel.getItemAtIndex(index);
    m_gridviewModel.updateItemAtIndex(item,index, type);

    if(type == 0) {
        if(m_startIdx == -1){
            m_startIdx = index;
        } else {
            m_endIdx = index;
        }
    }
}

void AppController::clickedBtnStart()
{
    if(m_startIdx != -1 && m_endIdx != -1){
        Item arrMatrix[::sizeMap][::sizeMap];
        m_gridviewModel.convertTo2dArr(arrMatrix);
        QList<Move> listPath = m_aStar.findBestPath(arrMatrix,m_startIdx,m_endIdx);

        // update list move to UI
        foreach (Move move, listPath) {
            int idx = move.row() * ::sizeMap + move.col();
            const Item item = m_gridviewModel.getItemAtIndex(idx);
            m_gridviewModel.updateItemAtIndex(item,idx, PATH);
        }
    } else {
        qDebug() << "Can't start";
    }
}

void AppController::clickedBtnReset()
{
    m_startIdx = -1;
    m_endIdx = -1;
    m_gridviewModel.resetList();
}
