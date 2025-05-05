#include "./genes_notebook_page.hpp"

#include "../main_frame.hpp"

#include "wx/stc/stc.h"
#include "wx/sizer.h"
#include "wx/frame.h"
#include "wx/panel.h"
#include "wx/string.h"
#include "wx/stattext.h"
#include "wx/msgdlg.h"

using namespace std;

namespace biocreator
{
	genes_notebook_page::genes_notebook_page(wxWindow *parent, wxWindowID id,const scifir::gene& x_gene) : wxNotebookPage(parent,id)
	{
		//wxMessageBox("Hello");
		wxStyledTextCtrl* genes_editor = new wxStyledTextCtrl(this,wxID_ANY,wxDefaultPosition,wxSize(800,500));
		genes_editor->StyleSetBackground(wxSTC_STYLE_DEFAULT,dark_background_colour);
		genes_editor->SetCaretLineBackground(active_line_background_colour);
		genes_editor->SetSelBackground(true,dark_selection_background_colour);
		genes_editor->SetText(wxString(x_gene.get_sequence()));
		genes_editor->Bind(wxEVT_STC_CLIPBOARD_COPY, [this](wxCommandEvent& event) {
			wxMessageBox("Hello");
        });
		
		wxPanel* genes_information = new wxPanel(this,wxID_ANY,wxPoint(0,500),wxSize(800,250));
		genes_information->SetBackgroundColour(background_colour);
		wxStaticText* gene_name = new wxStaticText(genes_information,wxID_ANY,wxString(x_gene.name));
		wxFont gene_name_font = wxFont();
		gene_name_font.SetPointSize(30);
		gene_name->SetFont(gene_name_font);
		wxStaticText* gene_bases = new wxStaticText(genes_information,wxID_ANY,wxString(to_string(x_gene.get_bases().size()) + " bases, homozigote"));
		wxStaticText* gene_description = new wxStaticText(genes_information,wxID_ANY,wxString(gene_info_collection.get_description(x_gene.name)));

		wxBoxSizer* panelSizer = new wxBoxSizer(wxVERTICAL);
		panelSizer->Add(gene_name,0,wxEXPAND);
		panelSizer->Add(gene_bases,0,wxEXPAND);
    	panelSizer->Add(gene_description,1,wxEXPAND);
    	genes_information->SetSizer(panelSizer);

		wxBoxSizer* horizontal_sizer = new wxBoxSizer(wxVERTICAL);
		horizontal_sizer->Add(genes_editor,1,wxEXPAND);
		horizontal_sizer->Add(genes_information,0,wxEXPAND);
		SetSizer(horizontal_sizer);
	}
}
