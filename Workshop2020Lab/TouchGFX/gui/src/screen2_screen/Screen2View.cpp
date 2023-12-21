#include <gui/screen2_screen/Screen2View.hpp>

Screen2View::Screen2View()
{

}

void Screen2View::setupScreen()
{
    Screen2ViewBase::setupScreen();
}

void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
}

void Screen2View::toggleSwLed()
{
	if(SwLedOn.isVisible())
	{
		SwLedOn.setVisible(false);
		SwLedOff.setVisible(true);
	}
	else
	{
		SwLedOn.setVisible(true);
		SwLedOff.setVisible(false);
	}

	SwLedOn.invalidate();
	SwLedOff.invalidate();
}
