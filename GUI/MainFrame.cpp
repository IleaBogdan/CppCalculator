#include "MainFrame.h"
#include <vector>
#include <string>
#include <iostream>


wxString backendCalcuation(const wxString& s) {
	return wxString(calculate(std::string(s)));
}

MainFrame::MainFrame(const wxString& title): 
	wxFrame(nullptr, wxID_ANY, title){

	wxStatusBar* statusBar=CreateStatusBar();
	statusBar->SetDoubleBuffered(true);

	panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxWANTS_CHARS);
	panel->SetFocus();
	panel->SetBackgroundColour(
		// wxColor gets rgb params
		wxColor(69, 69, 69)
	);
	panel->Bind(wxEVT_CHAR_HOOK, &MainFrame::OnKeyEvent, this);


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
	char keyChr = e.GetUnicodeKey();
	int keyCode=e.GetKeyCode();
	if (keyCode == WXK_TAB) {
		e.Skip();
		return;
	}
	if (keys.count(keyChr)) {
		if (default_text.count(calcText->GetLabelText())) {
			calcText->SetLabelText("");
		}
		calcText->SetLabelText(calcText->GetLabelText() + "" + keyChr);
		return;
	}
	if (keyChr == WXK_NONE) {
		switch (keyCode) {
		case WXK_END:
			//calcText->SetLabelText(backendCalcuation(calcText->GetLabelText()));
			break;
		}
		printf("Key: %d\n", keyCode);
	}
}
void MainFrame::OnTextChange(wxCommandEvent& e){
	wxLogStatus(calcText->GetLabelText());
	if (calcText->GetLabelText() != "") {
		if (calcText->GetLabelText().Last() == '=') {
			//std::cout << backendCalcuation(calcText->GetLabelText());
			calcText->SetLabelText(backendCalcuation(calcText->GetLabelText()));
			return;
		}
	}
}
void MainFrame::OnNumpadButtonClick(wxCommandEvent& e) {
	char localid = char(e.GetId());
	wxLogStatus(wxString{localid});
	switch (localid) {
	case '=':
		//std::cout << backendCalcuation(calcText->GetLabelText());
		calcText->SetLabelText(backendCalcuation(calcText->GetLabelText()));
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
}