#pragma once
#include "GLFW/glfw3.h"


namespace CG
{
	void OnWindowResize(
		GLFWwindow* resizedWindow, 
		GLsizei newWidth, 
		GLsizei newHeight);

	void OnKeyAction(GLFWwindow* window, int key, int scancode, int action, int mods);
};