#pragma once
#include <iostream>
#include <ostream>
class ChessPosition
{
private:
	int num;
	char let;
	bool valid;
public:
	ChessPosition();
	ChessPosition(int, char);
	~ChessPosition();

	ChessPosition getPosition() const { return *this; }

	bool operator==(ChessPosition const&);
	bool operator!=(ChessPosition const&);
	friend std::ostream& operator<<(std::ostream& os, ChessPosition pos)
	{
		os << pos.let << pos.getNum();
		return os;
	}
	void setPos(int, char);
	void getPos() const;
	int getNum() const { return num; }
	char getLet() const { return let; }
	
};

