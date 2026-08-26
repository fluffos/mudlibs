// knock.c
// Lets a player knock on a door, which is heard on the other side.
// Mobydick, 1-21-93.
// Pallando put in the check for !str because the error annoyed him. 8-)

#include <mudlib.h>

inherit DAEMON ;

int cmd_knock (string str) {

	string dir ;
	object env ;
	mapping doors, exits ;

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
	return 1 ;
}

string help()
{
  return( ""+
"Syntax: knock on <direction> door\n\n"+
"This command makes a sound heard on the other side of the\n"+
"        door in direction <direction>\n"+
  "" );
}
