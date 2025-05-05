#include "./gene_info_collection_data_source_example.hpp"

using namespace std;

namespace biocreator
{
	gene_info_collection_data_source_example::gene_info_collection_data_source_example()
	{}

	string gene_info_collection_data_source_example::get_description(const string& gene_name) const
	{
		if (gene_name == "gene-1")
		{
			return "Example of description";
		}
		else if (gene_name == "gene-2")
		{
			return "Genes of example number 1";
		}
		else
		{
			return "Another description more";
		}
	}

	string gene_info_collection_data_source_example::get_chromosome_name(const string& gene_name) const
	{
		return "chromosome 1";
	}

	string gene_info_collection_data_source_example::get_species(const string& gene_name) const
	{
		return "phodopus-roborovskii";
	}

	string gene_info_collection_data_source_example::get_category(const string& gene_name) const
	{
		return "example-category";
	}

	vector<string> gene_info_collection_data_source_example::get_alleles(const string& gene_name) const
	{
		return vector<string>({"allele-1","allele-2"});
	}
}