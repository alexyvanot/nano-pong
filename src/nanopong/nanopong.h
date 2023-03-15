#ifndef nanopong_h
#define nanopong_h

#include "nanolib.h"

<<<<<<< HEAD
typedef struct s_paddle_position_map {
    uint8_t position;
    uint8_t bit;
} t_paddle_position_map;
=======
void initGame();
void initPotentiometers();
void initPaddle();
void initBall();
void initScore();

void updatePaddle();
void updateBall();
void updateScore();

void drawPaddle();
void drawBall();
void drawScore();


void startGame();
int isGameStarted();
int isGameFinished();


enum PaddleDirection {
  PADDLE_UP,
  PADDLE_DOWN,
  PADDLE_NONE
};

enum BallDirection {
  BALL_UP,
  BALL_DOWN,
  BALL_LEFT,
  BALL_RIGHT,
  BALL_NONE
};

enum Score {
  SCORE_0,
  SCORE_1,
  SCORE_2,
  SCORE_3
};

enum PaddlePosition {
  PADDLE_LEFT,
  PADDLE_RIGHT
};

enum BallPosition {
  BALL_LEFT,
  BALL_RIGHT
};

enum GameStatus {
  GAME_STARTED,
  GAME_FINISHED
};

enum Players {
  PLAYER_LEFT,
  PLAYER_RIGHT
};

typedef struct {
  uint8_t x;
  uint8_t y;
  uint8_t width;
  uint8_t height;
  enum PaddleDirection direction;
  enum PaddlePosition position;
} Paddle;

typedef struct {
  uint8_t x;
  uint8_t y;
  uint8_t width;
  uint8_t height;
  enum BallDirection direction;
  enum BallPosition position;
} Ball;

typedef struct {
  enum Score left;
  enum Score right;
} Score;

typedef struct {
  Paddle left;
  Paddle right;
  Ball ball;
  Score score;
  enum GameStatus status;
} Game;

void initGame() {
  initPaddle();
  initBall();
  initScore();
}

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
>>>>>>> 912a2a6e4d2fbc8e0a9607bd729cce8bb79032d5

typedef struct s_adcValue_position_map {
    uint16_t adcValue;
    uint8_t position;
} t_adcValue_position_map;

typedef enum e_ball_direction {
    Left,               //0
    Right,              //1
    Diagonal_Up_Left,   //2
    Diagonal_Up_Right,  //3
    Diagonal_Down_Left, //4
    Diagonal_Down_Right //5
} t_ball_direction;

typedef struct s_ball {
    //Defined by: e_ball_direction.
    t_ball_direction direction;      
    //Top left corner is 0,0.
    //Bottom right corner is 7,7.
    uint8_t x;  //Min = 0, Max = 7
    uint8_t y;  //Min = 0, Max = 7
} t_ball;

typedef struct s_player {
    uint8_t index;          //Min = 0, Max = 1
    uint8_t paddlePosition; //Min = 0, Max = 5 (To sync coords with ball offset by +1 !)
    uint8_t score;          //Min = 0, Max = 3
} t_player;

typedef struct s_game {
    t_player players[2];
    t_ball ball;
    uint8_t isGameStarted;
    uint8_t isGameFinished;
} t_game;

t_ball initBall();

t_ball updateBall(t_game game);

void update(t_game* game);

t_ball checkAndOrChangeDirection(t_ball ball, t_player player1, t_player player2);

t_ball moveBall(t_ball ball);

uint8_t get_paddle_position(t_player player);

t_game init_game();

void start_game();

void draw_game(t_game game);

uint8_t get_paddle_position(t_player player);

uint8_t generate_random_number(uint8_t lower, uint8_t upper); //upper inclusive

#endif