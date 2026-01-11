# Chess Game v1.0.0 Release Notes

## Features Implemented

- Main menu with three buttons: New Game, Options, Exit
- Button hover effect and keyboard navigation
- SFML-based graphical interface
- Resource management for textures and fonts
- Screen switching between main menu and game board
- Basic board rendering (Screen2)
- Optimized resource loading (no global SFML objects)
- Stable exit without crashes
## Latest Enhancements (Post v1.0.0)
- Piece movement logic: Select a piece with left click, move it with right click to a valid square.
- Enhanced hover effect: Selected piece is highlighted in green, possible moves outlined for better user experience.

## Gameplay Instructions
- Use the mouse to interact with the chessboard.
- Left click to select a piece (highlighted in green).
- Right click on a valid square to move the selected piece.
- Menu navigation is available via mouse and keyboard.


## How to Compile and Execute (SFML Included)

1. Open a terminal in your project folder.
2. Run the following command:
   ```
   g++ src/main.cpp -Iinclude -Llib -lsfml-graphics -lsfml-window -lsfml-system -o build/app.exe
   ```
   - `-Iinclude` tells g++ where to find SFML headers.
   - `-Llib` tells g++ where to find SFML libraries.
   - `-lsfml-graphics -lsfml-window -lsfml-system` links the required SFML modules.
   - `-o build/app.exe` sets the output executable.
3. Run the game:
   ```
   build/app.exe
   ```

## Usage
- Run the executable to start the chess game
- Use mouse or keyboard to navigate menu
- Press Enter or Right Mouse Button to switch to the game board

## Known Limitations
- Chess logic and gameplay not yet implemented
- Options and Exit buttons are placeholders
- No sound or advanced animations

---
This is the first stable release. More features will be added in future versions!

