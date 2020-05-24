#ifndef OCTETOS_PROJECTOR_PANEL_HH
#define  OCTETOS_PROJECTOR_PANEL_HH

#include <gtk/gtk.h>

namespace octetos
{

class Panel
{
private:
	GtkWidget *window;
	GtkWidget *button;
	GtkWidget *button_box;

public:
	Panel();
	GtkWidget* get_widget()const;
	static void capture (GtkWidget *widget,gpointer data);
};


}

#endif
