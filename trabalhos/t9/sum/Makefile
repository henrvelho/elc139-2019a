FLAGS=-std=c++11 -openmp

RM=rm -f

EXEC=sum

all: $(EXEC)

$(EXEC):
	$(CXX) $(FLAGS) $(EXEC).cpp -o $(EXEC).o
# 	$(CXX) $(FLAGS) $(EXEC).o -o $(EXEC)

clean:
	$(RM) $(EXEC).o

run: $(EXEC)
	./$(EXEC).o