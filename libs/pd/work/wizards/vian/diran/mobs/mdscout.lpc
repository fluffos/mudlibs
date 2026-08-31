#include <std.h>
#include <diran.h>

inherit MOB"mob_inherit";

void create() {
::create();
    set_name("scout");
    set_short("a mountain dwarf scout");
    set_long("This sturdy looking mountain dwarf is a member of the city's scouts.  He protects the city against the Duergar.");
    set_id(({"scout", "dwarf", "mountain dwarf", "mountain dwarf scout", "mdscout"}));
    set_level(45);
    set_race("dwarf");
        set_faction("diran");
    set_body_type("dwarf");
    set("aggressive",20);
    set_gender("male"); 
    add_money("gold", random(75));
        set_spell_chance(20);
    set_spells(({"stab", "kick", "punch"}));
   new(WEP"garnetdagger")->move(this_object());
     force_me("wield dagger");
   new(ARM"mdgwhitepants")->move(this_object());
     force_me("wear trousers");
   new(ARM"mdssweater")->move(this_object());
     force_me("wear sweater");
}


