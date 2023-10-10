#include "HandValues.h"

#include <algorithm>
#include <iostream>
#include <map>

#include "Betting.h"

std::array<std::string, 9> valueName
{
	"High Card",
	"Pair",
	"Two Pairs",
	"Three Of A Kind",
	"Straight",
	"Flush",
	"Full House",
	"Four Of A Kind",
	"Straight Flush"
};

HandValue scorePlayer;
HandValue scoreComputer;

std::vector<Card> FuseHands(const std::vector<Card>& hand1, const std::vector<Card>& hand2)
{
	std::vector<Card> fullHand;
	for (int i = 0; i < hand1.size(); i++)
	{
		fullHand.push_back(hand1[i]);
	}
	for (int i = 0; i < hand2.size(); i++)
	{
		fullHand.push_back(hand2[i]);
	}
	SortByValue(fullHand);
	return fullHand;
}

std::map<Rank, int> RankOccurences(const std::vector<Card>& fullHand)
{
	std::map<Rank, int> rankOccurences;
	for (auto c : fullHand)
	{
		if (rankOccurences.find(c.Rank) == rankOccurences.end())
		{
			rankOccurences[c.Rank] = 1;
		}
		else
		{
			rankOccurences[c.Rank]++;
		}
	}

	return rankOccurences;
}

std::map<Suit, int> SuitOccurences(const std::vector<Card>& fullHand)
{
	std::map<Suit, int> suitOccurences;
	for (auto c : fullHand)
	{
		if (suitOccurences.find(c.Suit) == suitOccurences.end())
		{
			suitOccurences[c.Suit] = 1;
		}
		else
		{
			suitOccurences[c.Suit]++;
		}
	}

	return suitOccurences;
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

//The following functions are checks used in the Evaluate function
bool HasStraightFlush(const std::vector<Card>& fullHand)
{
	{
		std::vector<Card> tempHand = fullHand;
		int sequenceFlag = 0;
		SortByValue(tempHand);
		for (int c = 0; c < tempHand.size() - 1; c++)
		{
			if ((tempHand[c].TotalValue + 1 == tempHand[c + 1].TotalValue) && (tempHand[c].Rank + 1 == tempHand[c + 1].Rank))
			{
				sequenceFlag++;
			}
			else
			{
				sequenceFlag = 0;
			}
		} if (sequenceFlag >= 5)
		{
			return true;
		}
		return false;
	}
}

bool HasFourOfAKind(const std::vector<Card>& fullHand)
{
	const std::map<Rank, int> mappedHand = RankOccurences(fullHand);

	for (const auto p : mappedHand)
	{
		if (p.second == 4)
		{
			return true;
		}
	} return false;
}

bool HasFullHouse(const std::vector<Card>& fullHand)
{
	const std::map<Rank, int> mappedHand = RankOccurences(fullHand);

	for (const auto p : mappedHand)
	{
		if (p.second == 3)
		{
			for (const auto t : mappedHand)
			{
				if (t.second == 2)
				{
					return true;
				}
			} return false;
		}
	} return false;
}

bool HasFlush(const std::vector<Card>& fullHand)
{
	const std::map<Suit, int> mappedHand = SuitOccurences(fullHand);

	for (const auto p : mappedHand)
	{
		if (p.second >= 5)
		{
			return true;
		}
	} return false;
}

bool HasStraight(const std::vector<Card>& fullHand)
{
	std::vector<Card> tempHand = fullHand;
	int sequenceFlag = 0;
	SortByRank(tempHand);
	for (int c = 0; c < tempHand.size() - 1; c++)
	{
		if (tempHand[c].TotalValue + 1 == tempHand[c + 1].TotalValue)
		{
			sequenceFlag++;
		}
		else if (tempHand[c].Rank == tempHand[c + 1].Rank)
		{
			continue;
		}
	} if (sequenceFlag >= 5)
	{
		return true;
	}
	return false;
}

bool HasThreeOfAKind(const std::vector<Card>& fullHand)
{
	const std::map<Rank, int> mappedHand = RankOccurences(fullHand);

	for (const auto p : mappedHand)
	{
		if (p.second == 3)
		{
			return true;
		}
	} return false;
}

bool HasTwoPairs(const std::vector<Card>& fullHand) //fonctionne pas
{
	const std::map<Rank, int> mappedHand = RankOccurences(fullHand);
	bool twoPairsFlag = false;

	for (const auto p : mappedHand)
	{
		if (p.second == 2)
		{
			if (!twoPairsFlag)
			{
				twoPairsFlag = true;
			}
			return true;
		}
	} return false;
}

bool HasPair(const std::vector<Card>& fullHand)
{
	const std::map<Rank, int> mappedHand = RankOccurences(fullHand);

	for (const auto p : mappedHand)
	{
		if (p.second == 2)
		{
			return true;
		}
	} return false;
}

//Determines what the value of a hand is
HandValue Evaluate(const std::vector<Card>& hand1, const std::vector<Card>& hand2)
{
	const std::vector<Card> finalHand = FuseHands(hand1, hand2);
	if (HasStraightFlush(finalHand))
	{
		return StraightFlush;
	}
	else if (HasFourOfAKind(finalHand))
	{
		return FourOfAKind;
	}
	else if (HasFullHouse(finalHand))
	{
		return FullHouse;
	}
	else if (HasFlush(finalHand))
	{
		return Flush;
	}
	else if (HasStraight(finalHand))
	{
		return Straight;
	}
	else if (HasThreeOfAKind(finalHand))
	{
		return ThreeOfAKind;
	}
	else if (HasTwoPairs(finalHand))
	{
		return TwoPairs;
	}
	else if (HasPair(finalHand))
	{
		return Pair;
	}
	else
	{
		return HighCard;
	}
}

//Depending on the values, determines the winner
void EndResult(const HandValue scorePlayer, const HandValue scoreComputer)
{
	if (scoreComputer > scorePlayer)
	{
		std::cout << "The CPU wins with a " << valueName[scoreComputer] << "!" << std::endl;
		computerBank += moneyPot;
	}
	else if (scoreComputer < scorePlayer)
	{
		std::cout << "You win with a " << valueName[scorePlayer] << "!" << std::endl;
		playerBank += moneyPot;
	}
	else if (scoreComputer == 0 && scorePlayer == 0)
	{
		int playerHighest = 0;
		for (auto c : playerHand)
		{
			playerHighest = std::max(playerHighest, (c).BaseValue);
		}

		int computerHighest = 0;
		for (auto c : computerHand)
		{
			computerHighest = std::max(computerHighest, (c).BaseValue);
		}
		if (computerHighest > playerHighest)
		{
			std::cout << "Your highest card is lower than the computer's, the computer wins!" << std::endl;
			computerBank += moneyPot;
		}
		else if (computerHighest < playerHighest)
		{
			std::cout << "Your highest card is higher than the computer's, you win!" << std::endl;
			playerBank += moneyPot;
		}
	}
	else
	{
		std::cout << "You got the same hand value, it's a draw!" << std::endl;
		computerBank += moneyPot / 2;
		playerBank += moneyPot / 2;
	}
}