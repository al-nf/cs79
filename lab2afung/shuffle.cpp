/*
 * Name: Alan Fung
 * Email: afung@scu.edu
 */
#include <iostream>
#include <stdlib.h>
#include <utility>
#include "card.h"
#include "deck.h"

namespace lab2afung {
	// implement Fisher-Yates here
	void Deck::shuffle(void) {
        next = 0;
        for (int i = Deck::CARDS_PER_DECK-1; i >= 1; --i) {
            int j = std::rand()%(Deck::CARDS_PER_DECK-i) + i;
            std::swap(cards[i], cards[j]);
        }
    }

	// deal out one card
	const Card &Deck::deal() {
        if (next >= Deck::CARDS_PER_DECK - guard) {
            shuffle();
        }
		return cards[Deck::next++];
	}
}

