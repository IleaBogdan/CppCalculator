#pragma once
#include <wx/wx.h>
#include <vector>

std::vector<wxButton*> init_numpad(wxWindow* parrent);

enum Numpad_IDs {
	Button1 = 3,
	Button2 = 4,
	Button3 = 5,
	Button4 = 6,
	Button5 = 7,
	Button6 = 8,
	Button7 = 9,
	Button8 = 10,
	Button9 = 11,
	Button0 = 2
};