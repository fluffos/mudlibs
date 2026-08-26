/*
  _move.c
  
  Replacement for old Nightmare III move command.
  
  -- Tlaloc --
*/

#include <std.h>
#include <move.h>
#include <daemons.h>

inherit DAEMON;

int cmd_move(string str)
{
    object target, destination;
    mixed t1, d1;
    int ok;
    
    if(!str || !strlen(str) || sscanf(str, "%s to %s", t1, d1) < 2)
        return notify_fail("Syntax: move <object1> to <object2>\n");
    
    if(t1 == "here")
        target = environment(this_player());
    else if(t1 == "me")
        target = this_player();
    else if(!(target = find_player(t1)))
        target = find_object(t1);
    
    if(!target || !objectp(target))
        return notify_fail("Target object not found.");
    
    if(d1 == "here")
        destination = environment(this_player());
    else if(d1 == "me")
        destination = this_player();
    else if(!(destination = find_player(d1)))
        destination = find_object(d1);
    
    ok = target->move(destination);
    
    switch(ok)
    {
        case MOVE_OK:
        write("Move OK.\n");
        return 1;
        break;
        case MOVE_NOT_ALLOWED:
        return notify_fail("Move not allowed.\n");
        break;
        case MOVE_NO_ROOM:
        return notify_fail("No space in destination for target.\n");
        break; 
        case MOVE_DESTRUCTED:
        return notify_fail("Move destructed.\n");
        break;
        case MOVE_NO_DEST:
        return notify_fail("Destination not valid.\n");
        break;
        default:
        return notify_fail("Unknown error occurred.\n");
        break;
    }
    
    return 1;
}

int help()
{
    write("Syntax: move <target> to <destination>.\n");
    write("Using 'here' for either will use the room you are in.\n");
    write("Using 'me' for either will use you.\n");
    return 1;
}
        
    
    