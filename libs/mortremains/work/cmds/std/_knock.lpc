// knock.c
// Lets a player knock on a door, which is heard on the other side.
// Mobydick, 1-21-93.
// Pallando put in the check for !str because the error annoyed him. 8-)
// (04-04-98) Chronos made a few cosmetic changes.

#include <mudlib.h>

inherit DAEMON ;
string get_door_string(string dir) ;

int cmd_knock (string str) {

    string dir ;
    object env ;
    mapping doors, exits ;

    /* This code is irrelevant now.
      if ((int)TP->query_rest_status()==2) {
      write("You cannot knock on a door while sleeping.\n") ;
      return 1;
      }
      if ((int)TP->query_rest_status()==1) {
      write("You cannot knock on a door while resting.\n") ;
      return 1;
      }
      */
    notify_fail("Knock on what?\n");

    if(!str || str == "" || (str != "on door" && str != "door" &&
	str != "on the door" &&
	sscanf(str, "on the %s door", dir) != 1 &&
	sscanf(str, "on %s door", dir) != 1)) 
	return 0 ;

    env = environment(this_player()) ;

    if (!env) {
	notify_fail ("The void has no doors.\n") ;
	return 0 ;
    }
    doors = env->query("doors") ;
    if (!doors) {
	notify_fail ("There are no doors here.\n") ;
	return 0 ;
    }

    if(!dir) {

	if(sizeof(keys(doors)) > 1) {
	    notify_fail("Which door do you wish to knock on?\n");
	    return 0; }

	dir = keys(doors)[0];
    }

    if (!doors[dir]) {
	notify_fail ("There is no "+dir+" door.\n") ;
	return 0 ;
    }
    write ("You knock on the "+dir+" door.\n") ;
    say (this_player()->query("cap_name")+" knocks on the "+dir+" door.\n") ;
    exits = env->query("exits") ;
    find_object_or_load(exits[dir]) ;
    tell_room (exits[dir], "You hear a knocking sound.\n") ;
    tell_room(exits[dir], "Someone is knocking on the "+
      (string)get_door_string(dir) + " door.\n") ;
    return 1 ;
}

string help()
{
    return( ""+
      "Syntax: knock on <dir> door\n"+
      "Effect: makes a sound heard on the other side of the\n"+
      "        door in direction <dir>\n"+
      "" );
}

string get_door_string(string dir) {
    if (!dir) return "nearby" ; // Can't figure out where it's coming from..
    switch(dir) {
    case "north" : dir = "south"; break;
    case "south" : dir = "north"; break ;
    case "west": dir = "east"; break ;
    case "east" : dir = "west" ; break ;
    case "northwest" : dir = "southeast"; break ;
    case "southeast" : dir = "northwest"; break ;
    case "northeast" : dir = "southwest" ; break ;
    case "southwest" : dir = "northeast"; break ;
    default: dir = "nearby" ;
    }
    return dir ;
}
