/*
 * Name: Your Name
 * Email: Your email
 */
#include <iostream>
#include <stdlib.h>
#include <utility>
#include "card.h"
#include "deck.h"

namespace csen79 {
	// implement Fisher-Yates here
	void Deck::shuffle(void) {
        Deck::next = 0;
        for (int i = Deck::CARDS_PER_DECK-1; i >= 1; --i) {
            int j = std::rand()%(Deck::CARDS_PER_DECK-i) + i;
            std::swap(Deck::cards[i], Deck::cards[j]);
        }
    }

	// deal out one card
	const Card &Deck::deal() {
        if (Deck::next >= Deck::CARDS_PER_DECK - Deck::guard) {
            Deck::shuffle();
        }
		return cards[Deck::next++];
	}
}

