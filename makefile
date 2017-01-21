OBJS = Map.o Player.o Tile.o GameMain.o
CFLAGS = -Wall -c -std=c++0x


Game: $(OBJS)
	g++ $(OBJS) -o Game -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
	
GameMain.o: GameMain.cpp Map.h Player.h
	g++ $(CFLAGS) GameMain.cpp -o GameMain.o
	
Map.o: Map.cpp Map.h
	g++ $(CFLAGS) Map.cpp -o Map.o

Tile.o: Tile.cpp Tile.h
	g++ $(CFLAGS) Tile.cpp -o Tile.o
	
Player.o: Player.cpp Map.h Tile.h Player.h
	g++ $(CFLAGS) Player.cpp -o Player.o
	
clean:
	\rm *.o Game
