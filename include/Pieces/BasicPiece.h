#pragma once
#include "Utility.h"

enum class PieceColor {
    WHITE,
    BLACK,
};



class BasicPiece {
public:
    BasicPiece(PieceColor color, Location location) noexcept
        : m_color(color), m_location(location) {}

    /*  */
    virtual bool isValidMove(Location newLocation) const { return false; };

    /* Access */
    PieceColor get_color() const noexcept;
    Location get_location() const noexcept;

    string get_x() const noexcept;
    int get_y() const noexcept;

    /* Mutators */
    void set_location(Location location) noexcept;

protected:
    PieceColor m_color;
    Location m_location;
};
