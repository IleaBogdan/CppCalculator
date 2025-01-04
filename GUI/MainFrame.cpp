#include "MainFrame.h"
#include <vector>
#include <unordered_map>
#include <string>

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
	std::unordered_map<char, wxPoint> numpad_points{
		{'0', {cpl.first + 25, cpl.second + 75}}, // 0 
		{'1', {cpl.first, cpl.second} }, // 1
		{'2', {cpl.first + 75, cpl.second} }, // 2
		{'3', {cpl.first + 2 * 75, cpl.second} }, // 3
		{'4', {cpl.first, cpl.second + 25}}, // 4
		{'5', {cpl.first + 75, cpl.second + 25}}, // 5
		{'6', {cpl.first + 2 * 75, cpl.second + 25}}, // 6
		{'7', {cpl.first, cpl.second + 2 * 25}}, // 7
		{'8', {cpl.first + 75, cpl.second + 2 * 25}}, // 8
		{'9', {cpl.first + 2 * 75, cpl.second + 2 * 25} } // 9
	};
	std::vector<wxButton*> numpad;
	for (char i:"1472580369") {
		numpad.push_back(new wxButton(panel, wxID_ANY, wxString(std::string{i}), numpad_points[i]));
	}
	numpad.pop_back();
	wxTextCtrl* conosole = new wxTextCtrl(panel, wxID_ANY, "wtf?");
}