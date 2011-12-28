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
#ifndef _DROIDFRAME_H
#define _DROIDFRAME_H

#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/listbox.h>

#include <map>

#include "lib/deviceManager.hpp"
#include "lib/droidpadCallbacks.hpp"

class DroidFrame : public wxFrame, public droidpad::DroidPadCallbacks
{
	public:
		DroidFrame ();
		~DroidFrame ();
		DECLARE_EVENT_TABLE()
	public:
	protected:
		wxPanel *panel;
		wxMenuBar *menuBar;

		wxButton *buttonStart, *buttonStop, *buttonDevicesRefresh;
		
		wxListBox *devListBox;

		wxStaticText *statusText;

		enum
		{

		};

	private:
		void init();

		void handleXMLError(wxString name);

		void OnDevicesRefresh(wxCommandEvent& event);
		void OnStart(wxCommandEvent& event);
		void OnStop(wxCommandEvent& event);

		void OnClose(wxCloseEvent& event);
		void OnMenuClose(wxCommandEvent& event);

		void OnListBox(wxCommandEvent& event);

		droidpad::DeviceManager *devices;

		std::map<int, int>listToDeviceMap;

	// Callbacks
	public:
		void dpInitComplete(bool complete);
		void dpCloseComplete();

		void dpNewDeviceList(droidpad::AndroidDeviceList &list);

		void customiseDevice(droidpad::AndroidDevice &device);

		virtual void threadStarted();
		virtual void threadError(wxString failReason);
		virtual void threadStopped();

};

#endif
