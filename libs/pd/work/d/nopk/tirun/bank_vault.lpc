#include <std.h>
#include <tirun.h>

inherit VAULT;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "The bank vault");
    set_long(
       "The Tirun vault is where the bank of Tirun keeps its cash on hand. "
	"Rows and rows of locked drawers line the walls, the contents of "
	"which are kept secure by keys and magic incantations.  The only "
	"feature of any notice is the Seal of the Bank of Tirun on the "
	"floor, the rest of the room filled with the savings of all the "
	"residents of Tirun.  The vault door leads north back into the "
       "lobby.");
    set_smell("default", "The smell of precious metals fills the air.");
    set_listen("default", "The thick walls of the vault muffle all sounds "
		"from the outside.");
    set_exits( 
      (["north" : ROOMS"bank"]) );
    cover_exit_with_door("north", "tirunbankvaultdoor");
    set_door_name("tirunbankvaultdoor", "vault");
    set_key("tirunbankvaultdoor", "bank key");
//    set_door("vault", ROOMS"bank", "south", "bank key");
}

void init() {
    ::init();
    add_action("look_at_vault", "look");
}

void reset() {
    object money;

    ::reset();
    if(!present("money")) {
	money = new("/std/obj/coins");
	money->set_money("platinum", random(3));
	money->set_money("gold", random(10));
	money->set_money("silver", random(100));
	money->move(this_object());
    }
}

int look_at_vault(string str) {
    if(!str || str != "vault") return 0;
    if(!query_closed("tirunbankvaultdoor")) write("It is open.\n");
    else write ("It is slammed shut.\n");
    return 1;
}
