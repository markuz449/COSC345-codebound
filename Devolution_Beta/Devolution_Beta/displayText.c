//
//  displayText.c
//  Devolution_Beta
//
//  Created by Josef Bode on 8/5/19.
//  Copyright © 2019 CodeBound. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#include "displayText.h"
#include "graphics.h"

//#include "textManipulation.h"
//#include "fileManager.h"
//#include "mylib.h"

void init_display_text(GameState *game){
    SDL_Color white = { 255, 255, 255, 255 };
    
    if (game->scenarioStatus == SCENARIO_INTRO) {
        char *intro = NULL;
        intro = "PUT INTRODUCTION HERE!\n\nSPACEBAR TO CONTINUE";
        
        // create any text to be used on the game screen //
        SDL_Surface *tmp0 = TTF_RenderText_Blended_Wrapped(game->gameFont, intro, white, 900);
        game->storyTextW = tmp0->w;
        game->storyTextH = tmp0->h;
        game->storyText = SDL_CreateTextureFromSurface(game->renderer, tmp0);
        SDL_FreeSurface(tmp0);
    }
    /**
    if (game->scenarioStatus == SCENARIO_LASTPAGE) {
        char *C1 = NULL;
        C1 = "PUT INTRODUCTION HERE!\n\nSPACEBAR TO CONTINUE";
        //CHOICES text:
        SDL_Surface *tmp1 = TTF_RenderText_Blended_Wrapped(game->gameFont, continueText, white, 800);
        game->choice3TextW = tmp1->w;
        game->choice3TextH = tmp1->h;
        game->choice3Text = SDL_CreateTextureFromSurface(game->renderer, tmp1);
        SDL_FreeSurface(tmp1);
     
    }
     */
}

void draw_display_text(GameState *game){
    SDL_Renderer *renderer = game->renderer;
    
    if (game->scenarioStatus == SCENARIO_INTRO) {
        // draw the STORY text //
        SDL_Rect storyRect = { game->screenCenterX-game->storyTextW/2, game->screenCenterY-320, game->storyTextW, game->storyTextH};
        SDL_RenderCopy(renderer, game->storyText, NULL, &storyRect);
        // draw the CHOICES text //
        SDL_Rect choice1Rect = { game->screenCenterX-game->choice1TextW/2, game->screenCenterY+210, game->choice1TextW, game->choice1TextH};
        SDL_RenderCopy(renderer, game->choice1Text, NULL, &choice1Rect);
        SDL_Rect choice2Rect = { game->screenCenterX-game->choice2TextW/2, game->screenCenterY+260, game->choice2TextW, game->choice2TextH};
        SDL_RenderCopy(renderer, game->choice2Text, NULL, &choice2Rect);
        SDL_Rect choice3Rect = { game->screenCenterX-game->choice3TextW/2, game->screenCenterY+310, game->choice3TextW, game->choice3TextH};
        SDL_RenderCopy(renderer, game->choice3Text, NULL, &choice3Rect);
    } 
}

void nextPage(GameState *game){
    if (game->scenarioStatus == SCENARIO_INTRO) {
        game->scenarioStatus = SCENARIO_PAGE1;
        init_display_text(game);
        return;
    }

    if (game->scenarioStatus == SCENARIO_PAGE1) {
        game->scenarioStatus = SCENARIO_PAGE2;
        init_display_text(game);
        return;
    }
    
    if (game->scenarioStatus == SCENARIO_PAGE2) {
        game->scenarioStatus = SCENARIO_PAGE3;
        init_display_text(game);
        return;
    }
}

void prevPage(GameState *game) {
    if (game->scenarioStatus == SCENARIO_PAGE3) {
        game->scenarioStatus = SCENARIO_PAGE2;
        init_display_text(game);
        return;
    }
    
    if (game->scenarioStatus == SCENARIO_PAGE2) {
        game->scenarioStatus = SCENARIO_PAGE1;
        init_display_text(game);
        return;
    }
}

void shutdown_display_text(GameState *game){
    SDL_DestroyTexture(game->storyText);
    SDL_DestroyTexture(game->choice1Text);
    SDL_DestroyTexture(game->choice2Text);
    SDL_DestroyTexture(game->choice3Text);
    game->storyText = NULL;
    game->choice1Text = NULL;
    game->choice2Text = NULL;
    game->choice3Text = NULL;
}
