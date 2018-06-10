#include "stdafx.h"
#include "Rook.h"
#include <iostream>

Rook::Rook(const ChessPosition& pos) : ChessPiece(pos)
{
	allowed = new ChessPosition[15];
	curr = 0;
	num = pos.getNum();
	let = pos.getLet();
}


Rook::~Rook()
{
	delete[] allowed;
}

ChessPosition Rook::getPosition() const
{
	return ChessPiece::getPosition();
}

ChessPosition* Rook::getAllowedMoves()
{
	for (int i = 1; i <= 8; ++i)
	{
		for (char k = 'A'; k <= 'H'; ++k)
		{	
			ChessPosition a;
			if (!(i == num && k == let) && (i == num || k == let))
			{	
				a.setPos(i, k);
				allowed[curr++] = a;
			}
		}
	}
	return allowed;
}

bool Rook::captures(ChessPosition pos) const
{
	for (int i = 0; i < curr; ++i)
	{	
		if (allowed[i].getLet() == pos.getLet() && allowed[i].getNum() == pos.getNum()) return true;
	}
	return false;
}

void Rook::display() const
{
	for (int i = 0; i < curr; ++i)
	{
		allowed[i].getPos();
	}
}

