#ifndef GLFW_WRAPPER_H
#define GLFW_WRAPPER_H

#include "raylib.h"

#ifndef PLATFORM_WEB
#include <GLFW/glfw3.h>
// GLFW functions only for desktop
void SetupWindow(void);
void CleanupWindow(void);
// ... other GLFW functions
#else
// Web stubs - do nothing
#define SetupWindow() ((void)0)
#define CleanupWindow() ((void)0)
#define glfwSetWindowContentScaleCallback(window, callback) ((void)0)
#define glfwSetWindowAttrib(window, attrib, value) ((void)0)
// ... other stubs
#endif

#endif // GLFW_WRAPPER_H