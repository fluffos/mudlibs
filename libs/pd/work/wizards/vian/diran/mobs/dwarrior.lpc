#include <std.h>
#include <diran.h>

inherit MOB"mob_inherit";

void create() {
::create();
    set_name("duergar warrior");
    set_short("a duergar warrior");
    set_long("This sturdy looking duergar is a member of the city's warriors.  He protects the city against the Mountain Dwarves.");
    set_id(({"warrior", "duergar", "duergar warrior", "dwarrior"}));
    set_level(50);
    set_race("dwarf");
    set_body_type("dwarf");
    set("aggressive",20);
    set_gender("male"); 
    set_faction("duergar");
    add_money("gold", random(75));
        set_spell_chance(20);
    set_spells(({"slash", "kick", "punch"}));
        new(WEP"dwsword")->move(this_object());
     force_me("wield sword");
        new(ARM"dgpants")->move(this_object());
     force_me("wear pants");
             new(ARM"dgshirt")->move(this_object());
     force_me("wear shirt");
         set_race("duergar");


}



