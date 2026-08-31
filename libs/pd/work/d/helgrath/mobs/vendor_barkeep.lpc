#include <std.h>

inherit BARKEEP;

void create() {
    ::create();
    set_property("no bump", 1);
    set_name("Milex");
    set_id( ({ "Milex", "barkeep", "milex", "bartender", "vendor" }) );
    set_short("Milex, the owner of the White Horse Tavern");
    set("aggressive", 0);
    set_level(30);
    set_long("He tends bar and he listens to gossip.\n");
    set_gender("male");
    set_alignment(122);
    set("race", "human");
    add_money("gold", random(200));
    set_body_type("human");
    set_currency("gold");
set_menu( ([
  "firefly" : ([
    "type" : "alcoholic",
    "strength" : 37,
    "servings" : 1,
    "long" : "A firefly from the White Horse Tavern.",
    "my_mess" : "The firefly liquor burns your mouth!"
  ]),
  "bloody mary" : ([
    "type" : "alcoholic",
    "strength" : 19,
    "servings" : 3,
    "my_mess" : "Wow! That had a kick to it!",
  ]),
  "firewine" : ([
    "type" : "alcoholic",
    "servings" : 3,
    "strength" : 9,
    "long" : "A weaker version of the firefly.",
  ]),
]) );
}
