#pragma once
#include "ChessPiece.h"
#include <iostream>
class Rook :public ChessPiece
{
private:
	int num;
	int curr;
	char let;
	ChessPosition * allowed;
public:
	Rook(const ChessPosition& pos);
	~Rook();
	ChessPosition getPosition() const;
	ChessPosition* getAllowedMoves();
	bool captures(ChessPosition pos) const;
	void display() const;
	void lowerCurr() { --curr; }
	int getCurr() const { return curr; }
};

