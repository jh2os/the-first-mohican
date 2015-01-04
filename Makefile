#OBJS specifies which files to compile as part of the project
OBJS = src/main.cpp src/App* src/engine/*

#CC specifies which compiler we're using
CC = g++ -std=c++11 -Wall -Werror

#COMPILER_FLAGS specifies the additional Comilation options we're using
# -w suppressess all warnings
COMPILER_FLAGS = -DLINUX

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer 

#OBJ_NAME specifies the name of our executable
OBJ_NAME = platformtest

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
