#pragma once
#include "Pieces/BasicPiece.h"

/* Access */
PieceColor BasicPiece::get_color() const noexcept { return m_color; }
Location BasicPiece::get_location() const noexcept { return m_location; }

string BasicPiece::get_x() const noexcept { return m_location.first; }
int BasicPiece::get_y() const noexcept { return m_location.second; }

/* Mutators */
void BasicPiece::set_location(Location location) noexcept {
    m_location = location;
}