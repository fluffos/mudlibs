/*
// File     :  /domains/Examples/virtual/exaA_server.c
// Comment  :  All .exaA virtual rooms are clones of this object
// 94-05-13 :  Pallando @ Nightmare wrote it
*/
#include <lib.h>

inherit LIB_ROOM;
inherit VIRTUAL;

#define EXAMPLE_A_DAEMON "/domains/Examples/virtual/exaA/daemon"

void virtual_setup( string arg )
{
    mapping data;

    data = (mapping)EXAMPLE_A_DAEMON-> get_data( arg );

    SetExits( data["exits"] );
    SetShort( data["short"] );
    SetLong( data["long"] );
    SetItems( data["items"] );
    SetProperties( data["prop"] );
}

/* EOF */
