# 🏓 Ping-Pong Terminal Game (C Language)

![Made with C](https://img.shields.io/badge/Made%20with-C-blue?style=for-the-badge&logo=c)
![Platform](https://img.shields.io/badge/Platform-Linux%20Terminal-green?style=for-the-badge&logo=linux)
![License](https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge)

---

## 📖 Description
This is a **Ping-Pong game** written in **C**, playable directly in the **Linux terminal**.  
Challenge your friend and control the paddles in this retro-style arcade game.

There are two gameplay modes:
- 🎯 **pong.c** → Manual ball control (you move the ball yourself)
- ⚡ **pong_interactive.c** → Automatic ball movement (classic Pong style)

---

## ⚙️ Setup & Usage

1. **Clone this repository**
   ```bash
   git clone https://github.com/khamdamov200713/Ping-pong.git
   cd Ping-pong
   ```

2. **Compile the game**

   ▶️ **Manual ball control**
   ```bash
   gcc pong.c -o pong 
   ./pong
   ```

   ▶️ **Automatic ball movement**
   ```bash
   gcc pong_interactive.c -o pong_auto -lncurses
   ./pong_auto
   ```

---

## 🕹️ Controls

| Player | Move Up | Move Down |
|:--------|:----------:|:-----------:|
| 🧍 Left Paddle | `A` | `Z` |
| 🧍 Right Paddle | `K`  | `M`|
| 🎯 Ball Control (manual mode) | Arrow keys to move the ball |

---

## 🧩 Requirements

Make sure you have:
- GCC compiler  
- `ncurses` library installed  

---

## 📸 Example Gameplay (Terminal View)

```
+----------------------------------+
|             PING PONG            |
|        O           |             |
|                    |             |
|--------------------|-------------|
| Score: 3 - 4                      |
+----------------------------------+
```

![photo_2025-11-11_15-04-59](https://github.com/user-attachments/assets/e12317c5-b688-46ec-8659-30d6305f130a)

---

## 👨‍💻 Author

**Adkham Khamdamov**  
📧 [khamdamovadkham415@gmail.com](mailto:khamdamovadkham415@gmail.com)  
🌍 Tashkent, Uzbekistan  
💻 [GitHub Profile](https://github.com/khamdamov200713)

---
