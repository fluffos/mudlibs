#include <std.h>
#include <roston.h>

inherit BARKEEP;

create() {
    ::create();
   set_property("no bump", 1);
   set_name("jeeves");
    set_id( ({ "jeeves", "barkeep" }) );
    set_short("%^BOLD%^%^BLACK%^Jeeves, The Lost Soul");
   set("aggressive", 0);
  set_level(500);
    set_long("Jeeves will get you anything you want that he has "
             "as long as you ask him for it.");
   set_gender("male");
   set_alignment(122);
   set("race", "human");
   add_money("gold", random(200));
    set_body_type("human");
    set_currency("gold");
    set_menu(
        ({
        "reaver", "elixir", "shot"
        }),
        ({ "alcoholic", "water", "alcoholic" }),
        ({ 20, 10, 24})
    );
    set_my_mess(
        ({
        "%^BOLD%^%^WHITE%^You Feel the power of the Reaver fill your body",
        "%^BOLD%^%^BLACK%^Your Throat feels like is buring away as you drink",
        "%^BOLD%^%^WHITE%^You feel the power the past souls feed you."
        })
    );
    set_your_mess(
        ({
        "%^BOLD%^%^WHITE%^Slams a Reaver and there body burst into a great white light.",
        "%^BOLD%^%^BLACK%^Pounds a Elixir and graps at the burning throat.",
        "%^BOLD%^%^WHITE%^Drinks a Shot of Souls and a strange mist covers them."
        })
    );
    set_menu_short(
        ({"%^BOLD%^%^BLACK%^R%^WHITE%^e%^BLACK%^a%^WHITE%^v%^BLACK%^e%^WHITE%^r",
        "%^BOLD%^%^BLACK%^A Elixir",
        "%^BOLD%^%^WHITE%^A Shot of Souls"
        })
    );
    set_menu_long(
        ({
        "A Reaver from the bar of the unknowon",
        "A Elixir from the one they call Jeeves.",
        "A Shot of Souls from the past souls."
        })
    );
}
