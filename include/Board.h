#pragma once
#include "Pieces/BasicPiece.h"
#include "Pieces/PieceFactory.h"
#include "Pieces/Rook.h"
#include "Utility.h"

class Board {
public:
    /* Constructor */
    Board(const string& initBoard);

    /* Destructor */
    ~Board();

    /* Accessors */
    int makeMove(const string& source, const string& destination);

private:
    /* Private methods */
    bool isValidSource(int srcIndex);
    bool isValidDestination(int srcIndex, int destIndex);
    bool isValidMove(int srcIndex, const Location& dest);
    void removePiece(const int& destIndex);
    bool isKingInCheckAfterMove(const Location& dest);
    bool isPathClean(int srcIndex, const Location& src, const Location& dest);

    int findPieceAtLocation(const Location& location);

    void toggleTurn();

    /* Private members */
    vector<unique_ptr<BasicPiece>> m_board;
    PieceColor m_turn;
};


