#pragma once

#include <nanolib.h>

typedef struct s_game_grid {
    //The ball will be on a 6x8 grid.
    //X being 6 in length
    //Padle is locked from 1-6 but still writes from 0-7.
    //The reason for that is that the grid will be used to generate a frame.
    //The frame being the "image" displayed one the LED matrix.
    bool playerPaddle1[8];
    bool playerPaddle2[8];
    bool ball[6][8];
} t_game_grid;

typedef struct ball {
    int direction;      //Defined by: e_ball_direction.
} t_ball;

typedef enum e_ball_direction {
    Left,               //0     
    Right,              //1         
    Diagonal_Up_Left,   //2   
    Diagonal_Up_Right,  //3                
    Diagonal_Down_Left, //4    
    Diagonal_Down_Right //5  
} t_ball_direction;

typedef struct s_player {
    int paddlePosition; //Min = 0, Max = 6
    int score;          //Min = 0, Max = 3
} t_player;


