#include "ui/windows/files.hpp"

#include "../main_frame.hpp"

//#include "scifir/biology.hpp"

using namespace std;

namespace biocreator
{
	files_window::files_window() : wxTreeCtrl()
	{}

	files_window::files_window(main_frame* new_parent,wxWindowID new_id) : wxTreeCtrl(new_parent,new_id,wxDefaultPosition, wxSize(200,200))
	{
		root_id = this->AddRoot("Zipper");
	}

	void files_window::add_file(const string& filename)
	{
		/*wxTreeItemId chromosome1 = this->AppendItem(root_id, "chromosome 1 (3 genes)");
		wxTreeItemId child_id1 = this->AppendItem(chromosome1, "gene-1 (33 bases)");
		wxTreeItemId child_id2 = this->AppendItem(chromosome1, "gene-2 (198 bases)");
		wxTreeItemId child_id3 = this->AppendItem(chromosome1, "gene-3 (102 bases)");*/

		//msci::dna dna_a(filename);
		//for (const auto& x_chromosome : dna_a.get_chromosomes())
		//{
		//	wxTreeItemId chromosome_item_id = this->AppendItem(child_id, "Chromosome " + x_chromosome.first);
		//}
	}

	void files_window::add_chromosome(const scifir::chromosome& x_chromosome)
	{
		wxTreeItemId chromosome1 = this->AppendItem(root_id, x_chromosome.get_name() + " (" + to_string(x_chromosome.number_of_genes()) + " genes)");
		for(const auto& x_gene : x_chromosome.get_genes())
		{
			this->AppendItem(chromosome1, x_gene.second.name + " (" + to_string(x_gene.second.get_bases().size()) + " bases)");
		}
	}
}
