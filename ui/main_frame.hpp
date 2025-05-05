#ifndef DNAEDITOR_UI_MAIN_WINDOW_HPP_INCLUDED
#define DNAEDITOR_UI_MAIN_WINDOW_HPP_INCLUDED

#include <string>

#include "wx/frame.h"
#include "wx/listctrl.h"
#include "wx/panel.h"
#include "wx/toolbar.h"
#include "wx/treectrl.h"
#include "wx/colour.h"

#include "scifir/biology.hpp"

#include "./windows/files.hpp"
#include "./windows/genes_notebook.hpp"
#include "./windows/tools_bar.hpp"
#include "./menu_bar.hpp"

using namespace std;

namespace biocreator
{
	enum class id
	{
		ID_New = 1,
		ID_Open,
		ID_Recent,
		ID_Save,
		ID_SaveAll,
		ID_Close,
		ID_CloseAll,
		ID_Explanation,
		ID_Settings,
		ID_Undo,
		ID_Redo,
		ID_Add_Gene,
		ID_Edit_Gene,
		ID_Add_Chromosome,
		ID_Edit_Chromosome,
		ID_DNA_list,
		MenuItemID
	};

	extern wxColour background_colour;
	extern wxColour dark_background_colour;
	extern wxColour dark_selection_background_colour;
	extern wxColour active_line_background_colour;
	extern wxColour text_colour;

	extern scifir::genome opened_genome;
	extern scifir::gene_info_collection gene_info_collection;

	class main_frame: public wxFrame
	{
		public:
			main_frame(const string&, const wxString&, const wxPoint&, const wxSize&, long);

			menu_bar* menuBar;
			tools_bar* toolBar;
			files_window* treeCtrl;
			genes_notebook* genesNotebook;

		private:
			void OnTreeItemMenu(wxTreeEvent&);
			void OnMenuItem(wxCommandEvent&);
	};
}

#endif // DNAEDITOR_UI_MAIN_WINDOW_HPP_INCLUDED
