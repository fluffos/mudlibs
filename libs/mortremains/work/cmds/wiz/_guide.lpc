/*
// File     :  _guide.c
// Purpose  :  user interface command to The Guide
// 93-08-17 :  Written by Douglas Reay (Pallando @ TMI-2)
*/
#include <guide.h>
#include <mudlib.h>

inherit DAEMON;

#define SYNTAX "Syntax: guide | guide (index)\n"

int cmd_guide( string index )
{
    object guide;

    if( !( guide = present( "guide", this_player() ) ) )
        ( guide = new(GUIDE_OB) )-> move( this_player() );

    if( stringp( index ) )
        guide-> cmd_start( index );
    else
        guide-> cmd_start( (string)this_player()->query( "guide_index" ) );

    return 1;
}

int help()
{
    write( SYNTAX + @HelpText
Effect: Puts you into the TMI Wizards guide.
HelpText
    );
    return 1;
}

/* EOF */
