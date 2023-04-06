#pragma once
#include "board.h"
 /*Constructor for the Board class.
 Takes a string representing the initial board state and initializes the board with the pieces.

 Parameters:
 - initBoard: A string representing the initial board state. Each character in the string represents
   a piece on the board (uppercase for white, lowercase for black), or a space for an empty square.
   The string should be ordered from the top-left corner (A8) to the bottom-right corner (H1).*/
Board::Board(const string& initBoard)
    :m_turn(PieceColor::WHITE)
{
    for (size_t i = 0; i < initBoard.length(); ++i) {
        auto piece = PieceFactory::createPiece(initBoard[i], convertToLocation(i));
        if (piece) m_board.push_back(std::move(piece));
    }
}

/*Destructor for the Board class.
 Cleans up resources associated with the board.*/ 
Board::~Board() {}

/*Checks if the given source index is a valid index for a move.
 The source index is valid if it corresponds to a non-empty square and the piece at that square
 has the same color as the current player's turn.

 Parameters:
 - srcIndex: The index of the source piece in the m_board vector.

 Returns:
 - true if the source index is valid, false otherwise. */ 
bool Board::isValidSource(int srcIndex) {
    if (srcIndex == -1) return false;
    return m_board[srcIndex]->get_color() == m_turn;
}

/*Checks if the given destination index is a valid index for a move.
 The destination index is valid if it corresponds to an empty square or a square with a piece
 of the opposite color.

 Parameters:
 - srcIndex: The index of the source piece in the m_board vector.
 - destIndex: The index of the destination square in the m_board vector.

 Returns:
 - true if the destination index is valid, false otherwise.*/
bool Board::isValidDestination(int srcIndex, int destIndex) {
    return destIndex == -1 || m_board[destIndex]->get_color() != m_turn;
}

/* Checks if a move from the source index to the destination location is valid.
 The move is valid if the piece at the source index can legally move to the destination location.

 Parameters:
 - srcIndex: The index of the source piece in the m_board vector.
 - dest: The destination location as a Location object.

 Returns:
 - true if the move is valid, false otherwise.*/
bool Board::isValidMove(int srcIndex, const Location& dest) {
    return m_board[srcIndex]->isValidMove(dest);
}

/* Removes a piece from the board at the specified index.
 If the index is -1, this function does nothing.

 Parameters:
 - destIndex: The index of the piece to remove in the m_board vector.*/
void Board::removePiece(const int& destIndex)
{
    if (destIndex != -1)
        m_board.erase(m_board.begin() + destIndex);
}

 /*Checks if the king of the current player is in check after a move.
 This function iterates through all the opponent's pieces and checks if any of them
 can move to the current player's king's location.

 Returns:
 - false if the king is in check, true otherwise.*/
bool Board::isKingInCheckAfterMove(const Location& dest= Location("0", 0)) {
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
            if (src != dest && isValidMove(srcIndex, kingLoc) && isPathClean(srcIndex, src, kingLoc)) return false;
        }
    }
    return true;
}

/* Checks if the path between the sourceand destination locations is clean(unobstructed).
 This function iterates through the path and checks if any piece is obstructing the move.

 Parameters:
 - srcIndex: The index of the source piece in the m_board vector.
 - src: The source location as a Location object.
 - dest: The destination location as a Location object.

 Returns:
 - true if the path is clean, false otherwise.*/
bool Board::isPathClean(int srcIndex, const Location& src, const Location& dest) {
    auto path = getPath(src, dest);
    for (auto& loc : path) {
        int locIndex = findPieceAtLocation(loc);
        if (locIndex != -1 && m_board[locIndex]->get_color() == m_turn)
            return false;
    }
    return true;
}

/* Makes a move from the source location to the destination location.
 This function checks if the move is legal and performs the move if it is.
 It returns an integer code representing the result of the move.

 Parameters:
 - source: The source location as a string (e.g., "A1").
 - destination: The destination location as a string (e.g., "B2").

 Returns:
 - 11: Source is invalid (e.g., empty square or piece of the opposite color).
 - 12: Destination is invalid (e.g., occupied by a piece of the same color).
 - 21: Move is illegal (e.g., move not allowed by the piece's rules or path is obstructed).
 - 31: Move would put the king in check.
 - 41: Move is legal and doesn't result in check.
 - 42: Move is legal but results in check.*/
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
    if (!isKingInCheckAfterMove(dest)) {
        m_board[srcIndex]->set_location(src);
        return 31;
    }

    removePiece(destIndex);

    toggleTurn();

    return !isKingInCheckAfterMove() ? 41: 42;
}

/* Finds the index of a piece at the given location in the m_board vector.
 If there's no piece at the given location, returns -1.

 Parameters:
 - location: The location to search for as a Location object.

 Returns:
 - The index of the piece at the location in the m_board vector, or -1 if not found.*/
int Board::findPieceAtLocation(const Location& location) {
    auto it = std::find_if(m_board.begin(), m_board.end(), [location](const std::unique_ptr<BasicPiece>& piece) {
        return piece->get_location() == location;
        });
    return (it == m_board.end()) ? -1 : std::distance(m_board.begin(), it);
}

/*Toggles the turn to the other player.
 This function changes the current player's turn from white to black, or vice versa.*/ 
void Board::toggleTurn()
{
    if (m_turn == PieceColor::WHITE)
        m_turn = PieceColor::BLACK;
    else 
        m_turn = PieceColor::WHITE;
    
}
