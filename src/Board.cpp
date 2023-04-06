#pragma once
#include "board.h"

Board::Board(const string& initBoard)
    :m_turn(PieceColor::WHITE)
{
    for (size_t i = 0; i < initBoard.length(); ++i) {
        auto piece = PieceFactory::createPiece(initBoard[i], convertToLocation(i));
        if(piece) m_board.push_back(std::move(piece));
    }

}

Board::~Board() {

}



bool Board::isValidSource(int srcIndex) {
    if (srcIndex == -1) return false;
    return m_board[srcIndex]->get_color() == m_turn;
}

bool Board::isValidDestination(int srcIndex, int destIndex) {
    return destIndex == -1 || m_board[destIndex]->get_color() != m_turn;
}

bool Board::isValidMove(int srcIndex, const Location& dest) {
    return m_board[srcIndex]->isValidMove(dest);
}

void Board::removePiece(const int& destIndex)
{
    if(destIndex != -1)
        m_board.erase(m_board.begin() + destIndex);
}

bool Board::isKingInCheckAfterMove() {
    Location kingLoc;
    for (auto& piece : m_board)
        if (typeid(*piece) == typeid(King) && piece->get_color() == m_turn)
            kingLoc = piece->get_location();

    for (auto& piece : m_board)
    {
        if (piece->get_color() != m_turn)
        {
            auto src = piece->get_location();
            auto srcIndex = findPieceAtLocation(src);
            if (isValidMove(srcIndex, kingLoc) && isPathClean(srcIndex, src, kingLoc)) {
                // Try to capture the threatening piece and check if the king is still in check
                auto capturedPiece = std::move(m_board[srcIndex]);
                m_board.erase(m_board.begin() + srcIndex);
                bool kingStillInCheck = isKingInCheckAfterMove();
                m_board.insert(m_board.begin() + srcIndex, std::move(capturedPiece));

                if (!kingStillInCheck) return false;
            }
        }
    }
    return true;
}



bool Board::isPathClean(int srcIndex, const Location& src, const Location& dest) {
    auto path = getPath(src, dest);
    for (auto& loc : path) {
        int locIndex = findPieceAtLocation(loc);
        if (locIndex != -1 && m_board[locIndex]->get_color() == m_turn)
            return false;
    }
    return true;
}

int Board::makeMove(const string& source, const string& destination) {
    auto src = convertToLocationFromStr(source);
    auto dest = convertToLocationFromStr(destination);

    int srcIndex = findPieceAtLocation(src);
    int destIndex = findPieceAtLocation(dest);

    if (!isValidSource(srcIndex)) return 11;
    if (!isValidDestination(srcIndex, destIndex)) return 12;
    if (!isValidMove(srcIndex, dest)) return 21;
    if (!isPathClean(srcIndex, src, dest)) return 21;
    m_board[srcIndex]->set_location(dest);
    if (!isKingInCheckAfterMove()) {
        m_board[srcIndex]->set_location(src);
        return 31;
    }

    removePiece(destIndex);

    toggleTurn();
    return !isKingInCheckAfterMove() ? 41: 42;
}


int Board::findPieceAtLocation(const Location& location) {
    auto it = std::find_if(m_board.begin(), m_board.end(), [location](const std::unique_ptr<BasicPiece>& piece) {
        return piece->get_location() == location;
        });
    return (it == m_board.end()) ? -1 : std::distance(m_board.begin(), it);
}

void Board::toggleTurn()
{
    if (m_turn == PieceColor::WHITE)
        m_turn = PieceColor::BLACK;
    else 
        m_turn = PieceColor::WHITE;
    
}
