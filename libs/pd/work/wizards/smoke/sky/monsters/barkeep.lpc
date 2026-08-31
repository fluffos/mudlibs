#include <std.h>
#include <cp.h>
inherit BARKEEP;

void create() {
  ::create();
  set_name("dwarven barkeeper");
  set_id(({ "dwarf", "barkeep", "barkeeper", "dwarven barkeeper" }));
  set_short("a dwarven barkeeper");
  set_long("This barkeeper watches over his tavern, "
   "sipping on a special brew. His beard hangs "
   "over the counter, which isn't very high. "
   "A stern look covers his face.");
  set_race("dwarf");
  set_class("fighter");
  set_subclass("warrior");
  set_body_type("dwarf");
  set("aggressive", 0);
  set_gender("male");
  set_currency("gold");
  set_level(150);
  set_inventory( ([
    WEAP "c_sword" : ({ 2, "wield sword", "wield sword" }),
    ARM "c_belt" : "wear belt",
    ARM "f_cloak" : "wear cloak",
    ARM "l_armour" : "wear armour",
    ARM "l_bracers" : "wear bracers",
    ARM "l_gloves" : "wear gloves",
    ARM "l_boots" : "wear boots",
    ARM "l_helm" : "wear helm",
    ARM "l_pants" : "wear pants",
  ]) );
  set_emotes(10, ({"The barkeeper takes a swig of his special brew."}), 0);
  set_menu( ([
    "whiskey" : ([
      "type" : "alcoholic",
      "strength" : 60,
      "servings" : 1,
      "short" : "whiskey shot",
      "long" : "A shot of whiskey from Steel Hammer Village.",
      "my_mess" : "You slam down a shot of whiskey and a fire burns in your throat.",
      "your_mess" : "$N slams down a shot of whiskey and $P face turns red.",
    ]),
    "brew" : ([
      "type" : "alcoholic",
      "strength" : 35,
      "servings" : 3,
      "short" : "pitcher of special brew",
      "long" : "A pitcher of special brew from Steel Hammer Village.",
      "my_mess" : "You down the pitcher of special brew and let out a massive belch.",
      "your_mess" : "$N downs a pitcher of special brew and lets out a massive belch.",
    ]),
  ]) );
}
