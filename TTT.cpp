#include "TTT.h"

TTT::TTT()
{
}

//handles initialization
TTT::game TTT::createGame(player X, player O)
{
	cout << "initialized game board" << endl;

	TTT::game output;
	output.playerOne = X;
	output.playerTwo = O;

	return output;
}

//returns a basic player object
TTT::player TTT::createPlayer(string name, bool human = false)
{
	TTT::player output;

	output.human = human;
	output.setName(name);

	return output;
}

//main loop that plays the game
int TTT::play(game* instance)
{
	//preform modulo in gameTurn to see if its X's or O's turn
	int turn = 1;
	int winner = 0;
	while(true)
	{
		//print the current gameboard
		this->printGame(instance);

		//run the main function to determine whos turn it is
		this->gameTurn(instance, turn);

		//check if we have a winner yet
		winner = checkWinner(instance);

		//if we have a winner preform game over
		if(winner != 0)
		{
			this->gameOver(winner);
			break;
		}

		//add one to turn counter
		turn++;
	}

	//return the winner (1 or 2)
	return winner;
}

//prints the gameboard to console
void TTT::printGame(game* gi)
{
	system("cls");

	int block = 1;
	string buffer = "";
	for(int x=0; x<3; x++)
	{
		for(int y=0; y<3; y++)
		{
			//tell us what we want printed to console
			int piece = gi->board[x][y];
			switch (piece)
			{
			case 0:
				buffer += " "; break;

			case 1:
				buffer += "X"; break;

			case 2:
				buffer += "O"; break;
			}

			switch (block)
			{
			case 1:
				buffer += "|"; break;
			case 2:
				buffer += "|"; break;
			case 3:
				buffer +="\r\n-----\r\n"; break;
			case 4:
				buffer += "|"; break;
			case 5:
				buffer += "|"; break;
			case 6:
				buffer +="\r\n-----\r\n"; break;
			case 7:
				buffer += "|"; break;
			case 8:
				buffer += "|"; break;
			case 9:
				buffer +="\r\n"; break;
			}
			//add one to our block
			block++;
		}
	}
	//print to console
	cout << buffer;
}

//checks the entire board looking for a winner
int TTT::checkWinner(game* gi)
{
	//TODO: gameWinner logic
	return 0;
}

//basic void, prints game over and players name
void TTT::gameOver(int playerWon)
{
	//TODO: Game over logic
}

//main function that determins the players turn, and adds their mark to the board
void TTT::gameTurn(game* gi, int turn)
{
	TTT::player player;
	player = gi->playerTwo;

	if(turn % 2 == 0 )
	{
		if(player.human)
		{
			playerTurn(gi, player.name, 2);
		}
		else
		{
			computerTurn(gi);
		}
	}
	else
	{
		playerTurn(gi, player.name, 1);
	}

	cout << "Turn: " << turn;
}

//check the block number to see if its occupied
int TTT::boardCheck(game* gi, int block)
{
	int sBlock = 1;
	for(int x=0; x<3; x++)
	{
		for(int y=0; y<3; y++)
		{
			//tell us what we want printed to console
			if(block == sBlock)
			{
				return gi->board[x][y];
			}
			sBlock++;
		}
	}

	//returns if the block isnt found
	return 1;
}

//actually place the piece on the board
void TTT::placePiece(game* gi, int block, int piece)
{
	int sBlock = 1;
	for(int x=0; x<3; x++)
	{
		for(int y=0; y<3; y++)
		{
			//tell us what we want printed to console
			if(block == sBlock)
			{
				gi->board[x][y] = piece;
			}
			sBlock++;
		}
	}
}

//the function to make the computer pick a square to place their piece in
void TTT::computerTurn(game* gi)
{
	//TODO: AI logic
	//return 0;
}

//function that asks player his placement option
void TTT::playerTurn(game* gi, string name, int piece)
{
	while(true)
	{
		int option = 0;
		cout << endl << name << "'s turn" << endl;
		cout << "> " ;
		cin >> option;

		if(boardCheck(gi, option) != 0)
		{
			cout << "Invalid Move" << endl;
		}
		else
		{
			placePiece(gi,option, piece);
			break;
		}
	}
}

