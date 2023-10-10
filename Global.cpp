
#include <iostream>
#include <string>

#include "Betting.h"
#include "Decks.h"

bool restart;

bool ValidNumber(const std::string& inputString, const int min, const int max)
{
	bool isInputValid = true;
	do
	{
		isInputValid = true;
		for (int i = 0; i < inputString.size(); i++)
		{
			if (!isdigit(inputString[i]))
			{
				return false;
			}
			if (isInputValid && i == inputString.size() - 1)
			{
				if (std::stoi(inputString) > max || std::stoi(inputString) < min)
				{
					return false;
				}
				return true;
			}
		}
	} while (!isInputValid);
	return false;
}

bool YesNoQuestion(const std::string& question)
{
	bool restartLoop = true;
	do
	{
		restartLoop = true;
		char answer;

		std::cout << question << " Y/N" << std::endl;
		std::cin >> answer;

		switch (tolower(answer)) {
		case 'y':
			return true;
		case 'n':
			return false;
		default:
			std::cout << std::endl << "Please enter a valid answer: Y/N" << std::endl << std::endl;
			restartLoop = false;
		}
	} while (!restartLoop);
	return false;
}

void ResetGame()
{
	moneyPot = 0;

	while (!deck.empty()) { deck.pop(); }
	playerHand.clear();
	computerHand.clear();
	sharedHand.clear();
	system("cls");
}

void DisplayUI()
{
	system("cls");
	std::cout << "Your bank: " << playerBank << "\t" << "CPU's bank: " << computerBank << "\t" << "Money pot: " << moneyPot << std::endl << std::endl;
	ListHand(sharedHand, "Shared hand");
	ListHand(playerHand, "Your hand");
}
