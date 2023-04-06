#pragma once
#include "Utility.h"
#include "Pieces/Bishop.h"
#include "Pieces/Rook.h"

class Queen : public Rook, public Bishop {
public:
    /* Constructor */
    Queen(PieceColor color, Location location) noexcept
        : BasicPiece(color, location), Rook(color, location), Bishop(color, location) {}

    /* Destructor */
    ~Queen() override = default;

    /* Accessors */
    bool isValidMove(Location newLocation) const noexcept override;
};
