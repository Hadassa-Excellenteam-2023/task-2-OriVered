#include "Pieces\Rook.h"


bool Rook::isValidMove(Location newLocation) const noexcept
{
	return (m_location.first == newLocation.first || m_location.second == newLocation.second);
}
