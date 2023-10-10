#pragma once

#include "Cards.h"
#include "Decks.h"

enum HandValue
{
	HighCard, 
	Pair, 
	TwoPairs, 
	ThreeOfAKind, 
	Straight, 
	Flush,
	FullHouse, 
	FourOfAKind,
	StraightFlush
};

HandValue Evaluate(const std::vector<Card>& hand1, const std::vector<Card>& hand2);
void EndResult(HandValue scorePlayer, HandValue scoreComputer);