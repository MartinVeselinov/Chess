#include "stdafx.h"
#include "ChessPiece.h"


ChessPiece::ChessPiece()
{
}

ChessPiece::ChessPiece(const ChessPosition& pos)
{
	this->pos = pos;
}

ChessPiece::~ChessPiece()
{
}
ChessPosition ChessPiece::getPosition() const
{
	return pos;
}
void ChessPiece::display() const
{
	pos.getPos();
}
