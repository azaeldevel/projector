#ifndef OCTETOS_PROJECTOR_PROJECTION_HH
#define  OCTETOS_PROJECTOR_PROJECTION_HH

#include <gtk/gtk.h>

namespace octetos
{

class Projection
{
private:
	GtkWidget *window;
	
public:
	Projection(GtkApplication* app);
	GtkWidget* get_widget()const;
};


}

#endif
