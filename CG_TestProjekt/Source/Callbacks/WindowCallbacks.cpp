#include "WindowCallbacks.h"

#include <iostream>
void CG::OnWindowResize(
	GLFWwindow* resizedWindow, 
	GLsizei newWidth, 
	GLsizei newHeight)
{

	glViewport(0, 0, newWidth, newHeight);
}

void CG::OnKeyAction(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_W)
	{
		std::cout << "key pressed" << std::endl;
	}
}