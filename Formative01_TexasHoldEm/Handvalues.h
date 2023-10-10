#pragma once

#include <map>

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

extern std::array<std::string, 9> valueName;

extern HandValue scorePlayer;
extern HandValue scoreComputer;

std::vector<Card> FuseHands(const std::vector<Card>& hand1, const std::vector<Card>& hand2);
std::map<Rank, int> RankOccurences(const std::vector<Card>& fullHand);
std::map<Suit, int> SuitOccurences(const std::vector<Card>& fullHand);

void SortByValue(std::vector<Card>& hand);
void SortByRank(std::vector<Card>& hand);

bool HasStraightFlush(const std::vector<Card>& fullHand);
bool HasFourOfAKind(const std::vector<Card>& fullHand);
bool HasFullHouse(const std::vector<Card>& fullHand);
bool HasFlush(const std::vector<Card>& fullHand);
bool HasStraight(const std::vector<Card>& fullHand);
bool HasThreeOfAKind(const std::vector<Card>& fullHand);
bool HasTwoPairs(const std::vector<Card>& fullHand);
bool HasPair(const std::vector<Card>& fullHand);

HandValue Evaluate(const std::vector<Card>& hand1, const std::vector<Card>& hand2);
extern void EndResult(const HandValue scorePlayer, const HandValue scoreComputer);