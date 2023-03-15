#pragma once

#include <nanolib.h>

typedef struct s_game_grid {    //May be deprecate. TBD.
    //The ball will be on a 6x8 grid.
    //X being 6 in length
    //Padle is locked from 1-6 but still writes from 0-7.
    //The reason for that is that the grid will be used to generate a frame.
    //The frame being the "image" displayed one the LED matrix.
    bool playerPaddle1[8];
    bool playerPaddle2[8];
    bool ball[8][8];
} t_game_grid;

typedef struct ball {
    //Defined by: e_ball_direction.
    uint8_t direction;      
    //Top left corner is 0,0.
    //Bottom right corner is 7,7.
    uint8_t x;  //Min = 0, Max = 7
    uint8_t y;  //Min = 0, Max = 7
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
    uint8_t index;          //Min = 0, Max = 1
    uint8_t paddlePosition; //Min = 0, Max = 5 (To sync coords with ball offset by +1 !)
    uint8_t score;          //Min = 0, Max = 3
} t_player;

t_ball initBall();

t_player initPlayer();

void updatePlayer(t_player player, t_nano_pin potentiometer);

void updateBall(t_ball ball, t_player player1, t_player player2);

