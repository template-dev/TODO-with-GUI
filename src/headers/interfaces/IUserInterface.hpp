#ifndef BD445274_65A9_456C_BE91_E084C5E065F2
#define BD445274_65A9_456C_BE91_E084C5E065F2

class IUserInterface
{
public:
  virtual void onInit()     = 0;
  virtual void onRender()   = 0;
  virtual void onDestroy()  = 0;
  ~IUserInterface() = default;
};

#endif /* BD445274_65A9_456C_BE91_E084C5E065F2 */
