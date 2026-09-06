/*
*
*                Official Armoury of the Priests Guild
*
*                     Opened July 5,1994
*                         -Kel
*/

#include <gender.h>
#include "/areas/tristeza/DEFS.h"
#include <door_defs.h>


inherit "/guilds/priests/lib/storage";

#include "priest_room.h"

object shopkeeper;

int shop_open() {
    if(!present("germanicus",this_object())){
	notify_fail("The Armourer is not here.\n");
	return 0;
    }
    if(!IS_PRIEST(this_player())){
	notify_fail("We do not trade with the Infidal!\n");
	return 0;
    }
    return 1;
}

void reset_shop() {
    string str;
    object door;
    int flags;

    if(!shopkeeper) {
	shopkeeper = clone_object(NPC_DIR+"shopkeeper");
	shopkeeper->set_name("germanicus");
	shopkeeper -> set_id(({
	    "keeper","shopkeeper","brother germanicus","germanicus"
	  }));
	shopkeeper->set_gender(G_MALE); /* Default was randomly male or female */
	shopkeeper->set_short("Brother Germanicus the Guild Armourer");
	shopkeeper->set_dead_ob(this_object());
	shopkeeper->set_long(
	  "Brother Germanicus is a former Hospitalar Sergeant who has taken the oaths \
of a Lay Brother and now passes his remaining days serving Boccob as best he \
knows how.  His extreme knowledge of armours makes him a valuable asset.");
	shopkeeper->set_random_pick(0);
	shopkeeper->set_guild("priest");
	shopkeeper->load_chat(1,({
	    "Germanicus polishes some of the stored armours.",
	    "CLANG!!! Germanicus stamps a armour as Order property."
	  }));
	shopkeeper -> move_player("foo", this_object());
    }
    if(door = present("door", this_object())) {
	// This could be simpler, but if you can do it the hard way,
	// why wouldn't you? :P
	str = ":%<me.capname>%";
	flags = 0;
	if(door->query(DOOR_IS_OPEN)) {
	    str += " closes the door";
	    flags = 1;
	}
	if(door->query(DOOR_IS_UNLOCKED)) {
	    if(flags) str += " and locks it";
	    else str += " locks the door";
	    flags |= 2;
	}
	str += ".";
	door->set(DOOR_IS_CLOSED);
	door->set(DOOR_IS_LOCKED);
	if(flags)
	    tell_here(str,0,0,0,shopkeeper,0,0);
    }
}

void create_shop() {
    set_store("/guilds/priests/rooms/armoury_store");
    set(ROOM_GUILD);
    set_short("Armoury");
    set_long(
      "This is the Armoury of the Holy Order. Here the defenders of the faith \
may donate armours or borrow them for there own use. All donated items become \
broken or dented armours. On the north wall there is a door.");
    add_exit("south", PRIEST_ROOM_DIR+"nave");
    set_light_level(LT_DIM);
    set(PREVENT_TELEPORT);

    add_object( ({ SHOP_DOOR,
	({ "add_door",
	  "It is a small oak door, apparently leading to a storage room.",
	  "north",
	  PRIEST_ROOM_DIR "armoury_store",
	  "iron",
	  "chopin_was_here",
	  1,1,1,SHOP_PICK_LVL,
	  "It's a strong iron lock, protecting well the room behind this door.",
	}),
      }), 0, 0);
}


void init_shop() {
    add_action("check_armour","mend");
    add_action("check_armour","fix");
}


check_armour(str) {
    object what;
    int damage;
    if(!str) {
	notify_fail(capitalize(query_verb()) + " what?\n");
	return 0;
    }
    if(!shop_open()) return 0;
    str=lower_case(str);
    what=present(str,this_player());
    str=capitalize(str);
    if(!what) {
	write("You don't have "+str+".\n");
	return 1;
    }
    if(!what->is_armour()) {
	write(str+" is not an armour.\n");
	return 1;
    }
    if(what->query_worn()) {
	write("You must remove it first.\n");
	return 1;
    }
    if(!what->query_damage()) {
	write("It is not damaged.\n");
	return 1;
    }
    if(random(101)<(damage=what->query_damage())) {
	write("Oh no! "+str+" broke!\n");
	destruct(what);
	return 1;
    }
    what->add_damage(-damage);
    write("Ok. "+capitalize(str)+" is mended.\n");
    say(this_player()->query_name()+" had "+str+" mended.\n");
    return 1;
}


