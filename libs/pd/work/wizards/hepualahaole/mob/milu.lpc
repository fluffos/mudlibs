#include <std.h>

inherit BARKEEP;

create() {
    ::create();
   set_property("no bump", 1);
   set_name("Milu");
    set_id( ({ "Milu", "barkeep" }) );
    set_short("Milu, the owner of Shadow's Inn");
   set("aggressive", 0);
  set_level(12);
    set_long("He tends bar and he listens.\n");
   set_gender("male");
   set_alignment(122);
   set("race", "human");
   set_hp(300);
   add_money("gold", random(200));
    set_body_type("human");
    set_currency("gold");
    set_menu(
        ({
        "shadowfire", "marry", "shadowlite"
        }),
        ({ "alcoholic", "alcoholic", "alcoholic" }),
        ({ 25, 15, 3 })
    );
    set_my_mess(
        ({
        "The shadowfire burns your soul!",
        "Wow! That had a kick to it!",
        "You down some shadowlite."
        })
    );
    set_your_mess(
        ({
        "screams from the burning agony of shadowfire.",
        "drinks a bloodied marry.",
        "drinks some shadowlite."
        })
    );
    set_menu_short(
        ({
        "A shadowfire",
        "A bloodied marry",
        "A shadowlite"
        })
    );
    set_menu_long(
        ({
        "A shadowfire from the Shadow's Inn.",
        "A blood mixture donated to Shadow's Inn.",
        "A pale version of shadowfire for those watching their weight."
        })
    );
}
