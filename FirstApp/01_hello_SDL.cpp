/*This source code copyrighted by Lazy Foo' Productions (2004-2019)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <array>
#include <map>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gHelloWorld = NULL;
std::array<SDL_Surface*, 5> gKeyPressSurfaces;

enum class KeyPressSurfaces
{
	DEFAULT,
	UP,
	DOWN,
	LEFT,
	RIGHT,
	COUNT,
};

bool init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load splash image
	gHelloWorld = SDL_LoadBMP("hello_world.bmp");
	if (gHelloWorld == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "hello_world.bmp", SDL_GetError());
		success = false;
	}

	return success;
}

void close()
{
	//Deallocate surface
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

SDL_Surface* loadSurface(std::string path)
{
	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to laod image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
	}
	return loadedSurface;
}

bool loadMedia()
{
	/*
	std::array<std::pair<KeyPressSurfaces, std::string>, 5> picdirs = {
		std::pair<KeyPressSurfaces, std::string>(KeyPressSurfaces::DEFAULT, "press.bmp"),
		"up.bmp",
		"down.bmp",
		"left.bmp",
		"right.bmp",
	};
	*/

	std::map<KeyPressSurfaces, std::string> picdirs;
	picdirs[KeyPressSurfaces::DEFAULT] = "press.bmp";
	picdirs[KeyPressSurfaces::UP] = "up.bmp";
	picdirs[KeyPressSurfaces::DOWN] = "down.bmp";
	picdirs[KeyPressSurfaces::LEFT] = "left.bmp";
	picdirs[KeyPressSurfaces::RIGHT] = "right.bmp";

	for (int i = 0; i < 5; i++)
	{

		gKeyPressSurfaces[KeyPressSurfaces::]
	}
}

int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Apply the image
			SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
			
			//Update the surface
			SDL_UpdateWindowSurface( gWindow );
		}
	}
	bool quit = false;
	SDL_Event e;

	while (!quit) 
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}
	}

	//Destroy window
	SDL_DestroyWindow( gWindow );

	//Quit SDL subsystems
	close();

	return 0;
}