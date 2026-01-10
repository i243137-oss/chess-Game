# Chess Game

A simple chess game project using SFML 2.5.1 (C++). This release includes a graphical menu, button hover effects, and basic board rendering.

## Features
- Main menu with New Game, Options, Exit buttons
- Button hover and keyboard navigation
- SFML-based graphics
- Resource management for textures and fonts
- Screen switching between menu and board
- Optimized resource loading

## Requirements
- C++ compiler (g++, MinGW, etc.)
- SFML 2.5.1 is already included in this project (see `include/` and `lib/` folders)

## SFML 2.5.1 Setup
No separate download required! The `include` and `lib` folders for SFML 2.5.1 are already part of this repository. All necessary headers and libraries are ready to use.

## Build and Run
Open a terminal in your project folder and run:
```
g++ src/main.cpp -Iinclude -Llib -lsfml-graphics -lsfml-window -lsfml-system -o build\app.exe
```
- `-Iinclude` tells g++ where to find SFML headers.
- `-Llib` tells g++ where to find SFML libraries.
- `-lsfml-graphics -lsfml-window -lsfml-system` links the required SFML modules.
- `-o build\app.exe` sets the output executable.

Then run the game:
```
build\app.exe
```

## Notes
- Make sure your assets (images, fonts) are in the correct folders as referenced in the code.
- For more details, see [RELEASE_NOTES_v1.0.0.md](RELEASE_NOTES_v1.0.0.md).

## License
MIT