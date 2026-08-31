#include <std.h>
#include <diran.h>

inherit MOB"mob_inherit";

void create() {
::create();
    set_name("priest");
    set_short("a mountain dwarf priest");
    set_long("This sturdy looking mountain dwarf is a member of the city's priests.  He protects the city against the Duergar.");
    set_id(({"priest", "dwarf", "mountain dwarf", "mountain dwarf priest", "mdpriest"}));
    set_level(46);
        set_faction("diran");
    set_race("dwarf");
    set_body_type("dwarf");
    set("aggressive",20);
    set_gender("male"); 
    add_money("gold", random(75));
        set_spell_chance(20);
    set_spells(({"gods hammer", "kick", "punch"}));
   new(WEP"mdpstaff")->move(this_object());
     force_me("wield staff");
        new(ARM"mdwmrobe")->move(this_object());
     force_me("wear robe");
        new(ARM"mdwpsash")->move(this_object());
     force_me("wear sash");

}


