#pragma once
#include <wx/wx.h>
#include <vector>
#include <unordered_set>
#include "../Backend/Backend.h"

std::vector<wxButton*> init_numpad(wxWindow* parrent);

const wxString default_text_box = "(-1)";

const std::unordered_set<wxString> default_text{
	"",
	"this a text",
	"Type a calculation: 2 + 2"
};