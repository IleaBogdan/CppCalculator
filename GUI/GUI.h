#pragma once
#include <wx/wx.h>
#include <vector>
#include <unordered_set>
#include "../Backend/Backend.h"

std::vector<wxButton*> init_numpad(wxWindow* parrent);

#include "../Backend/Backend.h";

const std::unordered_set<wxString> default_text{
	"",
	"this a text",
	"Type a calculation: 2 + 2"
};