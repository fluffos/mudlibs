#include <std.h>
#include <daemons.h>

inherit BARKEEP;

void create()
{
    ::create();
    set_name("carolyn");
    set_id( ({ "carolyn", "shopkeep", "shopkeeper", "owner" }) );
    set_short("Carolyn, the owner");
    set_long("When she's not busy with a customer, Carolyn sweeps the floor " +
            "and hums merry tunes. She has long, curly golden locks that " +
            "flow and bounce down her shoulders to her billowing %^BOLD%^" +
            "%^CYAN%^light blue dress%^RESET%^ and %^BOLD%^%^WHITE%^white, " +
            "flour-covered apron%^RESET%^.");
    set_race("human");
    set_body_type("human");
    set_gender("female");
    set_alignment(600);
    set_level(10);
    set_property("no bump", 1);
    add_money("gold", 30 + random(31));
    
    set_emotes(10, ({
        "%^CYAN%^Carolyn frowns:%^RESET%^ It's a shame about that poor " +
                "Apu fellow, getting caught in that collapsed building.",
        "Carolyn hums a cheerful tune.",
        "Carolyn sweeps up some spilled flour.",
        "Carolyn kneads some dough.",
        "Carolyn smiles happily." }), 0,
    );
        
    set_currency("gold");
    set_menu_header("Carolyn's Bakery sells the following:");
    set_menu_footer("Just <buy item> to get something!");
set_menu( ([
  "bread" : ([
    "type" : "food",
    "strength" : 11,
    "servings" : 4,
    "short" : "a loaf of bread",
    "long" : "A small loaf of freshly baked bread.",
    "price" : 2,
  ]),
  "donut" : ([
    "type" : "food",
    "strength" : 6,
    "servings" : 2,
    "your_mess" : "gobbles up a donut.",
    "long" : "A glazed donut.",
    "price" : 3,
  ]),
  "cinnamon roll" : ([
    "type" : "food",
    "strength" : 15,
    "servings" : 2,
    "long" : "A gooey sticky cinnamon roll.",
    "price" : 5,
  ]),
  "pie" : ([
    "type" : "food",
    "strength" : 17,
    "servings" : 3,
    "my_mess" : "The pie is heavenly.",
    "long" : "A warm pie.",
    "price" : 6,
  ]),
  "cake" : ([
    "type" : "food",
    "strength" : 21,
    "servings" : 5,
    "long" : "A simple cake, decorated with icing flowers.",
    "price" : 7,
  ]),
]) );
}

