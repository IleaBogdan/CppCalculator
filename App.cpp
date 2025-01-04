#include "App.h"
#include "GUI/MainFrame.h"

// leting wx know which class is our app
wxIMPLEMENT_APP(App);


bool App::OnInit() {
	// instance of the window
	MainFrame* mf = new MainFrame("Calculator");
	// set size and center
	mf->SetClientSize(300, 400);
	mf->Center();
	mf->Show();
	// if returned false will close
	return true;
}