/*
// File     :  /cmds/mortal/_zero.c
// Comment  :  A temporary command to fix the 0 exits bug
// 94-06-30 :  Pallando wrote this
*/

#include <std.h>

inherit DAEMON;

int cmd_zero( string arg )
{
    object room, *contents;
    string room_file;
    int loop;

    room = environment( this_player() );

    if( room->query_long() )
    {
        write( "Liar!  Your bones will burn in hell forever.\n" );
        return 1;
    }
    loop = sizeof( contents = all_inventory( room ) );
    while( loop-- )
        contents[loop]-> move( this_object() );
    room_file = base_name( room );
    room-> remove();
    call_other( room_file, "frog" );
    room = find_object( room_file );
    loop = sizeof( contents = all_inventory( this_object() ) );
    while( loop-- )
        contents[loop]-> move( room );
    write( "Ok.\n" );
    return 1;
}

int help()
{
    write( @EndText
Command: zero
Syntax: zero (no args)
There is current a bug at Nightmare that makes rooms with no exits,
and no long description.  This command allows players to fix it.
EndText
    );
    return 1;
}

/* EOF */
