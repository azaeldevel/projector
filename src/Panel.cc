
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
	image = NULL;
	strPreviewFile = "screenshot.png";
	
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title (GTK_WINDOW (window), "Panel");

	views = gtk_box_new (GTK_ORIENTATION_HORIZONTAL,2);
	gtk_container_add(GTK_CONTAINER(window), views);
	subpan = gtk_box_new (GTK_ORIENTATION_VERTICAL,3);
	gtk_container_add(GTK_CONTAINER(views), subpan);
		
	image = gtk_image_new ();
	gtk_container_add (GTK_CONTAINER (subpan), image);
	gtk_widget_set_size_request(image,300,300);
	
	buffer = gtk_text_buffer_new (NULL);
	text = gtk_text_view_new_with_buffer (buffer);
	gtk_widget_set_size_request(text,300,300);
  	gtk_text_view_set_wrap_mode (GTK_TEXT_VIEW (text), GTK_WRAP_WORD); 
	scrolled_window = gtk_scrolled_window_new (NULL, NULL);
	gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolled_window), 
                                  GTK_POLICY_AUTOMATIC, 
                                  GTK_POLICY_AUTOMATIC);
	gtk_container_add (GTK_CONTAINER (scrolled_window),text);
	gtk_container_add (GTK_CONTAINER (subpan), scrolled_window);
	gtk_container_set_border_width (GTK_CONTAINER (scrolled_window), 5);
	
	button_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
	gtk_container_add (GTK_CONTAINER (subpan), button_box);
	
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
	gtk_image_set_from_file (GTK_IMAGE (((Panel*)data)->image), ((Panel*)data)->strPreviewFile.c_str());
	//cortando la imagen
	/*if(projector) 
	{
		octetos::core::Error::write(octetos::core::Error("No hay o no se asigo el monitor para la projeccion.",octetos::core::Error::ERROR_UNKNOW,__FILE__,__LINE__));
		return;
	}*/
}

}
