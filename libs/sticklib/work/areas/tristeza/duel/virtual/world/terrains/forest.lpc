/* (C) Tron */

#include <virtual_room.h>

#include <areas.h>

int
query_speed() { return 6; }

string *
do_desc() {

    string *tmp1;
    string *tmp2;

    tmp1= ({ "You are moving in an old forest.\n"});

    tmp2= ({ "The trees cast dark shadows over the place.\n",
      "A light breeze of wind moves the trees.\n"+
      "You hear the low humming sounds of the forest.\n",
      "There are a lot of young trees here. They tend to\n"+
      "scratch your face if you are not careful.\n",
      "There are some very old trees around you - they are\n"+
      "too thick for you to reach around them.\n",
      "The forest gets dense here, all the trees are packed\n"+
      "close together making moving difficult.\n",
      "There are a lot of leaves on the ground here...old and\n"+
      "rotting to soil again.\n"
    });

    return ({tmp1[random(sizeof(tmp1))]+
      tmp2[random(sizeof(tmp2))]});
}

void
create_virtual() {

    set_light_level(1);

    short_desc="Dark forest";

    add_virtual_exit("north", 0, -1);
    add_virtual_exit("south", 0, 1);
    add_virtual_exit("east", 1, 0);
    add_virtual_exit("west", -1, 0);

    add_random_object("2:5:" + AREA_DUEL_ARENA + "npc/orc");
    add_random_object("1:2:" + AREA_DUEL_ARENA + "npc/corc");
    add_random_object("1:5:" + AREA_DUEL_ARENA + "npc/rabbit");

    add_item("trees", "These trees are mostly old and twisted.\n");
    add_item("leaves", "They seem to be large and colourless.\n");

    //set_distant_look(4);
    set_hb(1);
    set_effects(({"Light wind moves the trees.\n",
	"You hear dry crunching sounds...like walking on dead leaves.\n",
	"A sudden screaking sound cuts the silence...damn birds, you think.\n"}), 5);

    set_random_desc(do_desc());
}

void
init() {
    object ob;

    ::init();

    if(!this_object()->query_mist()) {
	if(!random(10))
	{
	    ob = clone_object(AREA_DUEL_ARENA + "obj/mist");
	    ob->do_shadow(this_object());
	}
    }
}
