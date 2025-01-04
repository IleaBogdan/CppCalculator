#include "MainFrame.h"
#include <vector>

MainFrame::MainFrame(const wxString& title): 
	wxFrame(nullptr, wxID_ANY, title){
	
	// controls:

	wxPanel* panel = new wxPanel(this);
	panel->SetBackgroundColour(
		// wxColor gets rgb params
		wxColor(69, 69, 69)
	);
	// init numpad
	// maybe will make it another function
	std::pair<int, int> cpl{30, 260}; // core point location
	std::vector<wxPoint> numpad_points = { 
		{cpl.first+25, cpl.second+75}, // 0 
		{cpl.first, cpl.second}, // 1
		{cpl.first+75, cpl.second}, // 2
		{cpl.first+2*75, cpl.second}, // 3
		{cpl.first, cpl.second+25}, // 4
		{cpl.first+75, cpl.second+25}, // 5
		{cpl.first+2*75, cpl.second+25}, // 6
		{cpl.first, cpl.second+2*25}, // 7
		{cpl.first+75, cpl.second+2*25}, // 8
		{cpl.first+2*75, cpl.second+2*25}  // 9
	};
	std::vector<wxButton*> numpad;
	for (int i:{1,4,7,2,5,8,0,3,6,9}) {
		numpad.push_back(new wxButton(panel, wxID_ANY, wxString::Format(wxT("%i"), i), numpad_points[i]));
	}
}