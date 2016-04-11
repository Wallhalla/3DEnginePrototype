#include "WindowCallbacks.h"


void CG::OnWindowResize(
	GLFWwindow* resizedWindow, 
	GLsizei newWidth, 
	GLsizei newHeight)
{

	glViewport(0, 0, newWidth, newHeight);
}