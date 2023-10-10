#pragma once
#include <array>
#include <string>

enum Suit
{
	Clubs,
	Diamonds,
	Hearts,
	Spades
};
enum Rank
{
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King,
	Ace
};

extern std::array<std::string, 4> suitName;
extern std::array<std::string, 13> rankName;

//Suit and Rank are self-explanatory, BaseValue and TotalValue are used to check for Straight hands
struct Card
{
	Suit Suit;
	Rank Rank;
	int BaseValue = Rank;
	int TotalValue = 20 * Suit + Rank;
	std::string CardName()
	{
		return rankName[Rank] + " of " + suitName[Suit];
	}
};
