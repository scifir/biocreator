#include "ui/menu_bar.hpp"

using namespace std;

namespace biocreator
{
	//wxBEGIN_EVENT_TABLE(menu_bar, wxFrame)
		//EVT_MENU(id::ID_New, menu_bar::OnHello)
		//T_MENU(wxID_EXIT, menu_bar::OnExit)
		//EVT_MENU(wxID_ABOUT, menu_bar::OnAbout)
		//EVT_TREE_ITEM_MENU(ID_DNA_list, menu_bar::OnTreeItemMenu)
		//EVT_MENU(id::MenuItemID, menu_bar::OnMenuItem)
	//wxEND_EVENT_TABLE()

	menu_bar::menu_bar() : wxMenuBar()
	{
		wxMenu *fileMenu = new wxMenu;
        fileMenu->Append(wxID_ANY, "&New");
		fileMenu->Append(wxID_ANY, "&Reopen in edition mode");
		fileMenu->Append(wxID_ANY, "&Save gene");
		fileMenu->Append(wxID_ANY, "&Save all");
		fileMenu->AppendSeparator();
        fileMenu->Append(wxID_ANY, "&Open DNA");
        fileMenu->Append(wxID_ANY, "&Open DNA from network");
		fileMenu->Append(wxID_ANY, "&Open genes collection");
		fileMenu->Append(wxID_ANY, "&Open genes collection from network");
		fileMenu->Append(wxID_ANY, "&Recent");
		fileMenu->Append(wxID_ANY, "&Recent folders");
		fileMenu->Append(wxID_ANY, "&Close project");
        fileMenu->AppendSeparator();
        fileMenu->Append(wxID_ANY, "&Explanation");
        fileMenu->Append(wxID_ANY, "&Settings");
		fileMenu->Append(wxID_ANY, "&Export");
        fileMenu->AppendSeparator();
        fileMenu->Append(wxID_EXIT, "&Quit");

        wxMenu *editMenu = new wxMenu;
        editMenu->Append(wxID_ANY, "&Undo");
        editMenu->Append(wxID_ANY, "&Redo");
        editMenu->AppendSeparator();
        editMenu->Append(wxID_ANY, "&Add gene");
        editMenu->Append(wxID_ANY, "&Edit gene");
        editMenu->AppendSeparator();
        editMenu->Append(wxID_ANY, "&Add chromosome");
        editMenu->Append(wxID_ANY, "&Edit chromosome");
		editMenu->AppendSeparator();
        editMenu->Append(wxID_ANY, "&Copy");
		editMenu->Append(wxID_ANY, "&Paste");
		editMenu->AppendSeparator();
		editMenu->Append(wxID_ANY, "&Search");
		editMenu->AppendSeparator();
		editMenu->Append(wxID_ANY, "&Restore essential genes");
		editMenu->Append(wxID_ANY, "&Restore non-essential genes");
		editMenu->Append(wxID_ANY, "&Restore original gene");

		wxMenu *incubateMenu = new wxMenu;
		incubateMenu->Append(wxID_ANY, "&Analyze factibility");
		incubateMenu->AppendSeparator();
		incubateMenu->Append(wxID_ANY, "&Incubate");
		incubateMenu->Append(wxID_ANY, "&Open DNA synthetizer");
		incubateMenu->Append(wxID_ANY, "&Open DNA debugger");

		wxMenu *toolsMenu = new wxMenu;
		toolsMenu->Append(wxID_ANY, "&Modifications history");
		toolsMenu->Append(wxID_ANY, "&Summary of genetic expression");
		toolsMenu->AppendSeparator();
		toolsMenu->Append(wxID_ANY, "&Incubations diary");
		toolsMenu->Append(wxID_ANY, "&Genes collections");
		toolsMenu->Append(wxID_ANY, "&DNA comparer");
		toolsMenu->Append(wxID_ANY, "&Genes comparer");
		toolsMenu->Append(wxID_ANY, "&DNA mixer");
		toolsMenu->Append(wxID_ANY, "&Develoment diaries");
		
		wxMenu *resourcesMenu = new wxMenu;
		resourcesMenu->Append(wxID_ANY, "&GenHub");
		resourcesMenu->Append(wxID_ANY, "&Uniprot");
		resourcesMenu->Append(wxID_ANY, "&PDB");
		resourcesMenu->Append(wxID_ANY, "&PubChem");
		
		wxMenu *windowsMenu = new wxMenu;
		windowsMenu->Append(wxID_ANY, "&Open window");
		windowsMenu->Append(wxID_ANY, "&Close window");
		windowsMenu->AppendSeparator();
		windowsMenu->Append(wxID_ANY, "&This window");
		
		wxMenu *helpMenu = new wxMenu;
		helpMenu->Append(wxID_ANY, "&Manual");
		helpMenu->Append(wxID_ANY, "&Genes encyclopedia");
		helpMenu->AppendSeparator();
		helpMenu->Append(wxID_ANY, "&Search updates");
		helpMenu->Append(wxID_ANY, "&About the Bioeditor");

        /*wxMenu *menuHelp = new wxMenu;
        menuHelp->Append(wxID_ABOUT);*/

        //wxColour menu_bar_color2 = wxColour(255, 255, 255);
        //menuBar->SetTextColour(menu_bar_color2);
        this->Append(fileMenu, "&File");
        this->Append(editMenu, "&Edit");
		this->Append(incubateMenu, "&Incubate");
		this->Append(toolsMenu, "&Tools");
		this->Append(resourcesMenu, "&Resources");
		this->Append(windowsMenu, "&Windows");
		this->Append(helpMenu, "&Help");
	}

	void menu_bar::OnExit(wxCommandEvent& event)
	{
		Close(true);
	}

	void menu_bar::OnAbout(wxCommandEvent& event)
	{
		//wxMessageBox("This is a wxWidgets' Hello world sample", "About Hello World", wxOK | wxICON_INFORMATION);
	}

	void menu_bar::OnHello(wxCommandEvent& event)
	{
		//wxLogMessage("Hello world from wxWidgets!");
	}
}
