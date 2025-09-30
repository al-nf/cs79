#
# CSEN 79 Lab: Poker Statistics
#

# This is a Gnu compatible Makefile.  You can read the documentation online by searching Gnu Make
# All coding projects must include a similar Makefile, named "Makefile".  See submission guidelines
#
# Name: Alan Fung
# Email: afung@scu.edu
#

STD=-std=c++20
OPT=-g
CXXFLAGS=${STD} ${OPT}
CFLAGS=${OPT}

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $<

%: %.cpp
	$(CXX) -o $@ $(CXXFLAGS) $<

DECKSRCS=deckmain.cpp deck.cpp shuffle.cpp card.cpp
DECKOBJS=$(DECKSRCS:.cpp=.o)
CARDSRCS=card.cpp cardmain.cpp
CARDOBJS=$(CARDSRCS:.cpp=.o)
POKERSRCS=poker.cpp pokermain.cpp deck.cpp shuffle.cpp card.cpp
POKEROBJS=$(POKERSRCS:.cpp=.o)
ALL=decktest cardtest pokertest

all: $(ALL)

decktest:	$(DECKOBJS)
	$(CXX) -o $@ $(CXXFLAGS) $+

cardtest:	$(CARDOBJS)
	$(CXX) -o $@ $(CXXFLAGS) $+

pokertest:	$(POKEROBJS)
	$(CXX) -o $@ $(CXXFLAGS) $+

clean:
	/bin/rm -f $(DECKOBJS) $(CARDOBJS) $(POKEROBJS) $(ALL)
	/bin/rm -f poker.tar
	/bin/rm -rf $(ALL:=.dSYM)

depend:
	TMP=`mktemp -p .`; export TMP; \
	sed -e '/^# DEPENDENTS/,$$d' Makefile > $$TMP; \
	echo '# DEPENDENTS' >> $$TMP; \
	$(CXX) -MM  $(DECKSRCS) $(CARDSRCS) $(POKERSRCS) >> $$TMP; \
	/bin/mv -f $$TMP Makefile

tar:
	tar cf poker.tar Makefile *.cpp *.h

# DEPENDENTS
deckmain.o: deckmain.cpp card.h deck.h
deck.o: deck.cpp card.h deck.h
shuffle.o: shuffle.cpp card.h deck.h
card.o: card.cpp card.h
card.o: card.cpp card.h
cardmain.o: cardmain.cpp card.h
poker.o: poker.cpp card.h deck.h poker.h
pokermain.o: pokermain.cpp card.h deck.h poker.h
deck.o: deck.cpp card.h deck.h
shuffle.o: shuffle.cpp card.h deck.h
card.o: card.cpp card.h
