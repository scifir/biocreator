#ifndef DNA_EDITOR_UI_WINDOWS_TOOLS_BAR_HPP_INCLUDED
#define DNA_EDITOR_UI_WINDOWS_TOOLS_BAR_HPP_INCLUDED

#include "wx/frame.h"
#include "wx/toolbar.h"

using namespace std;

namespace biocreator
{
	class tools_bar : public wxToolBar
	{
		public:
			tools_bar();
			tools_bar(wxWindow*,wxWindowID);
	};
}

#endif // DNA_EDITOR_UI_WINDOWS_TOOLS_BAR_HPP_INCLUDED
