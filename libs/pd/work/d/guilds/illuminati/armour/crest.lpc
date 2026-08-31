#include <std.h>
#include <move.h>
#include <illuminati.h>

inherit ARMOUR;


void create() {
   ::create();
     set_property("no steal", 1);
     set_name("crest");
     set_short("%^YELLOW%^Go%^WHITE%^ld%^YELLOW%^en Cr%^WHITE%^e%^YELLOW%^st");
     set_long("This crest is made of gold and shows the sun rising over the horizon.");
     set_id(({ "crest", "golden crest" }));
     set_ac(0);
     set_weight(1);
     set_value(0);
     set_type("badge");
     set_limbs(({"torso"}));

}

int query_auto_load() {
    if(this_player()->query_guild() == "illuminati") return 1;
    return 0;
}

int give() { write("You may not give this away."); return 1; }

int drop() { write("Whatever for?"); return 1; }
