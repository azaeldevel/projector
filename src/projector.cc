/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * projector.c
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
#include "projector.hh"
#include <iostream>


namespace octetos
{


Main::~Main()
{
	
}


Main::Main(int argc,char **argv)
{
	gtk_init (&argc, &argv);
	this->argc = argc;
	this->argv = argv;
	
	display = 0;
	screen = 0;
	monitorPanel = 0;
	monitorProjection = 1;
	panel = NULL;
	projection = NULL;
	
	lDisplay = gdk_display_get_default();
	lScreenCount = gdk_display_get_n_screens(lDisplay);
	
	for (int s = 0; s < lScreenCount; s++)
	{
		//lScreen = gdk_display_get_screen(lDisplay,s);
		lMonitorCount = gdk_display_get_n_monitors(lDisplay);
		if(s == screen)
		{
			if(lMonitorCount < 2)
			{
				std::cerr << "Se requieren dos monitores para ejecutar el servicio\n";
				//return;
			}
			for (int m = 0; m < lMonitorCount; m++)
			{  
				if(m == monitorPanel) 
				{
					panel = new Panel;
					GdkRectangle lMonitorRect;
					gdk_monitor_get_geometry(gdk_display_get_monitor(lDisplay,m), &lMonitorRect);
					gtk_window_move((GtkWindow*)panel->get_widget(),lMonitorRect.x, lMonitorRect.y);
					gtk_window_fullscreen((GtkWindow*)panel->get_widget());
					gtk_widget_show_all(panel->get_widget());
				}
				else if(m == monitorProjection)
				{
					projection = new Projection(app);
					GdkRectangle lMonitorRect;
					gdk_monitor_get_geometry(gdk_display_get_monitor(lDisplay,m), &lMonitorRect);
					gtk_window_move((GtkWindow*)projection->get_widget(),lMonitorRect.x, lMonitorRect.y);
					gtk_window_fullscreen((GtkWindow*)projection->get_widget());
					gtk_widget_show_all(projection->get_widget());
				}
				else
				{
					return;
				}
				
			}
		}
	}

	
	
}


}