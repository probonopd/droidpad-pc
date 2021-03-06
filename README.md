DroidPad - PC application
=========================

Welcome to DroidPad! For downloads please visit http://digitalsquid.co.uk/droidpad/

General info
============

DroidPad is written primarily in C++ with a bit of C dotted around. The source
is split into UI parts in src/if-gui and backend code in src/lib. Data (which
includes layouts, images, drivers and ADB) is in data/

Other folders:
	src/lib/ext: external source files used by DroidPad, eg. dns-sd, base64, md5.
	src/lib/include: include files that include the platform dependent versions.
	src/lib/msw: MS Windows specific files.
	src/lib/net: handles network communications.
	src/lib/usb: manages ADB scanning etc.
	src/lib/output: platform dependent output functions.
	src/lib/out/linux: Linux output through uinput
	src/lib/out/win32: Windows output through Windows API and vJoy
	src/lib/ext/win32: Windows utils and driver installation.

Installation
============

Linux
-----
To compile for Linux, run ./configure; make; (sudo) make install, as is normal
for other linux software.

Required installation files to build:
build-essential
g++
autotools-dev
wx2.8-headers
libwxgtk-2.8-dev
(maybe more?)

Windows
-------
I would recommend compiling on a Linux computer, using MinGW.

32-bit: I use the Ubuntu-distributed version of 32-bit MinGW, with wxWidgets
compiled into its prefix.
64-bit: I Use my own compiled version of MinGW-64 in a different prefix.

To compile, run ./configure-mingw or ./configure-mingw64. These scripts will
need to be changed to use your prefix location from mine. They can also be
set with some environment variables.
make can then be used to compile the software; make winexport then copies all
necessary files to the folder winexport32 or winexport64, allowing for easy
running on Windows.

To build a 32 and 64 bit installer, run the script ./winbuild. This requires
nsis to be installed.
