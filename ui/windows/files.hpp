#ifndef DNA_EDITOR_UI_WINDOWS_FILES_HPP
#define DNA_EDITOR_UI_WINDOWS_FILES_HPP

#include <string>

#include "wx/treectrl.h"

#include "scifir/biology.hpp"

using namespace std;

namespace biocreator
{
	class main_frame;

	class files_window : public wxTreeCtrl
	{
		public:
			files_window();
			files_window(main_frame*,wxWindowID);

			void add_file(const string&);
			void add_chromosome(const scifir::chromosome& x_chromosome);
			void add_gene();

			main_frame* mainFrame;

		private:
			wxTreeItemId root_id;
	};
}

#endif // DNA_EDITOR_UI_WINDOWS_FILES_HPP
