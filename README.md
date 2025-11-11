![photo_2025-11-11_15-04-59](https://github.com/user-attachments/assets/e12317c5-b688-46ec-8659-30d6305f130a)
🏓 Ping-Pong Terminal Game (C Language)

📖 Description

This is a simple Ping-Pong game written in C, playable directly in the terminal.
The game uses keyboard input to move paddles and simulate a ball bouncing — similar to the classic Pong arcade game.

⚙️ Features

Two-player mode (left & right paddles)

Real-time ball movement

Score tracking

Written in pure C with ncurses library

🕹️ Controls
Player	Move Up	Move Down
Left Paddle: A   Z
Right Paddle: M   K

🧩 Requirements

Make sure you have:

GCC compiler

ncurses library installed

⚙️ Setup & Usage
1. Clone this repository
git clone https://github.com/khamdamov200713/Ping-pong.git
cd Ping-pong
gcc pong.c -o pong
gcc pong_interactive.c -o pong_interactive -lncurses
