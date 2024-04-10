#ifndef F7EC86FC_0B02_4D1C_8373_CF5EBA48AC4F
#define F7EC86FC_0B02_4D1C_8373_CF5EBA48AC4F

class IWindow
{
public:
  virtual void onInit() = 0;
  virtual void onRender() = 0;
  virtual void ononDestroy() = 0;
  virtual ~IWindow() = default;
};

#endif /* F7EC86FC_0B02_4D1C_8373_CF5EBA48AC4F */
