#include "headers/Window.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
  std::unique_ptr<Window> window = std::make_unique<Window>(800, 800, "Todo");
  window->onInit();
  window->onRender();

  return 0;
}
