#pragma once
#include "Utility.h"
#include "Pieces/Rook.h" 
#include "Pieces/King.h" 
#include "Pieces/Knight.h" 
#include "Pieces/Bishop.h" 
#include "Pieces/Queen.h" 
#include "Pieces/Pawn.h" 
class PieceFactory {
public:
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