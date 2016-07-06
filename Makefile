C_FILES		=  $(wildcard *.c)
CPP_FILES	=  $(wildcard *.cpp)

C_BIN	= ${C_FILES:.c=_c}
CPP_BIN = ${CPP_FILES:.cpp=_cpp}

all: $(C_BIN) $(CPP_BIN)

$(C_BIN): create_bin_dir
	gcc -o bin/$@ ${@:_c=.c}

$(CPP_BIN): create_bin_dir
	g++ -std=c++11 -o bin/$@ ${@:_cpp=.cpp}

create_bin_dir:
	mkdir -p bin
