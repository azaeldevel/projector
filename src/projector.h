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

#ifndef _PROJECTOR_
#define _PROJECTOR_

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define PROJECTOR_TYPE_APPLICATION             (projector_get_type ())
#define PROJECTOR_APPLICATION(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), PROJECTOR_TYPE_APPLICATION, Projector))
#define PROJECTOR_APPLICATION_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), PROJECTOR_TYPE_APPLICATION, ProjectorClass))
#define PROJECTOR_IS_APPLICATION(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PROJECTOR_TYPE_APPLICATION))
#define PROJECTOR_IS_APPLICATION_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), PROJECTOR_TYPE_APPLICATION))
#define PROJECTOR_APPLICATION_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), PROJECTOR_TYPE_APPLICATION, ProjectorClass))

typedef struct _ProjectorClass ProjectorClass;
typedef struct _Projector Projector;
typedef struct _ProjectorPrivate ProjectorPrivate;

struct _ProjectorClass
{
	GtkApplicationClass parent_class;
};

struct _Projector
{
	GtkApplication parent_instance;

	ProjectorPrivate *priv;

};

GType projector_get_type (void) G_GNUC_CONST;
Projector *projector_new (void);

/* Callbacks */

G_END_DECLS

#endif /* _APPLICATION_H_ */
