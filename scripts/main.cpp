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
	Model main_scene;
	ReadToModel("models/shotgun.jsfm",shotgun);
	ReadToModel("models/mains.jsfm",main_scene);
	
	int width, height;

	SDL_GetWindowSize(win,&width,&height);
	float dx = 0;

	float player_x = 0;
	float player_y = 0;
	float player_z = 1;
	while (run)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type==SDL_QUIT)
			{
				run=false;
			}
			if (event.key.keysym.scancode == 7) { player_x -=15; }
			if (event.key.keysym.scancode == 4) { player_x += 15; }
			if (event.key.keysym.scancode == 26) { player_z -= 0.05; }
			if (event.key.keysym.scancode == 22) { player_z += 0.05; }
			if (event.key.keysym.scancode==80){dx--;player_x+=7;}
			if (event.key.keysym.scancode==79){dx++;player_x-=7;}
		}

		SDL_SetRenderDrawColor(ren,200,200,200,255);
		SDL_RenderClear(ren);
		
		render3(win,ren,shotgun,{0,0,0},0x01,0,width/100*5,-height/100*15,-0.1);
		render3(win,ren,shotgun,{0,0,0},0x01,dx,player_x,player_y,player_z+4);
		render3(win, ren, main_scene,{ 0,0,0 },0x01,0,player_x,player_y-30,player_z);
	
		SDL_RenderPresent(ren);
		SDL_Delay(20);
	}
	SDL_DestroyWindow(win);
	SDL_Quit();

	return 0;
}
