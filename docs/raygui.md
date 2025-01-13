# RayGUI Documentation

RayGUI is a simple and easy-to-use immediate-mode GUI library based on raylib. Version 4.5-dev.

## Features

- Immediate-mode GUI with minimal retained data
- 25+ controls (basic and advanced)
- Styling system for colors, font and metrics
- Built-in 1-bit icons pack
- Standalone mode option (custom input/graphics backend)
- Multiple support tools

## Controls

### Container/Separators
- WindowBox (includes StatusBar, Panel)
- GroupBox (includes Line)
- Line
- Panel (includes StatusBar)
- ScrollPanel (includes StatusBar)
- TabBar (includes Button)

### Basic Controls
- Label
- LabelButton
- Button
- Toggle
- ToggleGroup
- ToggleSlider
- CheckBox
- ComboBox
- DropdownBox
- TextBox
- ValueBox
- Spinner
- Slider
- SliderBar
- ProgressBar
- StatusBar
- DummyRec
- Grid

### Advanced Controls
- ListView
- ColorPicker
- MessageBox
- TextInputBox

## Style System

RayGUI uses a global style system with the following characteristics:

- Global data array for all GUI style properties
- Default style can be recovered with `GuiLoadStyleDefault()`
- Style size: 1.5 KB (384*4 bytes)
- Base properties (indices 0-15) apply to all controls
- Extended properties (indices 16-23) are common to all controls

## Icons System

- Global array containing icons data
- Each icon is 16x16 pixels, 1 bit per pixel
- Total size: 8 KB (256 icons)
- Custom icons can be loaded using `GuiLoadIcons()`

## Configuration Options

```c
#define RAYGUI_IMPLEMENTATION // Generate implementation
#define RAYGUI_STANDALONE // Avoid raylib.h dependency
#define RAYGUI_NO_ICONS // Exclude embedded icons
#define RAYGUI_CUSTOM_ICONS // Use custom icons
#define RAYGUI_DEBUG_RECS_BOUNDS // Debug rectangle bounds
#define RAYGUI_DEBUG_TEXT_BOUNDS // Debug text bounds
```

## Dependencies

- Raylib 5.0 (unless using standalone mode)
  - Required for input reading
  - Shape drawing
  - Font loading
  - Text drawing

## Standalone Mode

When using standalone mode (`RAYGUI_STANDALONE`), the following functions must be implemented:

### Input Functions

```c
Vector2 GetMousePosition(void);
float GetMouseWheelMove(void);
bool IsMouseButtonDown(int button);
bool IsMouseButtonPressed(int button);
bool IsMouseButtonReleased(int button);
bool IsKeyDown(int key);
bool IsKeyPressed(int key);
int GetCharPressed(void);
```

### Drawing Functions

```c
void DrawRectangle(int x, int y, int width, int height, Color color);
void DrawRectangleGradientEx(Rectangle rec, Color col1, Color col2, Color col3, Color col4);
```

### Resource Management

```c
Font GetFontDefault(void);
Font LoadFontEx(const char fileName, int fontSize, int codepoints, int codepointCount);
Texture2D LoadTextureFromImage(Image image);
```
