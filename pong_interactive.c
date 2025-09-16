#include <ncurses.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 25
#define PADDLE_HEIGHT 3
#define LEFT_PADDLE_X 2
#define RIGHT_PADDLE_X (WIDTH - 3)
#define WIN_SCORE 21

int main(void) {
    int left_paddle_y = (HEIGHT - PADDLE_HEIGHT) / 2;
    int right_paddle_y = (HEIGHT - PADDLE_HEIGHT) / 2;
    int ball_x = WIDTH / 2;
    int ball_y = HEIGHT / 2;
    int ball_dx = 1;
    int ball_dy = 1;
    int left_score = 0;
    int right_score = 0;
    int ch;  // для ввода

    initscr();
    noecho();
    cbreak();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    while (left_score < WIN_SCORE && right_score < WIN_SCORE) {
        clear();
        mvprintw(0, 0, "Score: Left %d - Right %d", left_score, right_score);

        for (int y = 1; y < HEIGHT - 1; y++) {
            mvaddch(y, 0, '|');
            mvaddch(y, WIDTH - 1, '|');
        }
        for (int x = 0; x < WIDTH; x++) {
            mvaddch(1, x, '-');
            mvaddch(HEIGHT - 2, x, '-');
        }

        for (int i = 0; i < PADDLE_HEIGHT; i++) {
            mvaddch(left_paddle_y + i, LEFT_PADDLE_X, '|');
            mvaddch(right_paddle_y + i, RIGHT_PADDLE_X, '|');
        }
        mvaddch(ball_y, ball_x, 'O');

        refresh();

        ch = getch();
        if (ch != ERR) {
            if (ch == 'a' || ch == 'A') {
                if (left_paddle_y > 2) left_paddle_y--;
            } else if (ch == 'z' || ch == 'Z') {
                if (left_paddle_y < HEIGHT - PADDLE_HEIGHT - 2) left_paddle_y++;
            } else if (ch == 'k' || ch == 'K') {
                if (right_paddle_y > 2) right_paddle_y--;
            } else if (ch == 'm' || ch == 'M') {
                if (right_paddle_y < HEIGHT - PADDLE_HEIGHT - 2) right_paddle_y++;
            } else if (ch == ' ') {
            }
        }

        int next_ball_x = ball_x + ball_dx;
        int next_ball_y = ball_y + ball_dy;

        if (next_ball_y <= 2 || next_ball_y >= HEIGHT - 3) {
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
            napms(500);
            continue;
        } else if (next_ball_x >= WIDTH - 1) {
            left_score++;
            ball_x = WIDTH / 2;
            ball_y = HEIGHT / 2;
            ball_dx = -1;
            ball_dy = 1;
            napms(500);
            continue;
        }

        ball_x = next_ball_x;
        ball_y = next_ball_y;

        napms(100);
    }

    clear();
    if (left_score == WIN_SCORE) {
        mvprintw(HEIGHT / 2, (WIDTH - 20) / 2, "Left player wins!");
    } else {
        mvprintw(HEIGHT / 2, (WIDTH - 21) / 2, "Right player wins!");
    }
    refresh();
    nodelay(stdscr, FALSE);
    getch();
    endwin();
    return 0;
}
