#include <stdio.h>

void draw_field(int left_paddle_y, int right_paddle_y, int ball_x, int ball_y, int left_score,
                int right_score);
int main() {
#define WIDTH 80
#define HEIGHT 25
#define PADDLE_HEIGHT 3
#define LEFT_PADDLE_X 2
#define RIGHT_PADDLE_X (WIDTH - 3)

    int left_paddle_y = (HEIGHT - PADDLE_HEIGHT) / 2;
    int right_paddle_y = (HEIGHT - PADDLE_HEIGHT) / 2;
    int ball_x = WIDTH / 2;
    int ball_y = HEIGHT / 2;
    int ball_dx = 1;
    int ball_dy = 1;
    int left_score = 0;
    int right_score = 0;
    char input;

    while (left_score < 21 && right_score < 21) {
        draw_field(left_paddle_y, right_paddle_y, ball_x, ball_y, left_score, right_score);
        printf("Enter move (A/Z - left paddle, K/M - right paddle, Space - skip move): ");

        input = getchar();
        while (getchar() != '\n');

        if (input == 'A' || input == 'a') {
            if (left_paddle_y > 1) left_paddle_y--;
        } else if (input == 'Z' || input == 'z') {
            if (left_paddle_y < HEIGHT - PADDLE_HEIGHT - 1) left_paddle_y++;
        } else if (input == 'K' || input == 'k') {
            if (right_paddle_y > 1) right_paddle_y--;
        } else if (input == 'M' || input == 'm') {
            if (right_paddle_y < HEIGHT - PADDLE_HEIGHT - 1) right_paddle_y++;
        }

        int next_ball_x = ball_x + ball_dx;
        int next_ball_y = ball_y + ball_dy;

        if (next_ball_y <= 0 || next_ball_y >= HEIGHT - 1) {
            ball_dy = -ball_dy;
            next_ball_y = ball_y + ball_dy;
        }

        if (next_ball_x == LEFT_PADDLE_X + 1) {
            if (next_ball_y >= left_paddle_y && next_ball_y < left_paddle_y + PADDLE_HEIGHT) {
                ball_dx = -ball_dx;
                next_ball_x = ball_x + ball_dx;
            }
        }

        if (next_ball_x == RIGHT_PADDLE_X - 1) {
            if (next_ball_y >= right_paddle_y && next_ball_y < right_paddle_y + PADDLE_HEIGHT) {
                ball_dx = -ball_dx;
                next_ball_x = ball_x + ball_dx;
            }
        }

        if (next_ball_x <= 0) {
            right_score++;
            ball_x = WIDTH / 2;
            ball_y = HEIGHT / 2;
            ball_dx = 1;
            ball_dy = 1;
            continue;
        }
        if (next_ball_x >= WIDTH - 1) {
            left_score++;
            ball_x = WIDTH / 2;
            ball_y = HEIGHT / 2;
            ball_dx = -1;
            ball_dy = 1;
            continue;
        }

        ball_x = next_ball_x;
        ball_y = next_ball_y;
    }

    draw_field(left_paddle_y, right_paddle_y, ball_x, ball_y, left_score, right_score);
    if (left_score == 21) {
        printf("Left player wins! Congratulations!\n");
    } else {
        printf("Right player wins! Congratulations!\n");
    }

    return 0;
}

void draw_field(int left_paddle_y, int right_paddle_y, int ball_x, int ball_y, int left_score,
                int right_score) {
    printf("\033[2J\033[H");
    printf("Score: Left %d - Right %d\n", left_score, right_score);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (y == 0 || y == HEIGHT - 1) {
                putchar('-');
            } else if (x == 0 || x == WIDTH - 1) {
                putchar('|');
            } else if (x == LEFT_PADDLE_X && y >= left_paddle_y && y < left_paddle_y + PADDLE_HEIGHT) {
                putchar('|');
            } else if (x == RIGHT_PADDLE_X && y >= right_paddle_y && y < right_paddle_y + PADDLE_HEIGHT) {
                putchar('|');
            } else if (x == ball_x && y == ball_y) {
                putchar('o');
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }
}
