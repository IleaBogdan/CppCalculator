#include "MainFrame.h"
#include <vector>
#include <string>

MainFrame::MainFrame(const wxString& title): 
	wxFrame(nullptr, wxID_ANY, title){
	
	CreateStatusBar();

	wxPanel* panel = new wxPanel(this);
	panel->SetBackgroundColour(
		// wxColor gets rgb params
		wxColor(69, 69, 69)
	);
	std::vector<wxButton*> numpad=init_numpad(panel);
	for (auto& numpadelem : numpad) {
		numpadelem->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClick, this);
	}
}

void MainFrame::OnButtonClick(wxCommandEvent& e) {
	wxLogStatus(wxString(std::to_string(e.GetId()-2)));
}