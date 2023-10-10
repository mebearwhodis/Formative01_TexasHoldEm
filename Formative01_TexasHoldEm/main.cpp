
#include <random>

#include "Decks.h"
#include "Betting.h"
#include "Global.h"
#include "HandValues.h"

int main()
{
	do {
		ResetGame();
		std::stack<Card> newDeck(CreateRandomDeck());

		//Pre-Flop
		DealCards(0, 2, newDeck);
		if (!BettingTurn()) { break; }

		//Flop
		DealCards(3, 0, newDeck);
		if (!BettingTurn()) { break; }

		//Turn
		DealCards(1, 0, newDeck);
		if (!BettingTurn()) { break; }

		//River
		DealCards(1, 0, newDeck);
		if (!BettingTurn()) { break; }



		//Showdown
		DisplayUI();
		ListHand(computerHand, "Computer");
		scorePlayer = Evaluate(playerHand, sharedHand);
		scoreComputer = Evaluate(computerHand, sharedHand);
		EndResult(scorePlayer, scoreComputer);


	} while (YesNoQuestion("Do you want to play again?"));
}
