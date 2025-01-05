#include "MainFrame.h"
#include <vector>
#include <string>
#include <iostream>

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
		//std::cout << numpadelem->GetId() << std::endl;
		numpadelem->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClick, this);
	}
}

void MainFrame::OnButtonClick(wxCommandEvent& e) {
	int localid = e.GetId();
	char localid_value = char(localid);
	wxLogStatus(wxString{localid_value});
	if (localid_value == '=') {
		std::cout << "TO DO: call the backend here\n";
	}
	
}