#pragma once
#include "Utility.h"
#include "Pieces/BasicPiece.h"

class Rook : virtual  public BasicPiece {
public:
    /* Constructor */
    Rook(PieceColor color, Location location) noexcept
        : BasicPiece(color, location) {}

    /* Destructor */
    ~Rook() override = default;

    /* Accessors */
    bool isValidMove(Location newLocation) const noexcept override;
};
