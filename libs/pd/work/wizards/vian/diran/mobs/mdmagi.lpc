#include <std.h>
#include <diran.h>

inherit MOB"mob_inherit";

void create() {
::create();
    set_name("magi");
    set_short("a mountain dwarf magi");
    set_long("This sturdy looking mountain dwarf is a member of the city's magi.  He protects the city against the Duergar.");
    set_id(({"magi", "dwarf", "mountain dwarf", "mountain dwarf magi", "mdmagi"}));
    set_level(46);
    set_race("dwarf");
        set_faction("diran");
    set_body_type("dwarf");
    set("aggressive",20);
    set_gender("male"); 
    add_money("gold", random(75));
        set_spell_chance(20);
    set_spells(({"freeze", "kick", "punch"}));
   new(WEP"flamingstaff")->move(this_object());
     force_me("wield staff");
        new(ARM"mdwmrobe")->move(this_object());
     force_me("wear robe");
        new(ARM"mdwmsash")->move(this_object());
     force_me("wear sash");

}


