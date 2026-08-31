
#include <std.h>
#include <saahr.h>

inherit BARKEEP;

void create() {
  ::create();
  set_name("lenna");
  set_race("nymph");
  set_body_type("human");
  set_gender("female");
  set_id(({"nymph"}));
  set_short("lenna");
  set_long("Lenna is a boisterous nymph with a bright smile. She creates "
           "lemony treats for everyone.");

  set_class("clergy");
  set_subclass("druid");
  set_level(55);

  set_skill("attack", 80);
  set_skill("melee", 80);
  set_skill("defense", 400);
  set_skill("nature", 400);
  set_stats("wisdom", 120);

  set_spells(({ "freeze", "bisonsmight me", "husk me",
                "eagleblitz", "rootgrasp", "vinegrasp" }));
  set_spell_chance(80);

  set_currency("silver");

  set_menu_header("%^YELLOW%^Lenna's Lemon Stand%^RESET%^");
  set_menu_footer("Everything made from fresh lemons daily!");
  set_menu( ([
    "lemonade" : ([
      "id" : ({ "lemonade", "glass of lemonade" }),
      "type" : "soft drink",
      "strength" : 35,
      "servings" : 3,
      "short" : "glass of lemonade",
      "long" : "A cool glass of lemonade, with bits of lemon pulp and ice.",
      "my_mess" : "You drink some lemonade.",
      "your_mess" : "$N drinks some lemonade.",
      "empty" : "glass",
    ]),
    "lemon iced tea" : ([
      "id" : ({ "tea", "iced tea", "ice tea",
        "lemon iced tea", "lemon ice tea", "lemon tea",
        "glass of tea", "glass of lemon tea", "glass of lemon iced tea" }),
      "type" : "caffeine",
      "strength" : 29,
      "servings" : 3,
      "short" : "glass of lemon iced tea",
      "long" : "This tall glass of iced tea is flavored with lemon juice.",
      "my_mess" : "You drink some lemon iced tea.",
      "your_mess" : "$N drinks some lemon iced tea.",
      "empty" : "glass",
    ]),
    "lemon tart" : ([
      "id" : ({ "tart", "lemon tart" }),
      "type" : "food",
      "strength" : 28,
      "servings" : 1,
      "long" : "A baked tart with a lemon filling.",
    ]),
    "lemon chicken" : ([
      "id" : ({ "lemon chicken", "chicken" }),
      "type" : "food",
      "strength" : 39,
      "servings" : 2,
      "long" : "A piece of tender chicken cooked with lemons and lemon juice.",
      "my_mess" : "You eat some lemon chicken.",
      "your_mess" : "$N eats some lemon chicken.",
    ]),
  ]) );

  set_inventory( ([
    ARM+"nymphdress" : "wear dress",
  ]) );

}


