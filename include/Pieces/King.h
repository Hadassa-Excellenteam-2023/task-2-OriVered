#pragma once
#include "Utility.h"
#include "Pieces/BasicPiece.h"

class King : public BasicPiece {
public:
    /* Constructor */
    King(PieceColor color, Location location) noexcept
        : BasicPiece(color, location) {}

    /* Accessors */
    bool isValidMove(Location newLocation) const noexcept override;
};
