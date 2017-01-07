OBJS = Map.o GameMain.o
CFLAGS = -c -std=c++0x


Game: $(OBJS)
	g++ $(OBJS) -o Game -lsfml-graphics -lsfml-window -lsfml-system
	
Map.o: Map.cpp Map.h
	g++ $(CFLAGS) Map.cpp -o Map.o
	
GameMain.o: GameMain.cpp Map.h
	g++ $(CFLAGS) GameMain.cpp -o GameMain.o
	
clean:
	\rm *.o Game
