#include <vector>
#include <wx/wx.h>
#include <unordered_map>
#include <string>
#include <iostream>
#include "GUI.h"

// init numpad
std::vector<wxButton*> init_numpad(wxWindow* parrent) {
	std::pair<int, int> cpl{ 15, 160 }; // core point location
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
		{'9', {cpl.first + 2 * 75, cpl.second + 2 * 25} },
		{'=', {cpl.first+25*4, cpl.second+75}},
		{'+', {cpl.first+25*7, cpl.second+75}},
		{'-', {cpl.first+3*75, cpl.second+2*25}},
		{'*', {cpl.first + 3 * 75, cpl.second+25}},
		{'/', {cpl.first+3*75, cpl.second}},
		{'(', {cpl.first+75, cpl.second-25}},
		{')', {cpl.first+2*75, cpl.second-25}},
		{'C', {cpl.first, cpl.second-25}}
	};
	
	std::vector<wxButton*> numpad;
	for (const auto& i:numpad_points) {
		numpad.push_back(new wxButton(parrent,
			// setting each button a costum ID
			int(i.first),
			wxString(std::string{ i.first }), i.second));
	}
	return numpad;
}