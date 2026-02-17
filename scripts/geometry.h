struct Point
{
	float x,y,z;
};

struct Vector
{
	float x1,y1,z1;
	float x2,y2,z2;
};

struct Triangle
{
	float x1,y1,z1;
	float x2,y2,z2;
	float x3,y3,z3;
};

void point3(SDL_Window* window, SDL_Renderer* render, float x, float y, float z)
{
	if (z >= 0)
	{
		int w, h;

		if (z == 0) { z = 1; }
		SDL_GetWindowSize(window, &w, &h);

		SDL_RenderDrawPoint(render, w / 2 + (x / z), h / 2 - (y / z));
	}
}

void vector2(SDL_Window* window,SDL_Renderer* render,float x1,float y1,float x2,float y2)
{
	int w,h;
	
	SDL_GetWindowSize(window,&w,&h);

	SDL_RenderDrawLine(render,w/2+x1,h/2-y1,w/2+x2,h/2-y2);
}

void vector3(SDL_Window* window, SDL_Renderer* render, float x1, float y1, float z1, float x2, float y2, float z2)
{
	if (z1 >= 0 && z2 >= 0)
	{
		int w, h;

		if (z1 == 0) { z1 = 1; }
		if (z2 == 0) { z2 = 1; }
		SDL_GetWindowSize(window, &w, &h);

		SDL_RenderDrawLine(render, w / 2 + (x1 / z1), h / 2 - (y1 / z1), w / 2 + (x2 / z2), h / 2 - (y2 / z2));
	}
}

void triangle3(SDL_Window* window, SDL_Renderer* render, float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3)
{
	//if (z1 >= 0 && z2 >= 0 && z3 >= 0)
	{
		int w, h;

		if (z1 == 0) { z1 = 1; }
		if (z1 < 0) { z1 *= -1; }
		if (z2 == 0) { z2 = 1; }
		if (z2 < 0) { z2 *= -1; }
		if (z3 == 0) { z3 = 1; }
		if (z3 < 0) { z3 *= -1; }
		SDL_GetWindowSize(window, &w, &h);

		SDL_RenderDrawLine(render, w / 2 + (x1 / z1), h / 2 - (y1 / z1), w / 2 + (x2 / z2), h / 2 - (y2 / z2));
		SDL_RenderDrawLine(render, w / 2 + (x1 / z1), h / 2 - (y1 / z1), w / 2 + (x3 / z3), h / 2 - (y3 / z3));
		SDL_RenderDrawLine(render, w / 2 + (x2 / z2), h / 2 - (y2 / z2), w / 2 + (x3 / z3), h / 2 - (y3 / z3));
	}
}
