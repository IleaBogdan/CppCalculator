#pragma once
#include <wx/wx.h>
#include "GUI.h"

class MainFrame : public wxFrame
{
protected:

private:
	void OnButtonClick(wxCommandEvent& e);
	wxDECLARE_EVENT_TABLE();
public:
	MainFrame(const wxString& title);
};

