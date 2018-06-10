#include "stdafx.h"
#include "Knight.h"
#include <iostream>
int max = 8;

Knight::Knight(const ChessPosition& pos) : ChessPiece(pos)
{
	allowed = new ChessPosition[max];
	curr = 0;
	num = pos.getNum();
	let = pos.getLet();
}


Knight::~Knight()
{
	delete[] allowed;
}

bool Knight::allow(int i, char k) const
{
	if (num + 2 == i && let - 1 == k && (num >= 1 && num <= 8 && let >='A' && let <= 'H' )) return true;
	else if (num + 2 == i && let + 1 == k && (num >= 1 && num <= 8 && let >= 'A' && let <= 'H')) return true;
	else if (num + 2 == i && let + 1 == k && (num >= 1 && num <= 8 && let >= 'A' && let <= 'H')) return true;
	else if (num + 1 == i && let - 2 == k && (num >= 1 && num <= 8 && let >= 'A' && let <= 'H')) return true;
	else if (num + 1 == i && let + 2 == k && (num >= 1 && num <= 8 && let >= 'A' && let <= 'H')) return true;
	else if (num - 1 == i && let - 2 == k && (num >= 1 && num <= 8 && let >= 'A' && let <= 'H')) return true;
	else if (num - 1 == i && let + 2 == k && (num >= 1 && num <= 8 && let >= 'A' && let <= 'H')) return true;
	else if (num - 2 == i && let - 1 == k && (num >= 1 && num <= 8 && let >= 'A' && let <= 'H')) return true;
	else if (num - 2 == i && let + 1 == k && (num >= 1 && num <= 8 && let >= 'A' && let <= 'H')) return true;
	else return false;
}

ChessPosition Knight::getPosition() const
{
	return ChessPiece::getPosition();
}

ChessPosition* Knight::getAllowedMoves()
{
	for (int i = 1; i < 8; ++i)
	{
		for (char k = 'A'; k <= 'H'; ++k)
		{
			ChessPosition a;
			if (allow(i, k))
			{	
				a.setPos(i, k);
				allowed[curr++] = a;
			}
		}
	}
	return allowed;
}

bool Knight::captures(ChessPosition pos) const
{
	for (int i = 0; i < curr; ++i)
	{
		if (allowed[i].getLet() == pos.getLet() && allowed[i].getNum() == pos.getNum()) return true;
	}
	return false;
}

void Knight::display() const
{	
	for (int i = 0; i < curr; ++i)
	{
		allowed[i].getPos();
	}
}
