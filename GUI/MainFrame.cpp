#include "MainFrame.h"
#include <vector>
#include <string>

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
	EVT_BUTTON(Button0, MainFrame::OnButtonClick)
	EVT_BUTTON(Button1, MainFrame::OnButtonClick)
	EVT_BUTTON(Button2, MainFrame::OnButtonClick)
	EVT_BUTTON(Button3, MainFrame::OnButtonClick)
	EVT_BUTTON(Button4, MainFrame::OnButtonClick)
	EVT_BUTTON(Button5, MainFrame::OnButtonClick)
	EVT_BUTTON(Button6, MainFrame::OnButtonClick)
	EVT_BUTTON(Button7, MainFrame::OnButtonClick)
	EVT_BUTTON(Button8, MainFrame::OnButtonClick)
	EVT_BUTTON(Button9, MainFrame::OnButtonClick)
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
}

void MainFrame::OnButtonClick(wxCommandEvent& e) {
	wxLogStatus("Button");
}