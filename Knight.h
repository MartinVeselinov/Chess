#pragma once
#include "ChessPiece.h"
class Knight :
	public ChessPiece
{
private:
	int num;
	char let;
	int curr;
	ChessPosition * allowed;
public:
	Knight(const ChessPosition& );
	~Knight();
	bool allow(int, char) const;
	ChessPosition getPosition() const;
	ChessPosition* getAllowedMoves();
	bool captures(ChessPosition pos) const;
	void display() const;
	int getCurr() const { return curr; }
	void lowerCurr() { --curr; }
};

