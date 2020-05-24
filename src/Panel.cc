
#include "Panel.hh"

#include <gdk/gdkx.h>
#include <stdio.h>
#include <cairo.h>
#include <cairo-xlib.h>
#include <X11/Xlib.h>
#include <octetos/core/Error.hh>

namespace octetos
{

GtkWidget* Panel::get_widget()const
{
	return window;
}
Panel::Panel()
{
	strPreviewFile = "screenshot.png";
	
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

	gtk_window_set_title (GTK_WINDOW (window), "Panel");
	gtk_window_set_default_size (GTK_WINDOW (window), 800, 600);

	button_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
	gtk_container_add (GTK_CONTAINER (window), button_box);
		
	button = gtk_button_new_with_label ("Capturar");
	g_signal_connect (button, "clicked", G_CALLBACK (capture), this);
	gtk_container_add (GTK_CONTAINER (button_box), button);	
}

void Panel::capture (GtkWidget *widget,gpointer   data)
{
	GdkDisplay* gd = gdk_display_get_default();
	Display* disp = GDK_DISPLAY_XDISPLAY(gd);
	::Window root;
	cairo_surface_t *surface;
	int scr;
	
	//includio todos lo monitores del screen
	if(!disp) {
		std::string msg = "No se logro obtener el recurso Display ";
        octetos::core::Error::write(octetos::core::Error(msg,octetos::core::Error::ERROR_UNKNOW,__FILE__,__LINE__));
		return;
	}
	scr = DefaultScreen(disp);
	root = DefaultRootWindow(disp);		
	surface = cairo_xlib_surface_create(disp, root, DefaultVisual(disp, scr),DisplayWidth(disp, scr),DisplayHeight(disp, scr));
	cairo_surface_write_to_png(surface, ((Panel*)data)->strPreviewFile.c_str());
	cairo_surface_destroy(surface);
	//preview.set_from_file(strPreviewFile.c_str());
	//cortando la imagen
	/*if(!projector) 
	{
		octetos::core::Error::write(octetos::core::Error("No hay o no se asigo el monitor para la projeccion.",octetos::core::Error::ERROR_UNKNOW,__FILE__,__LINE__));
		return;
	}*/
}

}
