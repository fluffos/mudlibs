#include <std.h>
#include <diran.h>

inherit MOB"mob_inherit";

void create() {
::create();
    set_name("warrior");
    set_short("a mountain dwarf warrior");
    set_long("This sturdy looking mountain dwarf is a member of the city's warriors.  He protects the city against the Duergar.");
    set_id(({"warrior", "dwarf", "mountain dwarf", "mountain dwarf warrior",  "mdwarrior"}));
    set_level(46);
    set_race("dwarf");
        set_faction("diran");
    set_body_type("dwarf");
    set("aggressive",20);
    set_gender("male"); 
    add_money("gold", random(75));
    set_spell_chance(20);
    set_spells(({"whirl", "kick", "punch"}));
   new(WEP"mdwaxe")->move(this_object());
     force_me("wield axe");
        new(ARM"mdgwhitepants")->move(this_object());
     force_me("wear trousers");
        new(ARM"mdgwhiteshirt")->move(this_object());
     force_me("wear shirt");
        new(ARM"mdgvest")->move(this_object());
     force_me("wear vest");
        new(ARM"mdgsash")->move(this_object());
     force_me("wear sash");

}


