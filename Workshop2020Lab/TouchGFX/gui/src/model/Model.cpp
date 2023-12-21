#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <stdint.h>

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
}

void Model::setScanJunctionTemp(bool scanEnabled)
{
    scanJunctionTemp = scanEnabled;
}

extern "C" {
	extern uint32_t TEMP_SENSOR_GetValue(void);
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
