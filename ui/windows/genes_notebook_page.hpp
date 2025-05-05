#ifndef BIOCREATOR_UI_WINDOWS_GENES_NOTEBOOK_PAGE_HPP_INCLUDED
#define BIOCREATOR_UI_WINDOWS_GENES_NOTEBOOK_PAGE_HPP_INCLUDED

#include "wx/window.h"
#include "wx/notebook.h"

#include "scifir/biology.hpp"

using namespace std;

namespace biocreator
{
	class genes_notebook_page : public wxNotebookPage
	{
		public:
			genes_notebook_page(wxWindow *parent, wxWindowID id,const scifir::gene& x_gene);
	};
}

#endif // BIOCREATOR_UI_WINDOWS_GENES_NOTEBOOK_PAGE_HPP_INCLUDED
