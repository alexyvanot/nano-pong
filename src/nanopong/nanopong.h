#pragma once

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

