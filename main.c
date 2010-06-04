#include "sdl_display.h"
#include <stdio.h>
#include <assert.h>

extern struct sdl_ctx sdl;

void loop() {
	int x=-1, y=-1, last_x=-1, last_y=-1;
	int active = 0;
	
	while(1) {
		SDL_Event evt;
		SDL_MouseButtonEvent *btn;
		SDL_MouseMotionEvent *mot;
		
		if(SDL_WaitEvent(&evt) != 1)
			continue;
		
		switch(evt.type) {
			
			case SDL_MOUSEMOTION:
				mot = &evt.motion;
							
				x = mot->x;
				y = mot->y;
			
				if((active) && ((last_x != x) || (last_y != y))) {
					// draw
					aalineColor(sdl.screen, last_x, last_y, x, y, 0x000000ff);
					SDL_Flip(sdl.screen);
				}
			
				break;
			
			case SDL_MOUSEBUTTONUP:
				active = 0;
				break;
			
			case SDL_MOUSEBUTTONDOWN:
				btn = &evt.button;
				
				x = btn->x;
				y = btn->y;
				active = 1;
				break;

			case SDL_QUIT:
				return;

			default:
				break;
		}
		
		last_x = x;
		last_y = y;
		
	}
}

#define LINES	30

int main(int argc, char **argv)
{
	int i;
	
	sdl_init(1024, 600);
	
	SDL_FillRect(sdl.screen, NULL, 0xffffffff);
	
	for(i=LINES; i<sdl.h; i+=LINES)
		hlineColor(sdl.screen, 0, sdl.w-1, i, 0x33333333);
	
	SDL_Flip(sdl.screen);
	
	loop();
	
	return 0;
}
