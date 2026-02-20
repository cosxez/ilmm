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
	Model barn;
	Model stack;
	Model fence;
	ReadToModel("models/shotgun.jsfm",shotgun);
	ReadToModel("models/barn.jsfm",barn);
	ReadToModel("models/stack.jsfm",stack);
	ReadToModel("models/fence.jsfm",fence);

	int width, height;

	SDL_GetWindowSize(win,&width,&height);
	float dx = 0;

	float player_x = 0;
	float player_y = 0;
	float player_z = 1;

	bool is_an = false;
	bool down = false;
	bool up = false;

	int mx,my;
	SDL_GetMouseState(&mx, &my);
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
			if (event.key.keysym.scancode==80){dx-=1;player_x+=5;}
			if (event.key.keysym.scancode==79){dx+=1;player_x-=5;}
			if (event.button.button == SDL_BUTTON_LEFT) { is_an = true; down = true; }
			
			int nmx, nmy;
			SDL_GetMouseState(&nmx, &nmy);
			if (nmx < mx) { dx -= 2; player_x += 10; }
			if (nmx > mx) { dx += 2; player_x -= 10; }
			mx = nmx;
		}

		SDL_SetRenderDrawColor(ren,0,0,0,255);
		SDL_RenderClear(ren);
		if (is_an == true)
		{
			static short an_c = 90;
			static float an_z = 0;
			render3(win, ren, shotgun, { 200, 200,200 }, 0x02, an_c, width / 100 * 5, -height / 100 * 15, -0.1+an_z);
			if (down == true) { an_c -= 30; an_z -= 0.4; }
			if (up == true) { an_c += 30; an_z += 0.4; }
			if (an_c >= 90) { up = false; is_an = false; an_c = 90; }
			if (an_c <= 60)
			{
				down = false;
				up = true;
			}
		}
		else { render3(win, ren, shotgun, { 200, 200,200 }, 0x02, 90, width / 100 * 5, -height / 100 * 15, -0.1); }
		render3(win,ren,fence,{200,200,200},0x01,dx,player_x,player_y-30,player_z+1);
		render3(win, ren, barn,{ 200,200,200 },0x01,dx,player_x-200,player_y-30,player_z+1);
		{
			render3(win, ren, stack, { 200,200,200 }, 0x01, dx, player_x + 200, player_y - 30, player_z + 1.45);
			render3(win, ren, stack, { 200,200,200 }, 0x01, dx, player_x + 250, player_y - 30, player_z + 1.8);
			render3(win, ren, stack, { 200,200,200 }, 0x01, dx, player_x - 400, player_y - 30, player_z + 1.5);
			render3(win, ren, stack, { 200,200,200 }, 0x01, dx, player_x + 420, player_y - 30, player_z + 1);
			render3(win, ren, stack, { 200,200,200 }, 0x01, dx, player_x + 350, player_y - 30, player_z + 1.3);
			render3(win, ren, stack, { 200,200,200 }, 0x01, dx, player_x + 400, player_y - 30, player_z + 1.7);
			render3(win, ren, stack, { 200,200,200 }, 0x01, dx, player_x - 350, player_y - 30, player_z + 1.3);
			render3(win, ren, stack, { 200,200,200 }, 0x01, dx, player_x - 330, player_y - 30, player_z + 1.5);
		}
		SDL_RenderPresent(ren);
		SDL_Delay(20);
	}
	SDL_DestroyWindow(win);
	SDL_Quit();

	return 0;
}
