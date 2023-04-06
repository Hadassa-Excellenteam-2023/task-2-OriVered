#pragma once
#include "Utility.h"
#include "Pieces/BasicPiece.h"

class Rook : virtual  public BasicPiece {
public:
    Rook(PieceColor color, Location location) noexcept
        : BasicPiece(color, location) {}

    /* */
    bool isValidMove(Location newLocation) const noexcept override;

    /* Access */

    /* Mutators */


private:

};
