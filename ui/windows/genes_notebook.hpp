#ifndef GENES_NOTEBOOK_HPP_INCLUDED
#define GENES_NOTEBOOK_HPP_INCLUDED

#include "wx/aui/auibook.h"

#include "scifir/biology.hpp"

using namespace std;

namespace biocreator
{
	class genes_notebook : public wxAuiNotebook
	{
		public:
			genes_notebook();
			genes_notebook(wxWindow*, wxWindowID);

			void open_gene(const scifir::gene& x_gene);
			void open_dna_sequence();
			void open_chromosome();
			void open_genome();
	};
}

#endif // GENES_NOTEBOOK_HPP_INCLUDED
