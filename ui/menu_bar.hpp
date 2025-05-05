#ifndef DNA_EDITOR_UI_MENU_BAR_HPP_INCLUDED
#define DNA_EDITOR_UI_MENU_BAR_HPP_INCLUDED

#include "wx/frame.h"
#include "wx/menu.h"

#include "wx/listctrl.h"
#include "wx/panel.h"
#include "wx/toolbar.h"
#include "wx/treectrl.h"

using namespace std;

namespace biocreator
{
	class menu_bar : public wxMenuBar
	{
		public:
			menu_bar();

		private:
			void OnHello(wxCommandEvent&);
			void OnExit(wxCommandEvent&);
			void OnAbout(wxCommandEvent&);
			//wxDECLARE_EVENT_TABLE();
	};
}

#endif // DNA_EDITOR_UI_MENU_BAR_HPP_INCLUDED
