#include "MainFrame.h"
#include <vector>
#include <string>

MainFrame::MainFrame(const wxString& title): 
	wxFrame(nullptr, wxID_ANY, title){
	
	// controls:

	wxPanel* panel = new wxPanel(this);
	panel->SetBackgroundColour(
		// wxColor gets rgb params
		wxColor(69, 69, 69)
	);
	std::vector<wxButton*> numpad=init_numpad(panel);
}