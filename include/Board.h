#pragma once
#include "Pieces/BasicPiece.h"
#include "Pieces/PieceFactory.h"
#include "Pieces/Rook.h"
#include "Utility.h"

class Board {
public:
    Board(const string& initBoard);
    ~Board();
    bool isValidSource(int srcIndex);
    bool isValidDestination(int srcIndex, int destIndex);
    bool isValidMove(int srcIndex, const Location& dest);
    void removePiece(const int& destIndex);
    bool isKingInCheckAfterMove();
    bool isPathClean(int srcIndex, const Location& src, const Location& dest);
    int makeMove(const string& source, const string& destination);
    int findPieceAtLocation(const Location& location);
    //return

    void toggleTurn();
private:
    vector<unique_ptr<BasicPiece>> m_board;
    PieceColor m_turn;

};


