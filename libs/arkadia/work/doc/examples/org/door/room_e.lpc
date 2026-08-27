/*
 * Examples on doors made by Nick
 * 
 * There is no key to fit this door, but you can pick the lock. However there
 * is a poisoned needle trap in the lock *shiver*
 *
 * The door will also close and lockitself silently each reset.
 */

inherit "/std/room";
#include "door.h"
#include <stdproperties.h>
#include <macros.h>
#include <poison_types.h>
#include <ss_types.h>

#define FOUND_MY_TRAP "_player_found_needle_trap" /* Somethig unique */

/*
 * Prototype
 */
void do_trap(object player);

int trap;
object door;

/*
 * The normal create routine
 */
void
create_room()
{
    set_short("room e");
    set_long("The room e in all it's might.\n");

    door = clone_object(PATH + "/door_e");
    door->move(this_object());

    door->set_key(12345678); /* Must set key to door for lock to work good */

    add_prop(OBJ_I_SEARCH_TIME, 2); /* Extra time it takes to search here */
    add_prop(OBJ_S_SEARCH_FUN, "search"); /* Function to call when searching */

    add_prop(OBJ_S_WIZINFO, "This room contains a door which might have a " +
	"trap set in it.\nThe door is also pickable.\n");

    call_out("reset_room", 1);
}

/*
 * Reset room, the door will lock and close each reset, and the trap status
 * will change.
 */
void
reset_room()
{
    object other;

    /* Set up the poison */
    if (!trap)
	trap = random(3);
    (door->query_other_room())->set_trap(trap);

    other = door->query_other_door();
    if (door->query_open())
    {
	door->do_close_door(""); /* If you want a message written put it */
	other->do_close_door(""); /* between the "" */
    }
    if (!door->query_locked())
    {
	door->do_lock_door(""); /* If you want a message written put it */
	other->do_lock_door(""); /* between the "" */
    }
}

/*
 * Init, routine that adds commands.
 */
void
init()
{
    ::init(); /* Always good to do. */
    add_action("disarm", "disarm");
}

/*
 * This function is called when someone searches something in the room
 */
string
search(object player, string str)
{
    string item, rest;
    int skill;

    if (sscanf(str, "%s for %s", item, rest) != 2)
	item = str;

    /* In this rooms the only special thing to search is the door */
    if (item != "door" && item != "stone door" && item != "lock")
	return ""; 

    /* If the trap has already been disarmed it's not there */
    if (!trap)
	return "";

    /* How skilled is the player in finding/removeing traps? */
    skill = player->query_skill(SS_FR_TRAP);

    /* Has the player specified he will be looking for traps? */
    if (rest == "traps")
	skill += 10;

    /* If the players searches the lock it will be even easier to find the trap
     */
    if (item == "lock")
	skill += 20;

    /*
     * This is a rather easy trap to locate but one time of 7 the searcher will
     * fail to find the trap anyway, even if he is skilled.
     */
    if (skill > 25 && random(7))
    {
	player->add_prop(FOUND_MY_TRAP, 1); /* Mark him! */
	return "You find a poison needle trap in the lock of the stone door!\n";
    }
    else
	return ""; /* Player didn't find anything special. */
}

/*
 * Disarm function
 */
int
disarm(string str)
{
    string *tmp;
    int skill, result;

    /* If the player haven't found the trap we shouldn't inform him that there
     * is one here.
     */
    if (!str || !this_player()->query_prop(FOUND_MY_TRAP))
	return 0;

    tmp = explode(str, " ");

    if (tmp[0] != "trap")
	return 0;

    /*
     * There could be more traps in the room that we don't know about.
     */
    if (str != "trap in lock" && trap)
    {
	notify_fail("Do you mean 'disarm trap in lock' ?\n");
	return 0;
    }

    if (!trap)
    {
	this_player()->remove_prop(FOUND_MY_TRAP);
	write("Someone has already disarmed the trap in the lock.\n");
	return 1;
    }

    skill = this_player()->query_skill(SS_FR_TRAP);
    result = random(skill) - 10; /* Not a very hard trap to remove */

    if (result > 0)
    {
	write("You disarm the trap!\n");
	say(QCTNAME(this_player()) + " disarms a trap in the lock.\n");
	this_player()->remove_prop(FOUND_MY_TRAP);
	trap = 0;
	(door->query_other_room())->set_trap(0);
    } 
    else if (result < -5)
    {
	write("Oh, oh. You fouled up and sprung the trap!!!!\n");
	do_trap(this_player());
    }
    else
    {
	write("You failed to disarm thee trap.\n");
	say(QCTNAME(this_player()) + " failed to disarm a trap.\n");
    }

    return 1;
}

/*
 * Someone sprung the trap
 */
void
do_trap(object player)
{
    object poison;

    trap = 0;
    (door->query_other_room())->set_trap(0);

    if (random(10))
    {
	write("You are hit by a poisoned needle!\n");
	say(QCTNAME(player) + " is hit by a poisoned needle!\n");
    }
    else
    {
	write("You manage to escape a poisoned needle trap! Luck!\n");
	say(QCTNAME(player) + " manages to escape a poisoned needle trap!\n");
	return;
    }

    seteuid(getuid(this_object()));
    poison = clone_object("/std/poison_effect");
    poison->set_time(120);
    poison->set_interval(10);
    poison->set_strength(20);
    poison->set_damage(({ POISON_HP, 40 }));
    poison->set_type("standard");
    poison->move(player);
    poison->start_poison();
}

/*
 * Query if there is a trap
 */
int query_trap() { return trap; }

/*
 * Set the trap
 */
void set_trap(int i) { trap = i; }
