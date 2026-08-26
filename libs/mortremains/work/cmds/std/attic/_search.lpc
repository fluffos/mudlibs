// search.c
// This is a default search command that doesn't find anything. The main
// purpose of it is that if a player searches in a room that doesn't have
// anything to search for, he gets the "You search but find nothing" instaed
// of "What?". If a room defines a search command via add_action it will
// override this command. (If it doesn't then dike this command out!)
// Written by Mobydick, 11-13-92
// If you use this code, please leave this header in.
// If you don't, the Code Police will hunt you down and kill you.

int cmd_search() {
 
	if(!this_player()->query("vision")) {
	write("How can you search when you can't see a thing?\n");
	return 1; }
 
	write("You search, but fail to find anything of interest.\n");
	say((string)this_player()->query("cap_name") + " searches the room, " +
	    "but fails to find anything of interest.\n");
 
return 1; }

int help() {
	write ("Usage: search <object>\n\n"+
"This command lets you search an object for hidden things. If no argument\n"+
"is supplied, you search the room you are in.\n") ;
	return 1 ;
}
 
