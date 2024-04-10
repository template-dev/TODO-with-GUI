#include "headers/Window.hpp"

Window::Window(int width /* = 0 */, int height /* = 0 */, const char* title /* = "" */)
  : m_window(nullptr)
  , m_width(width)
  , m_height(height)
  , m_title(title)
  , m_show_demo(true)
  , m_glsl_version("#version 330")
  , m_fps(0.0)
  , m_ui(std::make_unique<UserInterface>(this))
{}

void Window::onInit()
{
  glfwSetErrorCallback(glfw_error_callback);
  if (!glfwInit())
    return;

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

  m_window = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);
  if (!m_window)
    return;

  glfwMakeContextCurrent(m_window);
  glfwSwapInterval(1);

  m_ui->onInit();
}

void Window::onRender()
{
  ImVec4 clear_color = ImVec4(1.0f, 1.0f, 1.0f, 1.00f);
  while (!glfwWindowShouldClose(m_window))
  {
    m_frameStart = std::chrono::high_resolution_clock::now();
    glfwPollEvents();

    //ImGui
    m_ui->onRender();

    glfwGetFramebufferSize(m_window, &m_width, &m_height);
    glViewport(0, 0, m_width, m_height);
    glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(m_window);

    m_frameEnd = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> frameDuration = m_frameEnd - m_frameStart;
    m_fps = 1000.0 / frameDuration.count();
  }
}

void Window::onDestroy()
{
  m_ui->onDestroy();
  glfwDestroyWindow(m_window);
  glfwTerminate();
}

Window::~Window()
{
  onDestroy();
}
