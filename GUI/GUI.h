#pragma once
#include <wx/wx.h>
#include <vector>
#include <unordered_set>

std::vector<wxButton*> init_numpad(wxWindow* parrent);

const std::unordered_set<wxString> default_text{
	"this a text",
	"Type a calculation: 2 + 2"
};