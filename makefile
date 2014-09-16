
CXX=g++
CFLAGS=-Wall -Wextra -pedantic -Wno-long-long
LDFLAGS=-lsfml-system -lsfml-window -lsfml-graphics
EXEC=Main

SRC=$(wildcard Source/*.cpp Source/Decor/*.cpp Source/Map/*.cpp Source/Personnage/*.cpp Source/Personnage/Decorateur/*.cpp Source/Personnage/GestionAnimation/*.cpp Source/Batiment/*.cpp Source/Batiment/Interieur/*.cpp Source/Statique/*.cpp Source/Objet/*.cpp Source/Interface/*.cpp Source/Propriete/*.cpp Source/Observer/*.cpp Source/Menu/*)
OBJ=$(SRC:.cpp=.o)

all:$(EXEC)

Main:$(OBJ)
	$(CXX) -std=c++0x -o Kurt_The_Last_Key $^ $(LDFLAGS)

%.o: %.cpp
	@$(CXX) -std=c++0x -o $@ -c $< $(CFLAGS)
	
.PHONY: clean mrproper

clean:
	rm -rf Source/*.o Source/Decor/*.o Source/Map/*.o Source/Personnage/*.o Source/Personnage/Decorateur/*.o Source/Personnage/GestionAnimation/*.o Source/Batiment/*.o Source/Batiment/Interieur/*.o Source/Statique/*.o Source/Objet/*.o Source/Interface/*.o Source/Propriete/*.o Source/Observer/*.o Source/Menu/*.o

mrproper: clean
	@rm -rf $(EXEC)
