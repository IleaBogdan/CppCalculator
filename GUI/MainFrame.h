#pragma once
#include <wx/wx.h>
#include "GUI.h"

class MainFrame : public wxFrame
{
protected:

private:
	void OnButtonClick(wxCommandEvent& e);
	//wxDECLARE_EVENT_TABLE(); // - no need for this now
public:
	MainFrame(const wxString& title);
};

