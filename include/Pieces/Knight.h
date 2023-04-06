#pragma once
#include "Utility.h"
#include "Pieces/BasicPiece.h"

class Knight : public BasicPiece {
public:
    /* Constructor */
    Knight(PieceColor color, Location location) noexcept
        : BasicPiece(color, location) {}

    /* Accsseors */
    bool isValidMove(Location newLocation) const noexcept override;
};
