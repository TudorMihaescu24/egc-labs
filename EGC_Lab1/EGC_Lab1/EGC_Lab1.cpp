//
//  main.cpp
//  SDL_Lab1
//
//  Created by CGIS on 16/02/16.
//  Copyright © 2016 CGIS. All rights reserved.
//

#include <iostream>
#include "include\SDL.h"

enum Color{
    none, red,green, blue};

//define window dimensions
const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

SDL_Window *window = NULL;
SDL_Surface *windowSurface = NULL;
SDL_Event currentEvent;

SDL_Rect rectangleCoordinates = {0, 0, 0, 0};
Uint32 rectagleColor;

bool quit = false;

int mouseX, mouseY;

bool initWindow()
{
    bool success = true;
    
    //Try to initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL initialization failed" << std::endl;
        success = false;
    }
    else{
        //Try to create the window
        window = SDL_CreateWindow("SDL Hello World Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);
        
        if(window == NULL)
        {
            std::cout << "Failed to create window: " << SDL_GetError() << std::endl;
            success = false;
        }
        else
        {
            //Try to get the window surface
            windowSurface = SDL_GetWindowSurface(window);
            
            if(windowSurface == NULL)
            {
                std::cout << "Failed to get the window surface: " << SDL_GetError() << std::endl;
                success = false;
            }
            else
            {
                //Initialize surface color
                SDL_FillRect(windowSurface, NULL, SDL_MapRGB(windowSurface->format, 255, 255, 255));
                
                //Update the surface
                SDL_UpdateWindowSurface(window);
            }

        }
    }
    
    return success;
}

void destroyWindow()
{
    //Destroy window
    SDL_DestroyWindow(window);
    window = NULL;
    
    //Quit SDL
    SDL_Quit();
}

int main(int argc, char * argv[]) {


    int Cred = 0;
    int Cgreen = 0;
    int Cblue = 0;
    int coord1X = 0;
    int coord1Y = 0;
    int coord2X = 0;
    int coord2Y = 0;
    int currentColor = none;
    bool coordSet = false;

    if(!initWindow())
    {
        std::cout << "Failed to initialize" << std::endl;
        return -1;
    }
    
    rectagleColor = SDL_MapRGB(windowSurface->format, 0, 0, 0);
    
    while (!quit) {
        //Handle events on queue
        if(SDL_WaitEvent(&currentEvent) != 0)
        {
            //User requests quit
            if(currentEvent.type == SDL_QUIT)
            {
                quit = true;
            }
            
            //Mouse event -> pressed button
            if(currentEvent.type == SDL_MOUSEBUTTONDOWN)
            {
                if(currentEvent.button.button == SDL_BUTTON_LEFT)
                {
                    SDL_GetMouseState(&mouseX, &mouseY);
                    if (coordSet == false)
                    {
                        coord1X = mouseX;
                        coord1Y = mouseY;
                        coordSet = true;
                    }
                    else
                    {
                        coord2X = mouseX - coord1X;
                        coord2Y = mouseY - coord1Y;
                    }
                 
                }   
            }

            if (currentEvent.type == SDL_MOUSEMOTION)
            {
                if (currentEvent.button.button == SDL_BUTTON_LEFT)
                {
                    SDL_GetMouseState(&mouseX, &mouseY);
                    if (coordSet == false)
                    {
                        coord1X = mouseX;
                        coord1Y = mouseY;
                        coordSet = true;
                    }
                    else
                    {
                        coord2X = mouseX - coord1X;
                        coord2Y = mouseY - coord1Y;
                    }

                }
            }

            Uint32 colorWhite = SDL_MapRGB(windowSurface->format, 255, 255, 255);
           
            
            //Keyboard event
            if(currentEvent.type == SDL_KEYDOWN)
            {

                switch(currentEvent.key.keysym.sym)
                {

                    case SDLK_UP:
                        switch (currentColor) {
                            case red:
                                if(Cred < 255)
                                    Cred++;
                                else
                                    Cred = 0;
                                break;
                            case blue:
                                if(Cblue < 255)
                                    Cblue++;
                                else
                                    Cblue = 0;
                                break;
                            case green:
                                if(Cgreen < 255)
                                    Cgreen++;
                                else
                                    Cgreen = 0;
                                break;
                        }

                        std::cout << "Color: (" << Cred << "," << Cgreen << "," << Cblue << ")" << std::endl;
                        rectagleColor = SDL_MapRGB(windowSurface->format, Cred, Cgreen, Cblue);
                        break;

                    case SDLK_DOWN:
                        switch (currentColor) {
                            case red:
                                if (Cred > 0)
                                    Cred--;
                                else
                                    Cred = 255;
                                break;
                            case blue:
                                if (Cblue > 0)
                                    Cblue--;
                                else
                                    Cblue = 255;
                                break;
                            case green:
                                if (Cgreen > 0)
                                    Cgreen--;
                                else
                                    Cgreen = 255;
                        }
                                break;

                    case SDLK_q:
                        coordSet = false;
                        break;
                        
                    case SDLK_r:
                        currentColor = red;
                        std::cout << "Color selected: red";
                        break;

                    case SDLK_g:
                        currentColor = green;
                        std::cout << "Color selected: green";
                        break;

                    case SDLK_b:
                        currentColor = blue;
                        std::cout << "Color selected: blue";
                        break;

                    default:
                        rectagleColor = SDL_MapRGB(windowSurface->format, Cred, Cgreen, Cblue);
                        break;
                }
            }
             

            SDL_FillRect(windowSurface, &rectangleCoordinates, colorWhite);
            rectangleCoordinates = { coord1X, coord1Y, coord2X, coord2Y };
            SDL_FillRect(windowSurface, &rectangleCoordinates, rectagleColor);
            
            SDL_UpdateWindowSurface(window);
        }
    }
    
    destroyWindow();
    return 0;
}
