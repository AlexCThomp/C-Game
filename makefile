OBJS = Map.o Player.o GameMain.o
CFLAGS = -c -std=c++0x


Game: $(OBJS)
	g++ $(OBJS) -o Game -lsfml-graphics -lsfml-window -lsfml-system
	
GameMain.o: GameMain.cpp Map.h Player.h
	g++ $(CFLAGS) GameMain.cpp -o GameMain.o
	
Map.o: Map.cpp Map.h
	g++ $(CFLAGS) Map.cpp -o Map.o
	
Player.o: Player.cpp Map.h Player.h
	g++ $(CFLAGS) Player.cpp -o Player.o
	
clean:
	\rm *.o Game
