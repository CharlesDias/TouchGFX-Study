#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>
#include <touchgfx/Texts.hpp>

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void setJunctionTempValue(int value);
    void setLanguage(LanguageId lang);
protected:
    int lastTempValue;
    LanguageId currentLang;
};

#endif // SCREEN1VIEW_HPP
