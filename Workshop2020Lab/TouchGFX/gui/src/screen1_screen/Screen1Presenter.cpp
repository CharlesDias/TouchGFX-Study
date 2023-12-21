#include <gui/screen1_screen/Screen1View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>
#include <touchgfx/Texts.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Screen1Presenter::Screen1Presenter(Screen1View& v)
    : view(v)
{

}

void Screen1Presenter::activate()
{
    model->setScanJunctionTemp(true);
}

void Screen1Presenter::deactivate()
{

}

void Screen1Presenter::newJunctionTempValue(int value)
{
    view.setJunctionTempValue(value);
}

void Screen1Presenter::toggleLanguage()
{
    LanguageId currentLanguage = Texts::getLanguage();
    if (currentLanguage == (LANGUAGES::NUMBER_OF_LANGUAGES - 1))
    {
        view.setLanguage(0);
    }
    else
    {
        view.setLanguage(currentLanguage + 1);
    }
}