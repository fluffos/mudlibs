/*
// File     :  /domains/Examples/virtual/exaA_server.c
// Comment  :  All .exaA virtual rooms are clones of this object
// 94-05-13 :  Pallando @ Nightmare wrote it
*/
#include <std.h>

inherit ROOM;
inherit VIRTUAL;

#define EXAMPLE_A_DAEMON "/domains/Examples/virtual/exaA/daemon"

void virtual_setup( string arg )
{
    mapping data;

    data = (mapping)EXAMPLE_A_DAEMON-> get_data( arg );

    set_exits( data["exits"] );
    set_short( data["short"] );
    set_long( data["long"] );
    set_items( data["items"] );
    set_properties( data["prop"] );
}

/* EOF */
