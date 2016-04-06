#pragma once
#include "GL/glew.h"
#include "GLFW/glfw3.h"


namespace CG
{
	class Window
	{
	private:
		GLFWwindow* windowInstance;

	public:
		Window(const char* inTitle, GLsizei inWidth, GLsizei inHeight);
		~Window();

	private:
		bool CreateWindowInstance(const char* inTitle, GLsizei inWidth, GLsizei inHeight);
		bool InitGLEW();

		void SetWindowCallbacks();
	public:
		// Updates the renderscene of the windowinstance
		void Update();

		// Clears the window with the specified clear color from glClearColor(color)
		void Clear() const;

		// Returns true if the window closed flag was set (Something closed the window)
		bool WasWindowClosed() const;

	};
}