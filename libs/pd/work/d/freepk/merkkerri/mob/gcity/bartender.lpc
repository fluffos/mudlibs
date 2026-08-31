#include <std.h>
#include <mjungle.h>
#include <gcity.h>

inherit BARKEEP;

void create() {
    ::create();
   set_property("no bump", 1);
set_name("bartender");
set_id(({"bartender", "merkkirri bartender", "gnoll"}));
set_short("Merkkirri Bartender");
   set("aggressive", 0);
set_level(30);
    set_long("He tends bar and he listens.\n");
   set_gender("male");
set_alignment(-100);
set("race", "gnoll");
   add_money("gold", random(200));
set_body_type("gnoll");
    set_currency("gold");
set_menu_header("Silvermane Bar Menu");
set_menu( ([
  "blood wine" : ([
    "type" : "alcoholic",
    "strength" : 42,
    "servings" : 2,
    "long" : "A strong wine made with fresh blood.",
    "my_mess" : "The strong alcohol is touched with a slight tang of iron.",
  ]),
  "brew" : ([
    "type" : "alcoholic",
    "strength" : 33,
    "servings" : 3,
    "short" : "golden brew",
    "long" : "A deep golden colored ale.",
  ]),
  "meat" : ([
    "type" : "food",
    "strength" : 25,
    "servings" : 2,
    "long" : "A hunk of fresh, bloody meat.",
    "short" : "piece of fresh meat",
  ]),
]) );
}
