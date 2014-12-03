#OBJS specifies which files to compile as part of the project
OBJS = main.cpp eflat/eflat.h eflat/eflat.cpp

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional Comilation options we're using
# -w suppressess all warnings
COMILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2

#OBJ_NAME specifies the name of our executable
OBJ_NAME = ../platformtest

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
