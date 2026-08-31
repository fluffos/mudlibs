#include <std.h>
#include <roston.h>
inherit MONSTER;

void create() {
    ::create();
    set_name("gyspy");
    set_id( ({ "monster" , "gyspy" }) );
    set_short("Gypsy");
    set_level(40);
    set_long("This gypsy is the wife of the Old Bard.  She is a small faerie but should not have that held against her.");
    set_alignment(100);
    set_race("faerie");
    set_body_type("faerie");
    set_gender("female");
    set("aggressive", 20);
    set_spell_chance(20);
    set_spells( ({ "fire dance", "spinning dervish", "anathema au vengeance" }) );
    new(ARM"dress")->move(this_object());
    force_me("wear dress");
}
