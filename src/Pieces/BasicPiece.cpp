#pragma once
#include "Pieces/BasicPiece.h"

/* Access */
PieceColor BasicPiece::get_color() const noexcept { return m_color; }
Location BasicPiece::get_location() const noexcept { return m_location; }

/* Mutators */
void BasicPiece::set_location(Location location) noexcept {
    m_location = location;
}