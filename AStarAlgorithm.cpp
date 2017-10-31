#include "AStarAlgorithm.h"

AStarAlgorithm::AStarAlgorithm(QObject *parent) : QObject(parent)
{

}

QList<Move> AStarAlgorithm::findBestPath(Item arrMatrix[sizeMap][sizeMap], int startIdx, int endIdx)
{
    Q_UNUSED(arrMatrix)

    // clear move
    m_listPath.clear();

    Move startMove,endMove;
    startMove = startMove.convert1Dto2D(startIdx);
    endMove = endMove.convert1Dto2D(endIdx);

    while(startMove != endMove){
        startMove = findBestMove(arrMatrix, startMove,endMove);
        m_listPath.push_back(startMove);
    }

    m_listPath.removeLast();

    return m_listPath;
}

Move AStarAlgorithm::findBestMove(Item arrMatrix[sizeMap][sizeMap], Move &startMove, const Move &endMove)
{
    qreal distance = sqrt(sizeMap*sizeMap);
    Move bestMove(-1,-1);
    //left
    if(startMove.col()-1 >=0){
        if(!arrMatrix[startMove.row()][startMove.col()-1].isObstacle() &&
                calculateEuclideanDistance(Move(startMove.row(),startMove.col()-1),endMove) < distance){
            distance = calculateEuclideanDistance(Move(startMove.row(),startMove.col()-1),endMove);
            bestMove = Move(startMove.row(),startMove.col()-1);
        }
    }

    //right
    if(startMove.col()+1 < sizeMap){
        if(!arrMatrix[startMove.row()][startMove.col()+1].isObstacle() &&
                calculateEuclideanDistance(Move(startMove.row(),startMove.col()+1),endMove) < distance) {
            distance = calculateEuclideanDistance(Move(startMove.row(),startMove.col()+1),endMove);
            bestMove = Move(startMove.row(),startMove.col()+1);
        }
    }

    //up
    if(startMove.row()-1 >= 0){
        if(!arrMatrix[startMove.row()-1][startMove.col()].isObstacle() &&
                calculateEuclideanDistance(Move(startMove.row()-1,startMove.col()),endMove) < distance) {
            distance = calculateEuclideanDistance(Move(startMove.row()-1,startMove.col()),endMove);
            bestMove = Move(startMove.row()-1,startMove.col());
        }
    }

    //down
    if(startMove.row()+1 < sizeMap){
        if(!arrMatrix[startMove.row()+1][startMove.col()].isObstacle() &&
                calculateEuclideanDistance(Move(startMove.row()+1,startMove.col()),endMove) < distance) {
            distance = calculateEuclideanDistance(Move(startMove.row()+1,startMove.col()),endMove);
            bestMove = Move(startMove.row()+1,startMove.col());
        }
    }

    //left up
    if(startMove.col()-1 >=0 && startMove.row()-1 >=0){
        if(!arrMatrix[startMove.row()-1][startMove.col()-1].isObstacle() &&
                calculateEuclideanDistance(Move(startMove.row()-1,startMove.col()-1),endMove) < distance) {
            distance = calculateEuclideanDistance(Move(startMove.row()-1,startMove.col()-1),endMove);
            bestMove = Move(startMove.row()-1,startMove.col()-1);
        }
    }

    //right up
    if(startMove.row()-1 >=0 && startMove.col()+1 < sizeMap ){
        if(!arrMatrix[startMove.row()-1][startMove.col()+1].isObstacle() &&
                calculateEuclideanDistance(Move(startMove.row()-1,startMove.col()+1),endMove) < distance) {
            distance = calculateEuclideanDistance(Move(startMove.row()-1,startMove.col()+1),endMove);
            bestMove = Move(startMove.row()-1,startMove.col()+1);
        }
    }

    //right down
    if(startMove.row()+1 < sizeMap && startMove.col()+1 < sizeMap){
        if(!arrMatrix[startMove.row()+1][startMove.col()+1].isObstacle() &&
                calculateEuclideanDistance(Move(startMove.row()+1,startMove.col()+1),endMove) < distance) {
            distance = calculateEuclideanDistance(Move(startMove.row()+1,startMove.col()+1),endMove);
            bestMove = Move(startMove.row()+1,startMove.col()+1);
        }
    }

    //left down
    if(startMove.row()+1 < sizeMap && startMove.col()-1 >=0){
        if(!arrMatrix[startMove.row()+1][startMove.col()-1].isObstacle() &&
                calculateEuclideanDistance(Move(startMove.row()+1,startMove.col()-1),endMove) < distance) {
            distance = calculateEuclideanDistance(Move(startMove.row()+1,startMove.col()-1),endMove);
            bestMove = Move(startMove.row()+1,startMove.col()-1);
        }
    }

    return bestMove;
}

qreal AStarAlgorithm::calculateEuclideanDistance(const Move &startMove, const Move &endMove)
{
    qreal distance = sqrt(pow(startMove.row()-endMove.row(),2)+pow(startMove.col()-endMove.col(),2));
    return distance;
}
