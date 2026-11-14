/*
** Header-File for Book of Errors
** Author: Thragor@Nightfall, 05jun96
** Update:
*/

#ifndef _EBOOK_H_
#define _EBOOK_H_

#include <secure/wizlevels.h>
#include <config.h>

#define COMPILE "Compile"
#define RUNTIME "Runtime"

#define DATE 0
#define ERRORS 1

#define COMPILED 0
#define COMPILELINE 1
#define LOCATION 2

#define ENVIRONMENT 0
#define CREATOR 1
#define OBJECT 2

#define EBOOK(x) ("/obj/tool/ebook/"+x)
#define TP this_player()
#define ME this_object()
#define SF(x) #'x //' For Emacs
#define D(x,y) "/players/thragor/lib/debug"->debug("thragor",x,y)

#define ERRORBASE EBOOK("errorbase")

#endif
