#include <std.h>
#include <immortal_hall.h>
inherit ROOM;

void create() {
    object ob;

    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("The Class and Spell Balance Room");
    set_long(
	"This room is for the discussion of class and spell balance. "
	"The Hall of Immortals is north of here.");
    set_exits( 
              (["north" : ROOMS "adv_inner"]) );

    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "irreality board" }) );
    ob->set_board_id("class_spell_balance");
    ob->set_max_posts(500);
    ob->set_location(ROOMS "class_spells_inner");
    ob->set_short("the class and spell balance board");
    ob->set_long("Post ideas and problems regarding classes and spells.\n");
}

