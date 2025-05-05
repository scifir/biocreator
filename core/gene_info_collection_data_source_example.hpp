#ifndef BIOCREATOR_CORE_GENE_INFO_COLLECTION_DATA_SOURCE_EXAMPLE_HPP_INCLUDED
#define BIOCREATOR_CORE_GENE_INFO_COLLECTION_DATA_SOURCE_EXAMPLE_HPP_INCLUDED

#include <string>
#include <vector>

#include "scifir/biology.hpp"

using namespace std;

namespace biocreator
{
	class gene_info_collection_data_source_example : public scifir::gene_info_collection_data_source
	{
		public:
			gene_info_collection_data_source_example();

			string get_description(const string& gene_name) const;
			string get_chromosome_name(const string& gene_name) const;
			string get_species(const string& gene_name) const;
			string get_category(const string& gene_name) const;
			vector<string> get_alleles(const string& gene_name) const;
	};
}

#endif // BIOCREATOR_CORE_GENE_INFO_COLLECTION_DATA_SOURCE_EXAMPLE_HPP_INCLUDED
