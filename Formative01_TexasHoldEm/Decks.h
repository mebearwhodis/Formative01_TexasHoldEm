#pragma once
#include <stack>
#include <string>
#include <vector>

#include "Cards.h"

extern std::stack<Card> deck;
extern std::vector<Card> playerHand;
extern std::vector<Card> computerHand;
extern std::vector<Card> sharedHand;

std::stack<Card> CreateRandomDeck();

void DealOneCard(std::stack<Card>& fromDeck, std::vector<Card>& toHand);
void DealCards(int nbToShared, int nbToPlayers, std::stack<Card>& deckToDeal);

void ListHand(std::vector<Card> hand, const std::string& handName);
void ListDeck(std::stack<Card> deck, const std::string& deckName);