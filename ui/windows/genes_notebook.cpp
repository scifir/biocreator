#include "ui/windows/genes_notebook.hpp"

#include "./genes_notebook_page.hpp"

using namespace std;

namespace biocreator
{
	genes_notebook::genes_notebook() : wxAuiNotebook()
	{}

	genes_notebook::genes_notebook(wxWindow* new_parent,wxWindowID new_id) : wxAuiNotebook(new_parent,new_id,wxDefaultPosition, wxSize(200,200))
	{}

	void genes_notebook::open_gene(const scifir::gene& x_gene)
	{
		biocreator::genes_notebook_page* genePage = new biocreator::genes_notebook_page(this,wxID_ANY,x_gene);
		AddPage(genePage,x_gene.name,true);
	}

	void genes_notebook::open_dna_sequence()
	{}

	void genes_notebook::open_chromosome()
	{}

	void genes_notebook::open_genome()
	{}
}
