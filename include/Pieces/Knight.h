#pragma once
#include "Utility.h"
#include "Pieces/BasicPiece.h"

class Knight : public BasicPiece {
public:
    Knight(PieceColor color, Location location) noexcept
        : BasicPiece(color, location) {}

    /* */
    bool isValidMove(Location newLocation) const noexcept override;

    /* Access */

    /* Mutators */


private:

};
