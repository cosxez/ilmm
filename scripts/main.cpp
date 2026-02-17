#include <iostream>
#include <vector>
#include <fstream>
#include <SDL2/SDL.h>
#include "geometry.h"
#include "render_models.h"
#include "parser.h"
#include "font.h"
#include "UI.h"

using namespace std;

int main(int args,char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO);
	
	SDL_Window* win=SDL_CreateWindow("ILMM",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1024,940,SDL_WINDOW_SHOWN);

	SDL_Renderer* ren=SDL_CreateRenderer(win,-1,0);

	char run=true;
	SDL_Event event;

	Model shotgun;
	ReadToModel("models/shotgun.jsfm",shotgun);

	int dx = 0;
	while (run)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type==SDL_QUIT)
			{
				run=false;
			}
		}

		SDL_SetRenderDrawColor(ren,0,0,0,255);
		SDL_RenderClear(ren);
		
		render3(win,ren,shotgun,{200,200,200},0x01,dx,0,0,1);
		dx++;

		SDL_RenderPresent(ren);
		SDL_Delay(20);
	}
	SDL_DestroyWindow(win);
	SDL_Quit();

	return 0;
}
