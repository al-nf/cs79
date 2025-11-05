# Sin-Yaw Wang <swang24@scu.edu>
TMPMAKE=tmpMake
CXX=c++
OPT=-g
STD=-std=c++20
CXXFLAGS=$(OPT) $(STD)

%.o:	%.cpp
	$(CXX) -c $(CXXFLAGS) $<

SRCS=main.cpp record.cpp recordops.cpp
OBJS=$(SRCS:.cpp=.o)
ALL=stl stldemo

all: $(ALL)

stl:	$(OBJS)
	$(CXX) -o $@ $(CXXFLAGS) $+

stldemo:	stldemo.cpp
	$(CXX) -o $@ $(CXXFLAGS) $+

clean:
	/bin/rm -f $(ALL) $(OBJS)
	/bin/rm -rf $(ALL:=.dSYM)

depend: $(SRCS) stldemo.cpp
	TMP=`mktemp -p .`; export TMP; \
	sed -e '/^# DEPENDENTS/,$$d' Makefile > $$TMP; \
	echo '# DEPENDENTS' >> $$TMP; \
	$(CXX) -MM $+ >> $$TMP; \
	/bin/mv -f $$TMP Makefile

# DEPENDENTS
main.o: main.cpp record.h
record.o: record.cpp record.h
recordops.o: recordops.cpp record.h
stldemo.o: stldemo.cpp
