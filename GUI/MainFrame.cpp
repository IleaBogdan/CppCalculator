#include "MainFrame.h"

MainFrame::MainFrame(const wxString& title): 
	wxFrame(nullptr, wxID_ANY, title){
	
	// controls:

	// we need to add all controls in a panel
	// if not we will have all of them spreading on the screen randomly
	wxPanel* panel = new wxPanel(this);
	wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(150, 50), wxSize(100, 35));
	wxCheckBox* chbox = new wxCheckBox(panel, wxID_ANY, "CheckBox", wxPoint(550, 50));
}