# Name: Alan Fung
# Email: afung@scu.edu


STD=-std=c++20
OPT=-g
# redefine this to wherever lab3 is
INC=
CXXFLAGS=${STD} ${OPT} ${INC}
CFLAGS=${OPT}

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $<

ROSTERSRCS=rosterptr.cpp rosterptrmain.cpp rostertest.cpp
ROSTEROBJS=$(ROSTERSRCS:.cpp=.o) roster.o
ALL=rosterptrtest

all: $(ALL)

rosterptrtest:	$(ROSTEROBJS)
	$(CXX) -o $@ $(CXXFLAGS) $+

clean:
	/bin/rm -f $(ROSTEROBJS) $(ALL)
	/bin/rm -rf $(ALL:=.dSYM)


depend: $(ROSTERSRCS)
	TMP=`mktemp -p .`; export TMP; \
	sed -e '/^# DEPENDENTS/,$$d' Makefile > $$TMP; \
	echo '# DEPENDENTS' >> $$TMP; \
	$(CXX) -MM $(INC) $+ >> $$TMP; \
	/bin/mv -f $$TMP Makefile

# DEPENDENTS
rosterptr.o: rosterptr.cpp person.h roster.h rosterptr.h
rosterptrmain.o: rosterptrmain.cpp person.h roster.h rosterptr.h
rostertest.o: rostertest.cpp person.h roster.h rosterptr.h
