#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <stdint.h>

extern "C" {
	extern uint32_t TEMP_SENSOR_GetValue(void);
	extern void TOGGLE_LED3(void);
	extern uint32_t userButtonPressed;
}

Model::Model() : modelListener(0)
    , tickCounter(0), scanJunctionTemp(false)
{

}

void Model::tick()
{
    tickCounter++;
    if (((tickCounter % 20) == 0) && (scanJunctionTemp))
    {
      if (modelListener != 0)
      {
        modelListener->newJunctionTempValue(getTempValue());
      }
    }

#ifndef SIMULATOR
	if(userButtonPressed == 1)
	{
		userButtonPressed = 0;
		modelListener->userButtonPressed();
	}
#endif /*SIMULATOR*/
}

void Model::setScanJunctionTemp(bool scanEnabled)
{
    scanJunctionTemp = scanEnabled;
}

int Model::getTempValue()
{
#ifndef SIMULATOR
	return TEMP_SENSOR_GetValue();
#else
  // Implementation for simulator
  return 25;
#endif /*SIMULATOR*/
}

void Model::toggleHwLed()
{
#ifndef SIMULATOR
	TOGGLE_LED3();
#endif /*SIMULATOR*/
}
