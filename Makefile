# set comiler
CC = g++

# include files
INCLUDE = -I ./include -L ./include/SDL2/lib

# Compilers flags for compiling object file
CFLAGSO = -std=c++17 -Wall -m64 -O3 -c ${INCLUDE}

# libraries
LIBS = -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

# compilers flags for compiling binary code
CFLAGSB = -s ${LIBS}

default: objCompile
	mkdir -p ./make/bin
	${CC} ./make/build/*.o -o ./make/bin/main ${CFLAGSB} ${INCLUDE}
	cp -r ./res ./make/bin

objCompile:
	mkdir -p ./make/build
	${CC} ./src/*.cpp ${CFLAGSO} ${LIBS}
	# laymans way to move object files to make/build folder
	mv *.o ./make/build

windows: winObjCompile
	mkdir -p ./make/bin
	${CC} ./make/build/*.o -o ./make/bin/main ${CFLAGSB} ${INCLUDE} -mwindows
	cp -r ./res ./make/bin

winObjCompile:
	mkdir -p ./make/build
	${CC} ./src/*.cpp ${CFLAGSO} ${LIBS} -mwindows
	# laymans way to move object files to make/build folder
	mv *.o ./make/build

debug: objCompile
	start ./make/bin/main.exe

run:
	start ./make/bin/main.exe