#include "stdafx.h"
#include "ChessPosition.h"
#include <iostream>

ChessPosition::ChessPosition()
{
}

ChessPosition::ChessPosition(int n = 0, char l = '\0')
{
	if (n >= 1 && n <= 8 && l >= 'A' && l <= 'H')
	{
		setPos(n, l);
		valid = true;
	}
	else
	{
		std::cout << "Invalid coordinates!";
		valid = false;
		return;
	}
}

ChessPosition::~ChessPosition()
{
}

bool ChessPosition::operator==(ChessPosition const & other)
{
	if (num == other.getNum() && let == other.getLet()) return true;
	else return false;
}

bool ChessPosition::operator!=(ChessPosition const & other)
{
	return !operator==(other);
}

void ChessPosition::setPos(int a, char b)
{
	if (a >= 1 && a <= 8 && b >= 'A' && b <= 'H')
	{
		num = a;
		let = b;
		valid = true;
	}
	else
	{
		std::cout << "Invalid coordinates!";
		valid = false;
	}
	
}

void ChessPosition::getPos() const
{	
	if(valid)
	std::cout << let << " " << num << std::endl;
	else return;
}

