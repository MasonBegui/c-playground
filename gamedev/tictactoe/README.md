# Tic-Tac-Toe

A C implementation of Tic-Tac-Toe with both a console and a raylib GUI version.

## Dependencies (Ubuntu)

```bash
sudo apt install build-essential cmake pkg-config \
  libwayland-dev wayland-protocols libxkbcommon-dev libegl1-mesa-dev
```

Raylib is fetched and built automatically by CMake (no system install needed).

## Build

```bash
cd build
cmake ..
cmake --build .
```

## Run

```bash
./tictactoe_console
./tictactoe_raylib
```
