/*
 * This "room" is a special object which can be dropped once.
 * Macbeth: since version 3.0 of the gamedriver this file has to
 * reside in global/ or secure/
 */
int dropped;
int grow_stage;
string owner;

query_auto_load ()
{
    return explode (object_name (this_object()), "#")[0]+":"+owner;
}

init_arg (str)
{
    owner = str;
}

set_owner (n)
{
    owner = n;
}

reset (arg)
{
    if (arg)
	return;
    dropped = 0;
    grow_stage = 5;
}

short ()
{
    return "portable castle";
}

long ()
{
    write(short() + ".\n");
}

/*
    heart_beat - grow the castle and, as it's placed in /room/new_castles,
    		 teleport it away, if not in /room/new_castles.
*/
heart_beat ()
{
    if (!dropped)
	return;
    if (grow_stage > 0) {
	say("The castle grows...\n");
	grow_stage -= 1;
	return;
    }
    if (grow_stage == 0) {
	string name;
	say("The portable castle has grown into a full castle !\n");
	shout("Something in the world has changed.\n");
	name = create_wizard(lower_case(owner));
	if (name) call_other(name,"???"); /* Macbeth: load the castle */
        if (!name
	    || !find_object(name)
	    || environment(find_object(name)) != environment()) {
	    /* added by Macbeth */
	    tell_room (environment(),
		"The castle disappears in a puff of smoke.\n");
	}
	destruct(this_object());
	return;
    }
}

id (str)
{
    return str == "castle";
}

drop (silently)
{
   /* Macbeth: check not needed anymore in 3.0
    if (environment(this_player())->query_drop_castle()) {
	write("Not this close to the city!\n");
	return 1;
    }
    */
    if (silently || query_verb() == "quit")
      return 1;
    
    dropped = 1;
    shout("There is a mighty crash, and thunder.\n");
    set_heart_beat(1);
    return 0;
}

get ()
{
    if (dropped) {
	write("You can't take it anymore !\n");
	return 0;
    }
    return 1;
}
