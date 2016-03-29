#include "Window.h"

#include "../Callbacks/WindowCallbacks.h"

#include <iostream>

using namespace CG;

Window::Window(const char* inTitle, GLsizei inWidth, GLsizei inHeight)
{
	if (!CreateWindowInstance(inTitle, inWidth, inHeight))
	{
		std::cout << "Failed to create window!" << std::endl;
	}

	if (!InitGLEW())
	{
		std::cout << "Failed to initialize GLEW!" << std::endl;
	}

	glClearColor(0.0f,0.0f,0.0f,1.0f);

	SetWindowCallbacks();

}

Window::~Window()
{
	// Clean up GLFW -> this will also destroy the windowInstancepointer stored in this class
	glfwTerminate();
}

bool Window::CreateWindowInstance(const char* inTitle, GLsizei inWidth, GLsizei inHeight)
{
	bool wasSuccessful = false;

	if (glfwInit() == GL_TRUE)
	{
		windowInstance = glfwCreateWindow(inWidth, inHeight, inTitle, NULL, NULL);

		if (!windowInstance)
		{
			glfwTerminate();
			return wasSuccessful;
		}

		glfwMakeContextCurrent(windowInstance);
		wasSuccessful = true;
	}

	return wasSuccessful;
}

bool Window::InitGLEW()
{
	bool wasSuccessful = false;

	if (glewInit() == GL_NO_ERROR)
	{
		std::cout << glGetString(GL_VERSION) << std::endl;
		wasSuccessful = true;
	}

	return wasSuccessful;
}

void Window::SetWindowCallbacks()
{
	glfwSetWindowSizeCallback(windowInstance, OnWindowResize);
}

void Window::Update()
{
	glfwPollEvents();
		glfwSwapBuffers(windowInstance);
}

void Window::Clear() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

bool Window::WasWindowClosed() const
{
	return glfwWindowShouldClose(windowInstance) == GL_TRUE;
}
