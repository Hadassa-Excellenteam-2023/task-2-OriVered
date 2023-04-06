#pragma once
#include "Utility.h"
#include "Pieces/BasicPiece.h"

class Bishop : virtual public BasicPiece {
public:
    Bishop(PieceColor color, Location location) noexcept
        : BasicPiece(color, location) {}

    /* */
    bool isValidMove(Location newLocation) const noexcept override;

    /* Access */

    /* Mutators */


private:

};
