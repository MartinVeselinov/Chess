#pragma once
#include "ChessPosition.h"
class ChessPiece
{
private: 
	ChessPosition pos;
public:
	ChessPiece();
	ChessPiece(const ChessPosition& pos);
	~ChessPiece();
	virtual ChessPosition getPosition() const = 0;
	virtual ChessPosition* getAllowedMoves() = 0;
	virtual bool captures(ChessPosition pos) const = 0;
	virtual void display() const;
	virtual int getCurr() const = 0;
	virtual void lowerCurr(){}
	virtual void setMoves(ChessPosition*) {};
	
};

