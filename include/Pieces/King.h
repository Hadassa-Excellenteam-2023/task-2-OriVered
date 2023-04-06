#pragma once
#include "Utility.h"
#include "Pieces/BasicPiece.h"

class King : public BasicPiece {
public:
    King(PieceColor color, Location location) noexcept
        : BasicPiece(color, location) {}

    /* */
    bool isValidMove(Location newLocation) const noexcept override;

    /* Access */

    /* Mutators */


private:

};
