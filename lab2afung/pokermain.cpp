/*
 * Name: Alan Fung
 * Email: afung@scu.edu
 */
#include <ctime>
#include <iomanip>
#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include "card.h"
#include "deck.h"
#include "poker.h"

using namespace std;
using namespace lab2afung;

// Generate one sample hand for each rank
void pokerHands(Poker &poker) {
	/*
	 * Loop until you have found one of each rank.
	 * Print that "sample hand"
	 */
    bool rank_found[Poker::POKER_ARRAY_SIZE] = {false};
    int found_count = 0;

    while (found_count < Poker::POKER_ARRAY_SIZE) {
        poker.dealHand();
        Poker::Rank current_rank = poker.rankHand();
        if (rank_found[current_rank] == false) {
            rank_found[current_rank] = true;
            cout << Poker::RankNames[current_rank] << ": " << poker << "\n";
            found_count++;
        }
    }
}

// Collect statistics for each rank of Poker
void pokerStats(Poker &poker) {
	time_t tmark = clock();			// ready, get set, go!
	/*
	 * Do your thing here.
	 * This is supposed to be big loop that deal many many poker hands and collect the
	 * statistics for each rank.
	 * Once you believe the statistics are good.  Exit the loop.
	 * "tmark" then computes the number of "clock ticks" in your loop.
	 * You should convert that to human friendly units, such as "seconds"
	 * 
	 * Output your stats then, with the amount of time it took you collect the stats.
	 */
    const int NUM_HANDS = 1e7;
    int rank_counts[Poker::POKER_ARRAY_SIZE] = {0};

    for (int i = 0; i < NUM_HANDS; ++i) {
        poker.dealHand();
        ++rank_counts[poker.rankHand()];
    }
    double mean = 0.0;
    for (int i = 0; i < Poker::POKER_ARRAY_SIZE; ++i) {
        cout << Poker::RankNames[i] << ": " << fixed << setprecision(3) << rank_counts[i]*1e2/NUM_HANDS << "%\n";
        mean += rank_counts[i] * i;
    }
    mean /= NUM_HANDS;

    cout << "\nMean Rank: " << Poker::RankNames[(int)(mean+0.5)] << "\n";
    
	tmark = clock() - tmark;	// stop the clock
    cout << "Time elapsed: " << (double)tmark/CLOCKS_PER_SEC * 1e3 << "ms\n";
    cout << "Cards dealt: " << NUM_HANDS << "\n";
    return;
}

int main(void) {
	Poker poker;
	cout << "Sample hand for each Rank:" << endl;
	pokerHands(poker);
	cout << endl << "Statistics:" << endl;
	pokerStats(poker);

	return EXIT_SUCCESS;
}
