
CC=g++
SRC=$(wildcard src/*.cpp)
OBJ_FOLDER=.object
OBJ=$(subst src/,$(OBJ_FOLDER)/src/,$(SRC:.cpp=.o))
EXEC=labyrinthe

ifeq ($(V),1)
	ECHO=
else
	ECHO=@
endif

all : $(OBJ_FOLDER)/src $(EXEC)
	
$(EXEC) : $(SRC:.cpp=.o)
	$(ECHO)$(CC) -o bin/$(EXEC) $(OBJ) -lsfml-graphics -lsfml-window -lsfml-system
	@echo ".. bin/$(EXEC) done."

%.o :  %.cpp
	$(ECHO)$(CC) -Iinclude -o $(OBJ_FOLDER)/$@ -c $<
	
$(OBJ_FOLDER)/src :
	$(ECHO)mkdir -p $(OBJ_FOLDER)/src
	
clean :
	$(ECHO)rm -rf $(OBJ_FOLDER)
	$(ECHO)rm -f bin/$(EXEC)
	@echo "..clean done."
