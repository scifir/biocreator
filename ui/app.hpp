#ifndef DNAEDITOR_UI_APP_HPP_INCLUDED
#define DNAEDITOR_UI_APP_HPP_INCLUDED

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class main_app: public wxApp
{
    public:
        virtual bool OnInit();
        virtual int OnExit();
};

wxDECLARE_APP(main_app);

#endif // DNAEDITOR_UI_APP_HPP_INCLUDED
