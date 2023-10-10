
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
		BettingTurn();

		//Flop
		DealCards(3, 0, newDeck);
		BettingTurn();

		//Turn
		DealCards(1, 0, newDeck);
		BettingTurn();

		//River
		DealCards(1, 0, newDeck);
		BettingTurn();



		//Showdown
		DisplayUI();
		ListHand(computerHand, "Computer hand");
		HandValue scorePlayer = Evaluate(playerHand, sharedHand);
		HandValue scoreComputer = Evaluate(computerHand, sharedHand);
		EndResult(scorePlayer, scoreComputer);

	} while (YesNoQuestion("Do you want to play again?"));
	exit(0);
}
