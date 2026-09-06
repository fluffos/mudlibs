inherit "/guilds/priests/lib/storage";
#include <door_defs.h>
#include "priest_room.h"
#include "/areas/tristeza/DEFS.h"
#include <gender.h>

object shopkeeper;

int shop_open() {
    if(!present("shopkeeper",this_object())) {
	notify_fail("The Quartermaster is not here.\n");
	return 0;
    }
    if(!IS_PRIEST(this_player())){
	notify_fail("Be gone heathen idoliter!\n");
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

	shopkeeper->set_name("tiberius");
	shopkeeper->set_id(({ "tiberius","quartermaster", "shopkeeper", "keeper"}));
	shopkeeper->set_guild("priest");
	shopkeeper->set_gender(G_MALE);
	shopkeeper->set_short("Brother Tiberius the Guild Quartermaster");
	shopkeeper->set_random_pick(0);
	shopkeeper->set_dead_ob(this_object());
	shopkeeper->set_long("Brother Tiberius is the Quartermaster for the \
Holy Order. He was a memeber of the infamous City Guard, but has since seen \
the true path and taken the vows of a Lay Brother.");
	shopkeeper->load_chat(1,({
	    "Tiberius deftly etches the Orders' monogram on an item."
	  }));
	move_object(shopkeeper,this_object());
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
    set_store("/guilds/priests/rooms/quarter_store");
    set(ROOM_GUILD);
    set_short("Quartermasters Room");
    set_long(
      "You are in the room of the Order's Quartermaster. It is a clean and neat \
storage area, with lots of shelves and bins, and a door leading to north. \
Here all sorts of useful items can be donated to the Order, or they may be \
borrowed for use. All objects left here are property of the Holy Order."
    );
    add_exit("east", PRIEST_ROOM_DIR+"nave");

    set(PREVENT_TELEPORT);
    add_object( ({ SHOP_DOOR,
	({ "add_door",
	  "It is a small oak door, apparently leading to a storage room.",
	  "north",
	  PRIEST_ROOM_DIR "quarter_store",
	  "iron",
	  "chopin_was_here",
	  1,1,1,SHOP_PICK_LVL,
	  "It's a strong iron lock, protecting well the room behind this door.",
	}),
      }), 0, 0);
}
