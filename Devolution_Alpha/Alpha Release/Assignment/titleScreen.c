//
//  titleScreen.c
//  Assignment
//
//  Created by Josef Bode on 5/23/19.
//  Copyright © 2019 CodeBound. All rights reserved.
//

#include "titleScreen.h"
#include "graphics.h"

void init_title_screen(GameState *game){
    
    //create any text to be used on the title screen//
    //Title text:
    SDL_Color white = { 255, 255, 255, 255};                                                //text colour set to white
    SDL_Surface *tmp0 = TTF_RenderText_Blended(game->titleFont, "Devolution", white);       //use a surface to hold the text
    game->titleW = tmp0->w;                                                                 //store the width of the text
    game->titleH = tmp0->h;                                                                 //store the height of the text
    game->title = SDL_CreateTextureFromSurface(game->renderer, tmp0);                       //create texture from text surface
    SDL_FreeSurface(tmp0);                                                                  //destroy surface
    //Subtitle text:
    SDL_Surface *tmp4 = TTF_RenderText_Blended(game->subtitleFont, "A text-based adventure . . .", white);
    game->subtitleW = tmp4->w;
    game->subtitleH = tmp4->h;
    game->subtitle = SDL_CreateTextureFromSurface(game->renderer, tmp4);
    SDL_FreeSurface(tmp4);
    //Footer text:
    SDL_Surface *tmp5 = TTF_RenderText_Blended(game->footerFont, "CodeBound 2019 WORKING ALPHA RELEASE", white);
    game->footerW = tmp5->w;
    game->footerH = tmp5->h;
    game->footer = SDL_CreateTextureFromSurface(game->renderer, tmp5);
    SDL_FreeSurface(tmp5);
    //Options text:
    //NEWGAME
    SDL_Surface *tmp1 = TTF_RenderText_Blended(game->menuFont, "New Game", white);
    game->newGameW = tmp1->w;
    game->newGameH = tmp1->h;
    game->newGame = SDL_CreateTextureFromSurface(game->renderer, tmp1);
    SDL_FreeSurface(tmp1);
    //LOADGAME
    SDL_Color faded = { 255, 255, 255, 90};
    SDL_Surface *tmp2 = TTF_RenderText_Blended(game->menuFont, "Continue", faded);
    game->loadGameW = tmp2->w;
    game->loadGameH = tmp2->h;
    game->loadGame = SDL_CreateTextureFromSurface(game->renderer, tmp2);
    SDL_FreeSurface(tmp2);
    //QUITGAME
    SDL_Surface *tmp3 = TTF_RenderText_Blended(game->menuFont, "Quit Game", white);
    game->quitGameW = tmp3->w;
    game->quitGameH = tmp3->h;
    game->quitGame = SDL_CreateTextureFromSurface(game->renderer, tmp3);
    SDL_FreeSurface(tmp3);
    
    //move selector to the right place and set the right dimensions//
    game->selectorStatus = SELECTOR_HOVER_NEWGAME;
    game->selector.x = game->screenCenterX-game->newGameW/2-25;
    game->selector.y = game->screenCenterY-15;
    game->selector.w = game->newGameW+50;
    game->selector.h = game->newGameH+30;
}

void draw_title_screen(GameState *game){
    SDL_Renderer *renderer = game->renderer;
    const int DISPLAY_W = 1000, DISPLAY_H = 710;
    
    // set the background //
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    // draw OUTLINE //
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect outlineRect = { game->screenCenterX-DISPLAY_W/2-5, game->screenCenterY-DISPLAY_H/2-5, DISPLAY_W+10, DISPLAY_H+10 };
    SDL_RenderFillRect(renderer, &outlineRect);
    
    // draw the DISPLAY //
    SDL_SetRenderDrawColor(renderer, 10, 10, 10, 255);
    SDL_Rect displayRect = { game->screenCenterX-DISPLAY_W/2, game->screenCenterY-DISPLAY_H/2, DISPLAY_W, DISPLAY_H };
    SDL_RenderFillRect(renderer, &displayRect);
    
    // draw the SELECTOR //
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect selectorPanel = { game->selector.x, game->selector.y, game->selector.w, game->selector.h };
    SDL_RenderFillRect(renderer, &selectorPanel);
    
    // draw the GAME TITLE //
    SDL_Rect titleRect = { game->screenCenterX-game->titleW/2, game->screenCenterY-300, game->titleW, game->titleH};
    SDL_RenderCopy(renderer, game->title, NULL, &titleRect);
    // draw the SUBTITLE //
    SDL_Rect subtitleRect = { game->screenCenterX-game->subtitleW/2, game->screenCenterY-130, game->subtitleW, game->subtitleH};
    SDL_RenderCopy(renderer, game->subtitle, NULL, &subtitleRect);
    // draw the FOOTER //
    SDL_Rect footerRect = { game->screenCenterX-game->footerW/2, game->screenCenterY+310, game->footerW, game->footerH};
    SDL_RenderCopy(renderer, game->footer, NULL, &footerRect);
    
    // draw the NEWGAME option //
    // draw the backdrop:
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_Rect newGameBD = { game->screenCenterX-game->newGameW/2-20, game->screenCenterY-10, game->newGameW+40, game->newGameH+20};
    SDL_RenderFillRect(renderer, &newGameBD);
    //Draw the text:
    SDL_Rect newGameRect = { game->screenCenterX-game->newGameW/2, game->screenCenterY, game->newGameW, game->newGameH};
    SDL_RenderCopy(renderer, game->newGame, NULL, &newGameRect);
    
    // draw the LOADGAME option //
    // draw the backdrop:
    SDL_Rect loadGameBD = { game->screenCenterX-game->loadGameW/2-20, game->screenCenterY+90, game->loadGameW+40, game->loadGameH+20};
    SDL_RenderFillRect(renderer, &loadGameBD);
    //Draw the text:
    SDL_Rect loadGameRect = { game->screenCenterX-game->loadGameW/2, game->screenCenterY+100, game->loadGameW, game->loadGameH};
    SDL_RenderCopy(renderer, game->loadGame, NULL, &loadGameRect);
    
    // draw the QUITGAME option //
    // backdrop:
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_Rect quitGameBD = { game->screenCenterX-game->quitGameW/2-20, game->screenCenterY+190, game->quitGameW+40, game->quitGameH+20};
    SDL_RenderFillRect(renderer, &quitGameBD);
    // text:
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect quitGameRect = { game->screenCenterX-game->quitGameW/2, game->screenCenterY+200, game->quitGameW, game->quitGameH};
    SDL_RenderCopy(renderer, game->quitGame, NULL, &quitGameRect);
    
    //render what we have drawn:
    SDL_RenderPresent(renderer);
}

void shutdown_title_screen(GameState *game){
    SDL_DestroyTexture(game->title);
    SDL_DestroyTexture(game->subtitle);
    SDL_DestroyTexture(game->newGame);
    SDL_DestroyTexture(game->loadGame);
    SDL_DestroyTexture(game->quitGame);
    SDL_DestroyTexture(game->footer);
    game->title = NULL;
    game->newGame = NULL;
}

