#pragma once
#include "Utility.h"
#include "Pieces/BasicPiece.h"

class Pawn : public BasicPiece {
public:
    /* Constructor */
    Pawn(PieceColor color, Location location) noexcept
        : BasicPiece(color, location) {}

    /* Accessors */
    bool isValidMove(Location newLocation) const noexcept override;
};
