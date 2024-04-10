#ifndef A6F934DB_4D4D_4DB4_AFF0_B53D24CE1A57
#define A6F934DB_4D4D_4DB4_AFF0_B53D24CE1A57

#include "interfaces/IWindow.hpp"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <GLFW/glfw3.h>
#include <memory>
#include <chrono>

class Window : public IWindow
{
public:
  Window(int width = 0, int height = 0, const char* title = "");

  void onInit()     override;
  void onRender()   override;
  void onDestroy()  override;

  ~Window();

private:
  static void glfw_error_callback(int error, const char* description)
	{
		fprintf(stderr, "GLFW Error %d: %s\n", error, description);
	}

private:
  GLFWwindow* m_window;
	int         m_width;
	int         m_height;
	const char* m_title;
	bool        m_show_demo;
	const char* m_glsl_version;
	double      m_fps;
	std::chrono::high_resolution_clock::time_point m_frameStart;
	std::chrono::high_resolution_clock::time_point m_frameEnd;
};

#endif /* A6F934DB_4D4D_4DB4_AFF0_B53D24CE1A57 */
