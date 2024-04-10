#ifndef A6F934DB_4D4D_4DB4_AFF0_B53D24CE1A57
#define A6F934DB_4D4D_4DB4_AFF0_B53D24CE1A57

#include "interfaces/IWindow.hpp"

class Window : public IWindow
{
public:
  Window();
  void onInit() override;
  void onRender() override;
  void ononDestroy() override;
  ~Window();
private:

};

#endif /* A6F934DB_4D4D_4DB4_AFF0_B53D24CE1A57 */
