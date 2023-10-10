#include "Decks.h"

#include <algorithm>
#include <iostream>
#include <random>
#include <stack>


std::stack<Card> deck;
std::vector<Card> playerHand;
std::vector<Card> computerHand;
std::vector<Card> sharedHand;

//cant shuffle stacks so we need to dump the cards in a vector, shuffle and then put them back in the stack.
std::stack<Card> CreateRandomDeck()
{

	std::stack<Card> fullDeck;
	std::vector<Card> tempDeck;

	for (int i = Suit::Clubs; i <= Suit::Spades; i++) // Suit
	{
		for (int j = Rank::Two; j <= Rank::Ace; j++) // Rank
		{
			tempDeck.push_back(Card{ static_cast<Suit>(i),static_cast<Rank>(j) });
		}
	}
	std::shuffle(tempDeck.begin(), tempDeck.end(), std::default_random_engine(time(NULL)));
	for (const auto& a : tempDeck)
	{
		fullDeck.emplace(a);
	}
	return fullDeck;
}


void DealOneCard(std::stack<Card>& fromDeck, std::vector<Card>& toHand)
{
	toHand.emplace_back(fromDeck.top());
	fromDeck.pop();
}

void DealCards(const int nbToShared, const int nbToPlayers, std::stack<Card>& deckToDeal)
{
	//loop to put x cards in the shared hand
	for (int i = 0; i < nbToShared; i++)
	{
		std::cout << "Dealt " << deckToDeal.top().CardName() << " to the shared hand." << std::endl << std::endl;
		DealOneCard(deckToDeal, sharedHand);
	}
	//loop to put x cards in the player & cpu hands
	for (int i = 0; i < nbToPlayers * 2; i++)
	{
		if (i % 2 == 0)
		{
			std::cout << "Dealt " << deckToDeal.top().CardName() << " to the player." << std::endl << std::endl;
			DealOneCard(deckToDeal, playerHand);
		}
		else
		{
			std::cout << "Dealt a card to the computer." << std::endl << std::endl;
			DealOneCard(deckToDeal, computerHand);
		}
	}
	system("pause");
}


void SortByValue(std::vector<Card>& hand)
{
	std::sort(hand.begin(), hand.end(), [](const Card& a, const Card& b)
		{
			return a.TotalValue < b.TotalValue;
		});
}

void SortByRank(std::vector<Card>& hand)
{
	std::sort(hand.begin(), hand.end(), [](const Card& a, const Card& b)
		{
			return a.Rank < b.Rank;
		});
}

//lists all cards in the specified hand
void ListHand(std::vector<Card> hand, const std::string& handName)
{
	std::cout << handName << ": ";
	for (int i = 0; i < hand.size(); i++)
	{
		std::cout << hand[i].CardName();
		if (i < hand.size() - 1)
		{
			std::cout << "  /  ";
		}
	}
	std::cout << std::endl;
}

//lists all cards in the specified deck
void ListDeck(std::stack<Card> deck, const std::string& deckName)
{
	int size = deck.size();
	std::stack<Card> tempDeck = deck;
	for (int i = 0; i < tempDeck.size(); i)
	{
		std::cout << deckName << ": " << tempDeck.top().CardName() << " #" << tempDeck.size() - size + 1 << std::endl;
		size -= 2;
		tempDeck.pop();
	}
	std::cout << std::endl;
}
