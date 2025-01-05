#include "MainFrame.h"
#include <vector>
#include <string>

enum Numpad_IDs {
	test=2
};

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
	EVT_BUTTON(test, MainFrame::OnButtonClick)
wxEND_EVENT_TABLE();

MainFrame::MainFrame(const wxString& title): 
	wxFrame(nullptr, wxID_ANY, title){
	
	CreateStatusBar();

	wxPanel* panel = new wxPanel(this);
	panel->SetBackgroundColour(
		// wxColor gets rgb params
		wxColor(69, 69, 69)
	);
	std::vector<wxButton*> numpad=init_numpad(panel);
	numpad[0]->SetId(test);
}

void MainFrame::OnButtonClick(wxCommandEvent& e) {
	wxLogStatus("Button 1");
}