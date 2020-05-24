
#include "Panel.hh"


namespace octetos
{

GtkWidget* Panel::get_widget()const
{
	return window;
}
Panel::Panel()
{
	window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

	gtk_window_set_title (GTK_WINDOW (window), "Panel");
	gtk_window_set_default_size (GTK_WINDOW (window), 800, 600);

	button_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
	gtk_container_add (GTK_CONTAINER (window), button_box);
		
	button = gtk_button_new_with_label ("Capturar");
	g_signal_connect (button, "clicked", G_CALLBACK (capture), NULL);
	gtk_container_add (GTK_CONTAINER (button_box), button);	
}

void Panel::capture (GtkWidget *widget,gpointer   data)
{
  g_print ("Hello World\n");
}

}
