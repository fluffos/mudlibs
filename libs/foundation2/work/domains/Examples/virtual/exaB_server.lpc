/*
// File     :  /domains/Examples/virtual/exaB_server.c
// Comment  :  All .exaB virtual rooms are clones of this object
// 94-05-20 :  Pallando @ Nightmare wrote it
*/
#include <lib.h>
#include "exaB/defines.h"

inherit LIB_ROOM;
inherit VIRTUAL;

#define EXAMPLE_B_DAEMON (PREFIX "daemon")
#define EXCEPTION_DAEMON (PREFIX "exceptions")

void virtual_setup( string arg )
{
    mapping data;

    data = (mapping)EXAMPLE_B_DAEMON-> get_data( arg );

    SetExits( data["exits"] );
    SetShort( data["short"] );
    SetLong( data["long"] );
    SetProperties( data["prop"] );

    if( data["exception"] )
	EXCEPTION_DAEMON-> modify( arg );
}

/* EOF */
