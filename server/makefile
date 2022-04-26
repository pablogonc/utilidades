create-dirs:
	mkdir -p build/src/

all: usador

usador: inicio
	gcc  -o "build/usador"  ./build/src/inicio.o   -lsaludador

inicio: create-dirs
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"build/src/inicio.d" -MT"build/src/inicio.o" -o "build/src/inicio.o" "src/inicio.c"
