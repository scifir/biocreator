#include "ui/windows/tools_bar.hpp"

using namespace std;

namespace biocreator
{
	tools_bar::tools_bar() : wxToolBar()
	{
	}

	tools_bar::tools_bar(wxWindow* new_parent,wxWindowID new_id) : wxToolBar(new_parent,new_id)
	{
		wxBitmap file_bitmap("ui/images/file.png", wxBITMAP_TYPE_PNG);
		wxBitmap open_bitmap("ui/images/open.png", wxBITMAP_TYPE_PNG);
		wxBitmap save_bitmap("ui/images/save.png", wxBITMAP_TYPE_PNG);
		//wxBitmap print_bitmap("ui/images/print.png", wxBITMAP_TYPE_PNG);
		//wxBitmap pdf_bitmap("ui/images/pdf.png", wxBITMAP_TYPE_PNG);
		//wxBitmap image_bitmap("ui/images/image.png", wxBITMAP_TYPE_PNG);
		wxBitmap copy_bitmap("ui/images/copy.png", wxBITMAP_TYPE_PNG);
		wxBitmap paste_bitmap("ui/images/paste.png", wxBITMAP_TYPE_PNG);
		wxBitmap undo_bitmap("ui/images/undo.png", wxBITMAP_TYPE_PNG);
		wxBitmap redo_bitmap("ui/images/redo.png", wxBITMAP_TYPE_PNG);

		this->AddTool(wxID_ANY,wxT("New file"),file_bitmap);
		this->AddTool(wxID_ANY,wxT("Open file"),open_bitmap);
		this->AddTool(wxID_ANY,wxT("Save"),save_bitmap);
		this->InsertSeparator(3);
		//this->AddTool(wxID_ANY,wxT("Print"),print_bitmap);
		//this->AddTool(wxID_ANY,wxT("Export to PDF"),pdf_bitmap);
		//this->AddTool(wxID_ANY,wxT("Export to image"),image_bitmap);
		//this->InsertSeparator(7);
		this->AddTool(wxID_ANY,wxT("Copy"),copy_bitmap);
		this->AddTool(wxID_ANY,wxT("Paste"),paste_bitmap);
		this->InsertSeparator(6);
		this->AddTool(wxID_ANY,wxT("Undo"),undo_bitmap);
		this->AddTool(wxID_ANY,wxT("Redo"),redo_bitmap);
		this->Realize();
	}
}
