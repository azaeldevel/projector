/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * projector.h
 * Copyright (C) 2020 Azael R. <azael.devel@gmail.com>
 * 
 * projector is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * projector is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef OCTETOS_PROJECTOR_HH
#define OCTETOS_PROJECTOR_HH

#include <gtk/gtk.h>

#include "Panel.hh"
#include "Projection.hh"

namespace octetos
{

class Main
{
private:
	GtkApplication *app;
  	//int status;
	int argc;
	char **argv;
	int lMonitorCount;
	int display;
	int screen;
	int monitorPanel;
	int monitorProjection;
	GdkDisplay *lDisplay;
	int lScreenCount;
	GdkScreen* lScreen;
	Panel* panel;
	Projection* projection;

public:
	//void run();
	Main(int argc,char **argv);
	~Main();
	int get_status()const;
	//static void activate(GtkApplication* app,gpointer user_data);
};

}
#endif

