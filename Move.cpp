#include "Move.h"

Move::Move()
{

}

Move::Move(int row, int col) :
    m_row(row),
    m_col(col)
{

}

int Move::row() const
{
    return m_row;
}

void Move::setRow(int row)
{
    m_row = row;
}

int Move::col() const
{
    return m_col;
}

void Move::setCol(int col)
{
    m_col = col;
}

Move Move::convert1Dto2D(const int &idx)
{
    int row = idx / sizeMap;
    int col = idx % sizeMap;
    return Move(row,col);
}

bool Move::operator !=(const Move &move)
{
    if(this->col() != move.col() || this->row() != move.row()) return true;
    return false;
}
