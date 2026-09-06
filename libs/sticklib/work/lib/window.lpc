/****************************************************************
*								*
* Module:							*
*	/lib/window.c						*
* Description:							*
*	A nifty window-object that can be used to represent	*
*	a window in the room. You need to link two rooms; one	*
*	has the 'master' window (this object), the other	*
*	slave window (SLAVE_WINDOW_FILE as defined by		*
*	<window_defs.h>). However, you only need to define	*
*	the room in which the master window is, and the slave	*
*	window will be added by this object. You have to make	*
*	sure that the room with the master window is always	*
*	loaded in before a player can enter the other room,	*
*	though, to make things work smoothly.			*
* Version:							*
*	1.0a (for StickLib), Aug-98.				*
* Last update:							*
*	25-Aug-98 by Doomdark					*
*								'
* Modifications:						*
*								*
****************************************************************/

#include <window_defs.h>

inherit	"/basic/id";

string long_desc2, long_desc3;
string *alias_list;	/* List of aliases window accepts. */
string other_room;	/* Name of the room window 'sees'. */
object other_side;	/* 'other side' of the window. */

status get() { return 0; } /* Can't be taken. */

void
create()
{
    set_name("window");
    set_short(0);	/* Usually, this is 'seen' in the room's description. */
    set_long("It's a typical window. You can look through it.");
    long_desc2 = "on a street behind the window";
    long_desc3 = "in the room behind the window";
    return;
}

void set_long2(string s) { long_desc2 = s; }

void set_long3(string s) { long_desc2 = s; }

varargs void
set_other_room(string s, string t, string u)
{
    object ob;
    other_room = s;
    if(t) long_desc2 = t;
    if(u) long_desc3 = u;
    other_room -> load_me();
    if(!(ob = find_object(other_room))) return;
    if(!(other_side = present("window", ob))) {
	other_side = clone_object(SLAVE_WINDOW_FILE);
	move_object(other_side, ob); }
    other_side -> set_master(this_object(),object_name(environment()));
    return;
}
string
players_in(object room)
{
    object x;
    string *t;
    x = first_inventory(room);
    t = ({});
    while(x) {
	if(living(x) && (x -> short()))
	    t += ({ (string) x -> query_name(this_player(), 0) });
	x = next_inventory(x); }
    if(!sizeof(t)) return 0;
    return implode(t, ", ", " and ");
}
varargs string
query_long(string what, object who)
{
    string s;
    call_other(other_room,"???");
    if (!(s = players_in(find_object(other_room))))
	return ::query_long(what, who) +"You can't see anyone " + long_desc2 + ".";
    else return ::query_long(what, who)+"\nYou see " + s + " " + long_desc2 + ".";
}
void player_passed(object who)
{
    if(who -> short()) environment() -> tell_here(
	  "You notice someone walking " + long_desc2 + ".");
    return;
}

string
query_inside_text()
{
    string s;
    if(!(s = players_in(environment())))
	return "You can't see anyone " + long_desc3 + ".";
    else return "You see " + s + " " + long_desc3;
}
