#pragma once
#include <wx/wx.h>
#include <vector>
#include <unordered_set>
#include "../Backend/Backend.h"

std::vector<wxButton*> init_numpad(wxWindow* parrent);

const wxString default_text_box = "Type a calculation: 2 + 2";

const std::unordered_set<wxString> default_text{
	"Type a calculation: 2 + 2", // keep as the first text the text you want to display at first on the message box
	"this a text"
};

const std::string keysStr = "C1234567890-+/*";
const std::unordered_set<char> keys(keysStr.begin(), keysStr.end());