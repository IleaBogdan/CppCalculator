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
	char localid = char(e.GetId());
	wxLogStatus(wxString{localid});
	switch (localid) {
	case '=':
		std::cout << "TO DO: call the backend here\n";
		break;
	default:
		// I need a string that can take all the 
		// numbers and signs and the send them to the backend
		break;
	}
	
}