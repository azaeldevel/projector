## Process this file with automake to produce Makefile.in

## Created by Anjuta


uidir = $(pkgdatadir)/ui
ui_DATA = projector.ui


AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(PROJECTOR_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = projector

projector_SOURCES = \
	main.c \
	projector.h \
	projector.c


projector_LDFLAGS =

projector_LDADD = $(PROJECTOR_LIBS)


if PLATFORM_WIN32
projector_LDFLAGS += -Wl,--export-all-symbols
else
projector_LDFLAGS += -Wl,--export-dynamic
endif

if NATIVE_WIN32
projector_LDFLAGS += -mwindows
endif


EXTRA_DIST = $(ui_DATA)

# Remove ui directory on uninstall
uninstall-local:
	-rm -r $(uidir)
	-rm -r $(pkgdatadir)

