
#include "Projection.hh"


namespace octetos
{

GtkWidget* Projection::get_widget()const
{
	return window;
}
Projection::Projection(GtkApplication* app)
{
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

	gtk_window_set_title (GTK_WINDOW (window), "Proyección");
	gtk_window_set_default_size (GTK_WINDOW (window), 800, 600);
}
	
}
