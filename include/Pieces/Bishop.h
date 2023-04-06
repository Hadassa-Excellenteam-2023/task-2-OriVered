#pragma once
#include "Utility.h"
#include "Pieces/BasicPiece.h"

class Bishop : virtual public BasicPiece {
public:
    /* Constructor */
    Bishop(PieceColor color, Location location) noexcept
        : BasicPiece(color, location) {}
    /* Destructor */
    ~Bishop() override = default;
    /* Access */
    bool isValidMove(Location newLocation) const noexcept override;
};
