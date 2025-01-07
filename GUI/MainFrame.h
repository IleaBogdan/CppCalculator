#pragma once
#include <wx/wx.h>
#include "GUI.h"

class MainFrame : public wxFrame
{
protected:

private:
	void OnNumpadButtonClick(wxCommandEvent& e);
	void OnTextChange(wxCommandEvent& e);
	void OnKeyEvent(wxKeyEvent& e);
	wxTextCtrl* calcText;
	wxPanel* panel;
public:
	MainFrame(const wxString& title);
};

