
all:
	gcc -g -Wall -lSDL -lSDL_gfx -lSDL_ttf -o dpad main.c sdl_display.c

clean:
	rm -f dpad *~

