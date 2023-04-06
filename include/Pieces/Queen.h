#pragma once
#include "Utility.h"
#include "Pieces/Bishop.h"
#include "Pieces/Rook.h"

class Queen : public Rook, public Bishop {
public:
    Queen(PieceColor color, Location location) noexcept
        : BasicPiece(color, location), Rook(color, location), Bishop(color, location) {}

    bool isValidMove(Location newLocation) const noexcept override;

private:

};
