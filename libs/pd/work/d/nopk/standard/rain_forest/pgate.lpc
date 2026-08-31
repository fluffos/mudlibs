#include <std.h>
#include <rain.h>
inherit VAULT;

void create() {
    ::create();
    set_properties( ([ "light" : 3, "night light" : 2, "town" :1 ]) );
    set_short("The town gates");
    set_long("These gates protect the palace from "
      "any unwated visitors of trespassers. There "
      "are always guards here to watch the gates.");
    set_items((["gates" : "They are tall steel gates."]));
    set_exits((["northeast" : ROOMS"home6",
	"northwest" : ROOMS"mpath5",
	"south" : ROOMS"pentrance"]));
    set_door("gate", ROOMS"pentrance", "south", "gate key");
    set_open("gate", 0);
    set_locked("gate", 1);
}

void reset() {
    ::reset();
    if(!present("guard"))
	new(MOB"gguard")->move(this_object());
    set_open("gate", 0);
    set_locked("gate", 1);
    get_object("/d/nopk/standard/rain_forest/pentrance")->set_open("gate", 0);
    get_object("/d/nopk/standard/rain_forest/pentrance")->set_locked("gate", 1);
}
