/*
// File     :  /domains/Examples/virtual/exaB_server.c
// Comment  :  All .exaB virtual rooms are clones of this object
// 94-05-20 :  Pallando @ Nightmare wrote it
*/
#include <std.h>
#include "exaB/defines.h"

inherit ROOM;
inherit VIRTUAL;

#define EXAMPLE_B_DAEMON (PREFIX "daemon")
#define EXCEPTION_DAEMON (PREFIX "exceptions")

void virtual_setup( string arg )
{
    mapping data;

    data = (mapping)EXAMPLE_B_DAEMON-> get_data( arg );

    set_exits( data["exits"] );
    set_short( data["short"] );
    set_long( data["long"] );
    set_properties( data["prop"] );

    if( data["exception"] )
	EXCEPTION_DAEMON-> modify( arg );
}

/* EOF */
