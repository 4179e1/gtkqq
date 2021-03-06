#ifndef __GTKQQ_SPLASHPANEL_H
#define __GTKQQ_SPLASHPANEL_H
#include <gtk/gtk.h>

#define QQ_SPLASHPANEL(obj)	GTK_CHECK_CAST(obj, qq_splashpanel_get_type(),\
						QQSplashPanel)
#define QQ_SPLASHPANEL_CLASS(c)	GTK_CHECK_CLASS_CAST(c,\
						qq_splashpanel_get_type(),\
						QQSplashPanelClass)
#define QQ_IS_SPLASHPANEL(obj)	GTK_CHECK_TYPE(obj, qq_splashPanel_get_type())

typedef struct _QQSplashPanel 		QQSplashPanel;
typedef struct _QQSplashPanelClass	QQSplashPanelClass;

struct _QQSplashPanel{
	GtkVBox parent;
};

struct _QQSplashPanelClass{
	GtkVBoxClass parent;
};

GtkWidget *qq_splashpanel_new();
GtkType qq_splashpanel_get_type();

#endif
