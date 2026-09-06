/* 
*
*	Official Artificer of Priests Guild
*
*		Opened July 3, 1994 -Kel
*
*/
inherit "/guilds/priests/lib/storage";
#include <gender.h>
#include "/areas/tristeza/DEFS.h"
#include <door_defs.h>
#include "priest_room.h"

object shopkeeper;

int shop_open() {
    if(!present("shopkeeper",this_object())) {
	notify_fail("The Artificer is not here.\n");
	return 0;
    }
    if(!IS_PRIEST(this_player())){
	notify_fail("We do no business with unwashed heathens!\n");
	return 0;
    }
    return 1;
}

void reset_shop() {
    object door;
    string str;
    int flags;

    if(!shopkeeper) {
	shopkeeper = clone_object(NPC_DIR+"shopkeeper");
	shopkeeper->set_name("drusus");
	shopkeeper->set_gender(G_MALE);
	shopkeeper->set_short("Brother Drusus the Guild Artificer");
	shopkeeper->set_id(({"shopkeeper"}));
	shopkeeper->set_random_pick(0);
	shopkeeper->set_guild("priest");
	shopkeeper->set_long(
	  "Brother Drusus is a retired Templar who has taken the oaths of a Lay \
Brother in the service of Boccob. Due to his extreme skill in weapons \
handling, he now serves as the Guild Artificer.");
	shopkeeper->load_chat(1,({
	    "Drusus sharpens a sword to a razor edge.",
	    "Thankckckck!!! Drusus brings his hammer down as he straightens\
 a sword.",
	    "CRANGGG!!! Drusus stamps a sword with the Orders insignia."
	  }));
	shopkeeper->set_dead_ob(this_object());
	shopkeeper->move_player("foo", this_object());
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
    set_store("/guilds/priests/rooms/artificer_store");
    set_short("Artificer's Workroom");
    set_long(
      "This is the Artificer's workroom of the Holy Order. Here weapons can be \
donated to the Order for use by Order members who borrow them. On the north \
wall there is a door leading to the storage room. All items \
donated here become property of the Holy Order. Brother Drusus will also \
'sharpen' or 'mend' a weapon if you ask politely.");
    add_exit("west", PRIEST_ROOM_DIR+"nave");
    set_light_level(LT_DIM);
    set(ROOM_GUILD);
    set_commands(([
	"sharpen" : "check_weapon",
	"sharp"	: "check_weapon",
	"mend"	: "check_weapon",
	"fix"	: "check_weapon"
      ]));

    set(PREVENT_TELEPORT);

    add_object( ({ SHOP_DOOR,
	({ "add_door",
	  "It is a small oak door, apparently leading to a storage room.",
	  "north",
	  PRIEST_ROOM_DIR "artificer_store",
	  "iron",
	  "chopin_was_here",
	  1,1,1,SHOP_PICK_LVL,
	  "It's a strong iron lock, protecting well the room behind this door.",
	}),
      }), 0, 0);

}


status
check_weapon(string str) {
    object what;
    if(!str) {
	notify_fail(capitalize(query_verb()) + " what?\n");
	return 0;
    }
    if(!shop_open()) return 0;
    str=lower_case(str);
    what=present(str,this_player());
    str=capitalize(str);
    if(!what) {
	this_player()->tell_me("You don't have "+str+".");
	return 1;
    }
    if (!what->is_weapon()) {
	this_player()->tell_me(str+" is not a weapon.");
	return 1;
    }
    if(what->query_wielded()) {
	write("You must remove it first.\n");
	return 1;
    }
    if(what->query_blunt()) {
	write("Cannot sharpen "+str+".\n");
	return 1;
    }
    if(!what->query_bluntness()) {
	write("It is sharp already.\n");
	return 1;
    }
    if(random(101)<what->query_bluntness()) {
	write("Oh no! Your weapon broke when sharpened!\n");
	destruct(what);
	return 1;
    }
    what->set_bluntness(0);
    write("Ok. "+capitalize(str)+" is sharpened.\n");
    say(this_player()->query_name()+" had "+str+" sharpened.\n");
    return 1;
}



