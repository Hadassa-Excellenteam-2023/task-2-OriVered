#pragma once
#include "Utility.h"
#include "Pieces/BasicPiece.h"

class Pawn : public BasicPiece {
public:
    Pawn(PieceColor color, Location location) noexcept
        : BasicPiece(color, location) {}

    bool isValidMove(Location newLocation) const noexcept override;

private:

};
