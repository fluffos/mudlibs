#include <std.h>
#include <diran.h>

inherit MOB"mob_inherit";

void create() {
::create();
    set_name("cleric");
set_short("a mountain dwarf cleric");
    set_long("This sturdy looking mountain dwarf is a member of the city's clerics.  He protects the city against the Duergar.");
    set_id(({"cleric", "dwarf", "mountain dwarf", "mountain dwarf cleric", "mdcleric"}));
    set_level(46);
    set_race("dwarf");
        set_faction("diran");
    set_body_type("dwarf");
    set("aggressive",20);
    set_gender("male"); 
    add_money("gold", random(75));
        set_spell_chance(20);
    set_spells(({"wound", "kick", "punch"}));
   new(WEP"mdpstaff")->move(this_object());
     force_me("wield staff");
        new(ARM"mdwmrobe")->move(this_object());
     force_me("wear robe");
        new(ARM"mdwcsash")->move(this_object());
     force_me("wear sash");

}


