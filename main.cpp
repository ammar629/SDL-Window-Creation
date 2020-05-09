/*
SDL DOCS
*/

#include <iostream>
#include <SDL.h>
//For the purposes of learning
const int WIDTH= 1080;
const int HEIGHT = 720;

int main(int argc, char* argv[]) {

	SDL_Window* Window = nullptr; //Creates a pointer to a window
	
    /*
	Pointer to surfaces
	*/
	SDL_Surface* WindowSurface = nullptr;  
	SDL_Surface* ImgSurface = nullptr;
	
	
	/*
	Initialization check
	Just to make sure everything has been loaded properly
	*/


	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << "Init Error\n" << SDL_GetError() << std::endl;
	}


	//If no hiccups lets build a window

	else {

		//SDL_CreateWindow takes the parameters title,x coordinate,y coordinate,width,height, a flag for the window (uint32)
		Window = SDL_CreateWindow("Half-Life AV", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
		

		//If failure to create window / if pointer to window is NULL then some error occured
		if (Window == NULL) {
			std::cout << "Window Initialization Error\n" << SDL_GetError() << std::endl;
		}

		//No error occured while allocating memory for a new window on the heap
		
		else {


			// Since its not NULL then we have a window surface avaiable
			WindowSurface = SDL_GetWindowSurface(Window);
			
			//Load a bmp file
			ImgSurface = SDL_LoadBMP("Hl.bmp"); // .bmp file must be in your project folder
			
			
			//Failed to load .bmp, print error
			if (ImgSurface == NULL) {
				std::cout << "No Img\n" << SDL_GetError() << std::endl;
			}

			//.bmp loaded successfully 

			else {

			//Copy Image from one surface to another
				//Parameters
				//src,the SDL_Surface structure to be copied from
				//srcrect,the SDL_Rect structure representing the rectangle to be copied, or NULL to copy the entire surface
				//dst, the target SDL_Surface
				//dstrect, the SDL_Rect structure representing the rectangle that is copied into

				SDL_BlitSurface(ImgSurface, NULL, WindowSurface, NULL);
				SDL_UpdateWindowSurface(Window);
				SDL_Delay(30000);
			}

		}
	}

	//Free the memory pointed to by ImgSurface (SDL_Surface ptr)
	SDL_FreeSurface(ImgSurface);
	ImgSurface = nullptr;

	//Destroy Window
	SDL_DestroyWindow(Window);
	Window = nullptr;
	
	//Since Window was destroyed its a good practice to set WindowSurface to null too
	WindowSurface = nullptr;

	//Quit
	SDL_Quit();
	return EXIT_SUCCESS;
}