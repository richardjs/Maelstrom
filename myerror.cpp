
#ifndef _myerror_h
#define _myerror_h

/* Generic error message routines */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>


void error(char *fmt, ...)
{
	char mesg[BUFSIZ];
	va_list ap;

	va_start(ap, fmt);
	vsnprintf(mesg, sizeof(mesg), fmt, ap);
	fputs(mesg, stderr);
	va_end(ap);
}

void mesg(char *fmt, ...)
{
	char mesg[BUFSIZ];
	va_list ap;

	va_start(ap, fmt);
	vsnprintf(mesg, sizeof(mesg), fmt, ap);
	fputs(mesg, stdout);
	va_end(ap);
}

void myperror(char *msg)
{
	char buffer[BUFSIZ];

	if ( *msg ) {
		snprintf(buffer, sizeof(buffer), "%s: %s\n", msg, strerror(errno));
		error("%s", buffer);
	} else
		error((char *)strerror(errno));
}

#endif /* _myerror_h */

