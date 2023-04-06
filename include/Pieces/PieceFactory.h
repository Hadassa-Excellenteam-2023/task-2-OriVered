/**
 * @file PieceFactory.h
 * @brief Defines the PieceFactory class used for creating chess piece objects.
 */

#pragma once
#include "Utility.h"
#include "Pieces/Rook.h" 
#include "Pieces/King.h" 
#include "Pieces/Knight.h" 
#include "Pieces/Bishop.h" 
#include "Pieces/Queen.h" 
#include "Pieces/Pawn.h"

 /**
  * @class PieceFactory
  * @brief A factory class used for creating unique chess piece objects.
  *
  * This class provides a static method to create chess piece objects based
  * on the given character representing a chess piece and its location on
  * the chessboard.
  */
class PieceFactory {
public:
    /**
     * @brief Creates a unique chess piece object based on the given character and location.
     *
     * This method takes a character representing a chess piece (e.g. 'P' for pawn,
     * 'R' for rook, etc.) and a location on the chessboard, and returns a unique_ptr
     * to the created chess piece object.
     *
     * @param pieceChar A character representing a chess piece.
     * @param location A Location object representing the piece's position on the chessboard.
     * @return A unique_ptr to a BasicPiece object of the appropriate type and color.
     */
    static unique_ptr<BasicPiece> createPiece(const char& pieceChar, const Location& location) {
        PieceColor color = isupper(pieceChar) ? PieceColor::WHITE : PieceColor::BLACK;
        switch (tolower(pieceChar)) {
        case 'p':
            return make_unique<Pawn>(color, location);
        case 'r':
            return make_unique<Rook>(color, location);
        case 'n':
            return make_unique<Knight>(color, location);
        case 'b':
            return make_unique<Bishop>(color, location);
        case 'q':
            return make_unique<Queen>(color, location);
        case 'k':
            return make_unique<King>(color, location);
        default:
            return nullptr;
        }
    }
};
