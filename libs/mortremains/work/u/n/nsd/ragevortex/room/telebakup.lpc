/*
** File: telebackup.c
** Author: Ragevortex
** Updated by: Lady Nsd (august 2000)
*/

#include <config.h>
#include <mudlib.h>
#include "mina.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set( "short", "Control Room" );
    set("author", "ragevortex");
    set("long", @EndText
As you enter the teleporter you start floating inside of
a weird energy field. You hear a crackling sound all
around you and what appears to be portal forms all
around you. Perhaps you could go through them.
EndText
    );
    set( "exits", ([
      "start" : START,
      "void"  : VOID,
    ]) );
}
