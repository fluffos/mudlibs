#include <std.h>
#include <diran.h>

inherit MOB"mob_inherit";

void create() {
::create();
    set_name("archer");
    set_short("a mountain dwarf archer");
    set_long("This sturdy looking mountain dwarf is a member of the city's archers.  He protects the city against the Duergar.");
    set_id(({"archer", "dwarf", "mountain dwarf", "mountain dwarf archer",  "mdarcher"}));
    set_level(45);
    set_faction("diran");
    set_race("dwarf");
    set_body_type("dwarf");
    set("aggressive",20);
    set_gender("male"); 
    add_money("gold", random(75));
        set_spell_chance(20);
    set_spells(({"bash", "kick", "punch"}));
   new(WEP"mdabow")->move(this_object());
     force_me("wield bow");
   new(ARM"mdgwhitepants")->move(this_object());
     force_me("wear trousers");
   new(ARM"mdgwhiteshirt")->move(this_object());
     force_me("wear shirt");
   new(ARM"mdgvest")->move(this_object());
     force_me("wear vest");
   new(ARM"mdgsash")->move(this_object());
     force_me("wear sash");
        new(ARM"mdaquiver")->move(this_object());
     force_me("wear quiver");
}


