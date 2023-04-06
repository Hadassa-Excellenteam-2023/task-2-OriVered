#pragma once
#include "Utility.h"

enum class PieceColor {
    WHITE,
    BLACK,
};



class BasicPiece {
public:
    /* Constructor */
    BasicPiece(PieceColor color, Location location) noexcept
        : m_color(color), m_location(location) {}

    /* Destructor */
    virtual ~BasicPiece() = default;

    /* Accessors */
    virtual bool isValidMove(Location newLocation) const { return false; };
    PieceColor get_color() const noexcept;
    Location get_location() const noexcept;

    /* Mutators */
    void set_location(Location location) noexcept;

protected:
    PieceColor m_color;
    Location m_location;
};
