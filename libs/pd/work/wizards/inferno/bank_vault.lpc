#include <std.h>
#include <sindarii.h>

inherit VAULT;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "The bank vault");
    set("long",
	"You are inside of the master bank's vault!");
    set_exits( 
              (["up" : "/wizards/inferno/bank"]) );
    set_items(
	      ([ "vault" : (: "look_at_vault" :) ]) );
    set_door("vault", "/wizards/inferno/bank", "up", "bank key");
}

void reset() {
    object money;

    ::reset();
    if(!present("money")) {
	money = new("/std/obj/coins");
	money->set_money("platinum", 420);
	money->set_money("gold", 31337);
	money->set_money("electrum", 1337);
	money->move(this_object());
    }
}

void look_at_vault() {
    if(query_open("vault")) message("my_action", "It is open.", this_player());
    else message("my_action", "It is slammed shut.", this_player());
}

