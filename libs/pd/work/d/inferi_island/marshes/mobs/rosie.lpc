#include <std.h>
#include <amun.h>
inherit BARKEEP;
void create() {
    ::create();
    set_name("Rosie");
    set("id", ({ "rosie", "monster" }) );
    set_level( 25 );
    set("short", "Rosie" );
    set("long", "Rosie is currently the barmaid here at the pub, but she was once a great warrior. After helping rid the marsh of the dragon, she did some work in Hamen's Tomb. She has a red hour-glass along her stomach and the rest of her hair is pure black." );
    set("race", "raknid" ); 
    set_gender( "female" );
    set_body_type("raknid");
    set_class("fighter");
    set_currency("gold");
    set_skill("bargaining", 90);
set_menu_header("The following drinks are served at the Bloated Pub:");
set_menu_footer("<buy drink_name> to get a drink");
set_menu( ([
  "mist" : ([
    "type" : "alcoholic",
    "strength" : 45,
    "servings" : 1,
    "short" : "%^BOLD%^%^CYAN%^Frozen Mist%^RESET%^",
    "my_mess" : "The frozen mist gives you a head rush "
      "as it slides down your throat.",
  ]),
  "water" : ([
    "type" : "alcoholic",
    "strength" : 20,
    "servings" : 2,
    "short" : "%^ORANGE%^Murky%^RESET%^ Water",
    "my_mess" : "You down the murky water and notice it "
      "has a strong bite!",
  ]),
  "mallow" : ([
    "type" : "alcoholic",
    "strength" : 35,
    "servings" : 2,
    "short" : "%^BOLD%^%^BLACK%^Marsh Mallow%^RESET%^",
    "my_mess" : "The marsh mallow expands slightly in your mouth "
      "just before you swallow it.",
  ]),
]) );
}
