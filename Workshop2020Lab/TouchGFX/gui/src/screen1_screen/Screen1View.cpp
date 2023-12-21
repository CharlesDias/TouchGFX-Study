#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View()
    : lastTempValue(0)
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::setJunctionTempValue(int value)
{
	if (lastTempValue != value)
	{
		lastTempValue = value;
		temperatureBar.setValue(value);
		temperatureBar.invalidate();
	}
}