#ifndef A9751520_A87E_4B82_908B_C24CA129C27E
#define A9751520_A87E_4B82_908B_C24CA129C27E

#include "interfaces/IUserInterface.hpp"
#include "Window.hpp"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <GLFW/glfw3.h>
#include <memory>

class Window;
class UserInterface : public IUserInterface
{
public:
  UserInterface(Window* window);

  void onInit()    override;
  void onRender()  override;
  void onDestroy() override;

private:
  void onDrawElements();

private:
  Window* m_window;
  ImGuiWindowFlags m_windowFlags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;

  static bool m_optFullScreen;
	static bool m_dockspaceOpen;
	static bool m_optPadding;
};

#endif /* A9751520_A87E_4B82_908B_C24CA129C27E */
