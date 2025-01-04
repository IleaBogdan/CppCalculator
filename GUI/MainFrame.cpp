#include "MainFrame.h"

MainFrame::MainFrame(const wxString& title): 
	wxFrame(nullptr, wxID_ANY, title){
	
	// controls:

	// we need to add all controls in a panel
	// if not we will have all of them spreading on the screen randomly
	wxPanel* panel = new wxPanel(this);
	wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(150, 50), wxSize(100, 35));
	wxCheckBox* chbox = new wxCheckBox(panel, wxID_ANY, "CheckBox", wxPoint(550, 50));
	wxStaticText* stText = new wxStaticText(panel, wxID_ANY, "Static Text", wxPoint(120, 150)); // not changeble by the user
	wxTextCtrl* txtCtr = new wxTextCtrl(panel, wxID_ANY, "Text Control", wxPoint(500, 145)); // can be changed by user
	wxSlider* slider = new wxSlider(panel, wxID_ANY, 25, 0, 100, wxPoint(100, 250), wxSize(200, -1));
}