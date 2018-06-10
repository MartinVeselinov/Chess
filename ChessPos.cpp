#include "stdafx.h"
#include <iostream>
#include "ChessPosition.h"
#include "ChessPiece.h"
#include "Rook.h"
#include "Knight.h"
using namespace std;

void allMoves(ChessPiece* pieces[], int n)
{	
	for (int i = 0; i < n; ++i) // current piece
	{
		for (int j = 0; j < n; ++j) // other pieces
		{	
			if (j != i) // We must compare different pieces
			{
				ChessPosition* moves = pieces[j]->getAllowedMoves(); // array of moves for the 2nd piece
				for (int k = 0; k < pieces[j]->getCurr(); ++k) // looping through the above array
				{	
					if (pieces[i]->getPosition() == moves[k].getPosition())
					{	
						for (int z = k; z < pieces[j]->getCurr() -1; ++z)
						{	
							moves[z] = moves[z + 1];
						}
						pieces[j]->lowerCurr();						
					}
				}
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{	
		cout << pieces[i]->getPosition() << ":" << endl;
		pieces[i]->display();
		cout << endl;
	}
}
int main()
{	
	ChessPosition a(4, 'D');
	ChessPosition c(2, 'C');
	ChessPosition d(5, 'D');
	
	ChessPiece* b1 = new Knight(a);
	ChessPiece* b2 = new Knight(c);
	ChessPiece* b3 = new Rook(d);
	
	ChessPiece* pieces[2];
	pieces[0] = b1;
	pieces[1] = b3;

	
	allMoves(pieces,2);
	//for (int i = 0; i < 2; ++i) // current piece
	//{
	//	//cout << "First" << endl;
	//	for (int j = 0; j < 2; ++j) // other pieces
	//	{	
	//		//cout << "Second" << endl;
	//		if (j != i) // We must compare different pieces
	//		{	
	//			//cout << "We are in the IF" << endl;
	//			ChessPosition* moves = pieces[j]->getAllowedMoves(); // array of moves for the 2nd piece
	//			for (int k = 0; k < pieces[j]->getCurr(); ++k) // looping through the above array
	//			{	
	//				//cout << "Third" << endl;
	//				if (pieces[i]->getPosition() == moves[k].getPosition())
	//				{	
	//					//cout << "We are in the second IF" << endl;
	//					for (int z = k; z < pieces[j]->getCurr(); ++z)
	//					{	
	//						//cout << "Fourth" << endl;
	//						moves[z] = moves[z + 1];
	//					}
	//					pieces[j]->lowerCurr();
	//				}
	//				//else cout << "Didn't enter the second IF" << endl;
	//			}
	//		}
	//	}
	//}
	//cout << pieces[0]->getPosition() << ":"<< endl;
	//pieces[0]->display();
	//cout << endl;
	//cout << pieces[1]->getPosition() << ":" << endl;
	//pieces[1]->display();

    return 0;
}

