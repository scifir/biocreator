#include "./main_frame.hpp"

#include "./app.hpp"

#include <sstream>

#include "scifir/biology.hpp"

#include "../core/gene_info_collection_data_source_example.hpp"

using namespace std;

namespace biocreator
{
    wxColour background_colour = wxColour(0, 168, 104);
    wxColour dark_background_colour = wxColour(1, 105, 65);
    wxColour dark_selection_background_colour = wxColour(1, 120, 74);
    wxColour active_line_background_colour = wxColour(1, 145, 90);
	wxColour text_colour = wxColour(255, 255, 255);

    scifir::genome opened_genome = scifir::genome();
    scifir::gene_info_collection gene_info_collection = scifir::gene_info_collection({ shared_ptr<scifir::gene_info_collection_data_source>(new gene_info_collection_data_source_example()) });

	main_frame::main_frame(const string& open_file,const wxString& title, const wxPoint& pos, const wxSize& size, long new_style)
		: wxFrame(NULL, wxID_ANY, title, pos, size, new_style)
	{
        SetBackgroundColour(background_colour);
        wxIcon bitmap("ui/images/icon.png");
        SetIcon(bitmap);

        scifir::chromosome chromosome1 = scifir::chromosome("chromosome 1",{{ "gene-1",scifir::gene("gene-1","TACGTAATC") },
            { "gene-2",scifir::gene("gene-2","TACGTAGCCAAT") },
            { "gene-3",scifir::gene("gene-3","TACGTATAGATA") },
            { "gene-4",scifir::gene("gene-4","TACGAAATTGAA") }});
        opened_genome.add_chromosome(chromosome1);

		toolBar = new tools_bar(this,wxID_ANY);

		genesNotebook = new genes_notebook(this,wxID_ANY);
        genesNotebook->SetBackgroundColour(background_colour);
        genesNotebook->SetForegroundColour(text_colour);
        scifir::gene x_gene = scifir::gene("gene1","TACTCGATCGAT");
        genesNotebook->open_gene(x_gene);

		menuBar = new menu_bar();

        SetMenuBar(menuBar);

        wxFrame::Bind(wxEVT_MENU, [this](wxCommandEvent& event) {
            Close(true);
        }, wxID_EXIT);

        SetToolBar(toolBar);

        treeCtrl = new files_window(this,wxID_ANY);
        treeCtrl->SetBackgroundColour(background_colour);
        treeCtrl->SetForegroundColour(text_colour);
		treeCtrl->add_file("dna_example");
        treeCtrl->add_chromosome(opened_genome["chromosome 1"]);
		treeCtrl->ExpandAll();

        treeCtrl->Bind(wxEVT_TREE_ITEM_ACTIVATED, [this](wxTreeEvent& event) {
//            wxLogMessage(wxString(treeCtrl->GetItemText(event.GetItem())));
            wxString node_name = treeCtrl->GetItemText(event.GetItem());
            wxString gene_name = node_name.SubString(0,node_name.Find(" (") - 1);
            genesNotebook->open_gene(opened_genome["chromosome 1"][gene_name.utf8_string()]);
        });

    	wxBoxSizer* main_frame_sizer = new wxBoxSizer(wxVERTICAL);

		wxBoxSizer* horizontal_sizer = new wxBoxSizer(wxHORIZONTAL);
		horizontal_sizer->Add(treeCtrl,1);
		horizontal_sizer->Add(genesNotebook,2,wxEXPAND);

		main_frame_sizer->Add(horizontal_sizer,1,wxEXPAND);

		SetSizer(main_frame_sizer);
	}

	void main_frame::OnTreeItemMenu(wxTreeEvent& evt)
    {
        // This event handler creates a new menu and displays
        // it as a popup menu with the wxWindow::PopupMenu function

        wxMenu menu;
        menu.Append(wxID_ANY, "Copy gene");
        menu.Append(wxID_ANY, "Paste gene");

        // We need to pass some data (the text of the node) to
        // the menu event handler. We create a class that holds
        // the needed data and use the Connect function to
        // associate our event handler with the menu.
    // UserData* userData = new UserData();
        //userData->m_data = m_treeCtrl->GetItemText(evt.GetItem());
        //menu.Connect(MenuItemID, wxEVT_MENU,
            //(wxObjectEventFunction)&WxTreeCtrl3Frame::OnMenuItem,
        //userData, this);

        // Display the menu as a popup menu
        PopupMenu(&menu);

        evt.Skip();
    }

    void main_frame::OnMenuItem(wxCommandEvent& evt)
    {
        // Display a message with the text of the node
        // the user right-clicked on
        //UserData* userData = dynamic_cast<UserData*>(evt.GetEventUserData());
        //if (userData)
        //{
            wxMessageBox("You clicked on the item");
        //}
    }
}
