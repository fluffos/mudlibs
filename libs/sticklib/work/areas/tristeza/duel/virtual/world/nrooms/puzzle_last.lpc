#include <room.h>

#include <areas.h>
void
create_room() {

    set_light_level(LT_LIGHTS);
    set_outdoors(WD_INDOORS);

    set(PREVENT_TELEPORT);
    set_short("Tomb chamber");
    set_long("It's a round chamber with a picture of a mage orc. Green "+
      "stones emit green light from the roof.\n");
    add_item("picture", "It's a small mage orc wearing a black cloak.");

    add_monster(AREA_TRISTEZA "duel/npc/orc_mage",
      "Mage's ghost arrives.", 1);
}

init_room() {
    call_out("say_it", 1);
    if(!present("orchinie", this_object())) {
	write("An echoing voice laughs at you: The tomb is empty!!!\n");
	write("You DID not get the quest, you poor sod!\n");
	move_object(this_player(), AREA_TRISTEZA "virtual/world/nrooms/puzzle_room");
    }
    else set_heart_beat(1);
}

void
say_it() {

    write("Dark voice says: You have entered the tomb.\n");
}

heart_beat() {

    object ob;

    if(!first_inventory(this_object())) {
	set_heart_beat(0); return;
    }
    if(!present("orchinie", this_object())) {
	while(ob = first_inventory(this_object())) {
	    move_object(ob, AREA_TRISTEZA "virtual/world/nrooms/puzzle_room");
	}
	set_heart_beat(0);
    }
}
