#include "nanopong.h"

t_ball initBall() {
    uint8_t rX = 3;
    uint8_t rY = 3;
    uint8_t rDirection = 0;

    //Randomise the x starting point.
    if (rand() % 2 == 0) {
        rX = 3;
    } else {
        rX = 4;
    }

    //Randomise the y starting point.
    if (rand() % 2 == 0) {
        rY = 3;
    } else {
        rY = 4;
    }

    //Randomise the direction.
    if (rand() % 2 == 0) { //Left or Right
        if (rand() % 2 == 0) { //Horizontal or Diagonal
            if (rand() % 2 == 0) {  //If (Diagonal) Up or Down
                rDirection = Diagonal_Up_Left;
            } else {
                rDirection = Diagonal_Down_Left;
            }
        } else {
            rDirection = Left;
        }
    } else {
        if (rand() % 2 == 0) { //Horizontal or Diagonal
            if (rand() % 2 == 0) {  //If (Diagonal) Up or Down
                rDirection = Diagonal_Up_Right;
            } else {
                rDirection = Diagonal_Down_Right;
            }
        } else {
            rDirection = Right;
        }
    }

    //Create the ball.
    t_ball ball;
    ball.direction = rDirection;
    ball.x = rX;
    ball.y = rY;

    return ball;
}

t_player initPlayer() {
    uint8_t rPosition = 4;

    //Randomise the paddle starting point.
    if (rand() % 2 == 0) {
        rPosition = 3;
    } else {
        rPosition = 4;
    }

    //Create the player.
    t_player player;
    player.index = rPosition;
    player.score = 0;

    return player;
}

void updateBall(t_ball ball, t_player player1, t_player player2) {
    checkAndOrChangeDirection(ball, player1, player2);
    moveBall(ball);
}

void checkAndOrChangeDirection(t_ball ball, t_player player1, t_player player2) {
    switch (ball.x) {   //Check if ball is neighboring the paddles.
        case 1: //Left Paddle (Player 1).
            if (ball.direction % 2 == 0) {  //Check if ball is going left.
                if (ball.y == (player1.paddlePosition + 1)) { //Ball hit the middle of the paddle.
                    ball.direction = Right;
                    return;
                } else if (ball.y == (player1.paddlePosition + 1) - 1 || (player1.paddlePosition + 1) - 2) { //Ball hit the top of the paddle.
                    ball.direction = Diagonal_Up_Right;
                } else if (ball.y == (player1.paddlePosition + 1) + 1 || ball.y == (player1.paddlePosition + 1) + 2) { //Ball hit the bottom of the paddle.
                    ball.direction = Diagonal_Down_Right;
                }
            }
            break;
        case 6: //Right Padde (Player 2).
            if (ball.direction % 2 == 1) {  //Check if ball is going right.
                if (ball.y == (player1.paddlePosition + 1)) { //Ball hit the middle of the paddle.
                    ball.direction = Left;
                    return;
                } else if (ball.y == (player2.paddlePosition + 1) - 1 || (player2.paddlePosition + 1) - 2) { //Ball hit the top of the paddle.
                    ball.direction = Diagonal_Up_Left;
                } else if (ball.y == (player2.paddlePosition + 1) + 1 || ball.y == (player2.paddlePosition + 1) + 2) { //Ball hit the bottom of the paddle.
                    ball.direction = Diagonal_Down_Left;
                }
            }
    }

    switch (ball.y) {
        case 0:
            if (ball.direction % 2 == 0) {
                ball.direction = Diagonal_Down_Left;
            } else {
                ball.direction = Diagonal_Down_Right;
            }
            break;
        case 7:
            if (ball.direction % 2 == 0) {
                ball.direction = Diagonal_Up_Left;
            } else {
                ball.direction = Diagonal_Up_Right;
            }
            break;
    }
}

void moveBall(t_ball ball) {
    if (ball.direction % 2 == 0) { //True = Left | False = Right.
            ball.x--;
        } else {
            ball.x++;
        }

    if (ball.direction != 0 && ball.direction != 1) { //True = Diagonal
        if (ball.direction == 2 || ball.direction == 3) { //True = Up | False = Down.
            ball.y--;
        } else {
            ball.y++;
        }
    }
}