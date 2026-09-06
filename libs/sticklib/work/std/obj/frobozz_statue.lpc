inherit "/basic/id";

#include <guild.h>

//#include "defs.h"
#include <conditions.h>

// As StickLib doesn't have the fighter guild code we have to move
// people to some other room. Perhaps just to the generic shop. :-)

//#define	ROOM_TO_MOVE_TO	FIGHTER_DIR "guild_entrance"
#include <generic_rooms.h>
#define	ROOM_TO_MOVE_TO	GENERIC_ROOM_SHOP

void
create()
{
    set_short("Statue of Frobozz");
    set_long("The statue portrays a short old grey-bearded man wearing a cloak and a pointed hat with stars in it. He is looking at a weapon wielded in his left hand as if he didn't know what to do with it.");
    set_name("statue of frobozz");
    set_id(({ "statue","frobozz" }));
}

status
get() { return 0; }

void
init()
{
    add_action("quick_entrance","worship");
    add_action("bow","bow");
    add_action("kick","kick");
}

int
bow(string str)
{
    if(!str || !id(str))
	return 0;
    if(!this_player()->query_can_move()) {
	this_player()->tell_me("You are unable to move a muscle.");
	return 1;
    }
    this_player()->tell_me("You bow deeply to the statue of Frobozz.");
    environment()->tell_here(this_player()->query_name()
      +" bows deeply to the statue of Frobozz.", 0, 0, ({ this_player() }), 0, 0, 0);
    return 1;
}

int
kick(string str)
{
    if(!str || !id(str))
	return 0;
    if(!this_player()->query_can_move()) {
	this_player()->tell_me("You are unable to move a muscle.");
	return 1;
    }
    this_player()->tell_me("You kick the statue of Frobozz.");
    environment()->tell_here(this_player()->query_name()+
      " kicks the statue of Frobozz.", 0, 0,
      this_player(), 0, 0, 0);
    environment()->tell_here("The expression in the statue's face changes from\
 bafflement to strict determination. Slowly he raises the huge sword high above\
 his head.");
    this_player()->tell_me("WHAM!!!\nYou lose your consciousness.");
    environment()->tell_here("The sword hits "+this_player()->query_name()+". WHAM!!!",
      0, 0, ({ this_player() }), 0, 0, 0);
    this_player()->set_condition(C_UNCONSCIOUS,30+random(31)); /* 30 to 60 hb's */
    this_player()->add_hp(-10000);	// Let's scare them a bit.
    this_player()->set_reset(1, 1);
    return 1;
}

quick_entrance(str) {
    if(!str || !id(str))
	return;
    if(!this_player()->query_can_move()) {
	this_player()->tell_me("You are unable to move a muscle.");
	return 1;
    }
    this_player()->tell_me("You kneel in front of the statue of Frobozz and worship him.");
    environment()->tell_here(this_player()->query_name()+" kneels in front of the\
 statue of Frobozz and worships him.", 0, 0, this_player(), 0, 0, 0);

#ifdef GN_FIGHTER
    if ((string) this_player()->query_guild() == GN_FIGHTER) {
	this_player()->tell_me("When you stand up again you notice that you have been teleported to...");
	this_player()->move_player("Vdisappears", ROOM_TO_MOVE_TO);
    }
#endif
    return 1;
}
