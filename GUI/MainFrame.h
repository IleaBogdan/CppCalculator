#pragma once
#include <wx/wx.h>
#include "GUI.h"

class MainFrame : public wxFrame
{
protected:

private:
	void OnButtonClick(wxCommandEvent& e);
	void OnTextChange(wxCommandEvent& e);
	wxTextCtrl* calcText;
public:
	MainFrame(const wxString& title);
};

