/*
 * This file is part of DroidPad.
 * DroidPad lets you use an Android mobile to control a joystick or mouse
 * on a Windows or Linux computer.
 *
 * DroidPad is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * DroidPad is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with DroidPad, in the file COPYING.
 * If not, see <http://www.gnu.org/licenses/>.
 */
#include "about.hpp"

#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/icon.h>
#include "data.hpp"
#include "proc.hpp"
#include "wxImagePanel.hpp"

using namespace droidpad;

#ifdef __WXMSW__
#define _FRAME_ICON wxT("icon.xpm")
#else
#define _FRAME_ICON wxT("iconlarge.xpm")
#endif

#define LARGE_ICON wxT("iconlarge.xpm")

#define FRAME_TITLE "About DroidPad"

BEGIN_EVENT_TABLE(About, wxDialog)
	EVT_BUTTON(ID_GO_WEB, About::goWeb)
	EVT_BUTTON(ID_GO_BUG, About::goBugreport)
END_EVENT_TABLE()

About::About(wxWindow *parent) :
	wxDialog(parent, -1, _(FRAME_TITLE), wxDefaultPosition)
{
	SetIcon(wxIcon(Data::getFilePath(_FRAME_ICON), wxBITMAP_TYPE_XPM));

	wxBoxSizer *panelSizer = new wxBoxSizer(wxVERTICAL);
	SetSizer(panelSizer);

	wxImagePanel *image = new wxImagePanel(this, Data::getFilePath(LARGE_ICON), wxBITMAP_TYPE_XPM);
	panelSizer->Add(image, 0, wxALIGN_CENTRE);

	wxStaticText *title = new wxStaticText(this, -1, wxT("DroidPad"));
	wxFont largeFont = title->GetFont();
	largeFont.SetPointSize(18);
	title->SetFont(largeFont);
	panelSizer->Add(title, 0, wxALIGN_CENTRE);

	wxStaticText *desc = new wxStaticText(this, -1, _("Use an Android phone as a computer joystick"));
	panelSizer->Add(desc, 0, wxALIGN_CENTRE);

	wxBoxSizer *buttonSizer = new wxBoxSizer(wxHORIZONTAL);

	wxButton *web = new wxButton(this, ID_GO_WEB, _("Visit website"));
	buttonSizer->Add(web);

	wxButton *bug = new wxButton(this, ID_GO_BUG, _("Report a bug"));
	buttonSizer->Add(bug);

	panelSizer->Add(buttonSizer, 0, wxALIGN_CENTRE);

	panelSizer->SetSizeHints(this);
	Fit();
}

void About::goWeb(wxCommandEvent &evt) {
	openWebpage("http://digitalsquid.co.uk/droidpad");
}

void About::goBugreport(wxCommandEvent &evt) {
	openWebpage("https://bugs.launchpad.net/droidpad-pc");
}
