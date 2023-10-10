
#include "Betting.h"

#include <iostream>
#include <string>
#include "Global.h"

int minimumBet = 50;
int playerBank = 500;
int computerBank = 500;
int moneyPot = 0;


void BettingTurn()
{
	DisplayUI();
	bool wantsToBet = true;
	do
	{
		if (YesNoQuestion("Would you like to bet (Y) or to fold (N)?"))
		{
			std::string bet;
			std::cout << "Please pick an amount to bet from " << minimumBet << " to " << std::min(playerBank, computerBank) << "." << std::endl;
			std::cin >> bet;
			while (!ValidNumber(bet, minimumBet, std::min(playerBank, computerBank)))
			{
				std::cout << "This is not a valid bet." << std::endl;
				std::cout << "Please pick an amount to bet from " << minimumBet << " to " << std::min(playerBank, computerBank) << "." << std::endl;
				std::cin >> bet;
			}
			playerBank -= std::stoi(bet);
			computerBank -= std::stoi(bet);
			moneyPot += std::stoi(bet) * 2;

			std::cout << std::endl;
			wantsToBet = false;
		}
		else
		{
			if (YesNoQuestion("Choosing to fold now will make the CPU automatically win, are you sure you want to do that?"))
			{
				std::cout << "You lost" << std::endl;
				//end the game function
				wantsToBet = false;
			}
			else
			{
				wantsToBet = true;
			}
		}
	} while (wantsToBet);
}


