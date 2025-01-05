#include <vector>
#include <wx/wx.h>
#include <unordered_map>
#include <string>
#include <iostream>

// init numpad
std::vector<wxButton*> init_numpad(wxWindow* parrent) {
	std::pair<int, int> cpl{ 30, 260 }; // core point location
	std::unordered_map<char, wxPoint> numpad_points{
		{'0', {cpl.first + 25, cpl.second + 75}},
		{'1', {cpl.first, cpl.second} },
		{'2', {cpl.first + 75, cpl.second} },
		{'3', {cpl.first + 2 * 75, cpl.second} },
		{'4', {cpl.first, cpl.second + 25}},
		{'5', {cpl.first + 75, cpl.second + 25}},
		{'6', {cpl.first + 2 * 75, cpl.second + 25}},
		{'7', {cpl.first, cpl.second + 2 * 25}},
		{'8', {cpl.first + 75, cpl.second + 2 * 25}},
		{'9', {cpl.first + 2 * 75, cpl.second + 2 * 25} }
	};
	
	std::vector<wxButton*> numpad;
	for (char i : std::string("1472580369")) {
		numpad.push_back(new wxButton(parrent, wxID_ANY, 
			wxString(std::string{ i }), numpad_points[i]));
	}
	return numpad;
}