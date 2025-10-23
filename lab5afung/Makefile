CC = g++
DEMO = demo
TEST = test

all: clean $(DEMO) $(TEST)

$(DEMO): 
	$(CC) mystring.cpp str_demo.cpp -o $(DEMO)

$(TEST):
	$(CC) mystring.cpp test_string.cpp -o $(TEST)

clean:
	rm -f $(DEMO) $(TEST)
