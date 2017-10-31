#ifndef MOVE_H
#define MOVE_H

#include "Constants.h"

class Move
{
    public:
        Move();
        Move(int row, int col);

        int row() const;
        void setRow(int row);

        int col() const;
        void setCol(int col);

        Move convert1Dto2D(const int &idx);
        bool operator !=(const Move &move);

    private:
        int m_row;
        int m_col;
};

#endif // MOVE_H
