#include <std.h>
#include <diran.h>

inherit MOB"mob_inherit";

void create() {
::create();
    set_name("guard");
    set_short("a mountain dwarf guard");
    set_long("This sturdy looking mountain dwarf is a member of the city's guard.  He protects the city against the Duergar.");
    set_id(({"guard", "dwarf", "mountain dwarf", "mountain dwarf guard", "mdguard"}));
    set_level(45);
    set_race("dwarf");
    set_body_type("dwarf");
        set_faction("diran");
    set("aggressive",20);
    set_gender("male"); 
    add_money("gold", random(75));
        set_spell_chance(20);
    set_spells(({"slash", "kick", "punch"}));
   new(WEP"mdglongsword")->move(this_object());
     force_me("wield sword");
   new(ARM"mdgwhitepants")->move(this_object());
     force_me("wear trousers");
   new(ARM"mdgwhiteshirt")->move(this_object());
     force_me("wear shirt");
   new(ARM"mdgvest")->move(this_object());
     force_me("wear vest");
   new(ARM"mdgsash")->move(this_object());
     force_me("wear sash");
}


