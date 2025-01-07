#include "MainFrame.h"
#include <vector>
#include <string>
#include <iostream>


// macros - think this is how they are called
#define ALLOW_KEYS() panel->SetFocus()
#define SOLVE_OPERATION() calcText->SetLabelText(backendCalcuation(calcText->GetLabelText()))

wxString backendCalcuation(const wxString& s) {
	return wxString(calculate(std::string(s)));
}

MainFrame::MainFrame(const wxString& title): 
	wxFrame(nullptr, wxID_ANY, title){

	wxStatusBar* statusBar=CreateStatusBar();
	statusBar->SetDoubleBuffered(true);

	panel = new wxPanel(this);
	panel->SetFocus();
	panel->SetBackgroundColour(
		// wxColor gets rgb params
		wxColor(69, 69, 69)
	);
	panel->Bind(wxEVT_KEY_DOWN, &MainFrame::OnKeyEvent, this);


	wxPanel* numpad_panel = new wxPanel(panel, wxID_ANY, wxPoint(3, 100), wxSize(350, 450));
	//numpad_panel->SetBackgroundColour(wxColor(0, 0, 0));
	numpad_panel->Bind(wxEVT_BUTTON, &MainFrame::OnNumpadButtonClick, this);
	std::vector<wxButton*> numpad=init_numpad(numpad_panel);
	calcText = new wxTextCtrl(panel, wxID_ANY, 
		*default_text.begin(), wxPoint(18, 50), wxSize(200, -1));
	
	// somithing is fucked when I bind this and stopes the numpad buttons
	//calcText->Bind(wxEVT_TEXT, &MainFrame::OnTextChange, this);
}
void MainFrame::OnKeyEvent(wxKeyEvent& e) {
	char key = e.GetUnicodeKey();
	if (key == WXK_NONE) {
		int keyCode = e.GetKeyCode();
		
	} else {
		if (key == '=') {
			SOLVE_OPERATION();
		}
		if (keys.count(key)) {
			wxLogStatus(wxString{ key });
			if (default_text.count(calcText->GetLabelText())) {
				calcText->SetLabelText("");
			}
			calcText->SetLabelText(calcText->GetLabelText() + "" + key);
		}
	}
}
void MainFrame::OnTextChange(wxCommandEvent& e){
	wxLogStatus(calcText->GetLabelText());
	if (calcText->GetLabelText() != "") {
		if (calcText->GetLabelText().Last() == '=') {
			//std::cout << backendCalcuation(calcText->GetLabelText());
			SOLVE_OPERATION();
			return;
		}
	}
	ALLOW_KEYS();
}
void MainFrame::OnNumpadButtonClick(wxCommandEvent& e) {
	char localid = char(e.GetId());
	wxLogStatus(wxString{localid});
	switch (localid) {
	case '=':
		//std::cout << backendCalcuation(calcText->GetLabelText());
		SOLVE_OPERATION();
		break;
	case 'C':
		calcText->SetLabelText("");
		break;
	default:
		if (default_text.count(calcText->GetLabelText())) {
			calcText->SetLabelText("");
		}
		calcText->SetLabelText(calcText->GetLabelText() + "" + localid);
		// I need a string that can take all the 
		// numbers and signs and the send them to the backend
		break;
	}
	//e.Skip();
	ALLOW_KEYS();
}