#include <std.h>
#include <diran.h>

inherit MOB"mob_inherit";

void create() {
::create();
    set_name("duergar shaman");
    set_short("a duergar shaman");
    set_long("This sturdy looking duergar is a member of the city's shamans.  He protects the city against the Mountain Dwarves.");
    set_id(({"shaman", "duergar", "duergar shaman", "dshaman"}));
    set_level(51);
    set_race("dwarf");
    set_body_type("dwarf");
    set_faction("duergar");
    set("aggressive",20);
    set_gender("male"); 
        set_spell_chance(20);
    set_spells(({"deadlyfinger", "kick", "punch"}));
    add_money("gold", random(75));
        new(ARM"dgpants")->move(this_object());
     force_me("wear pants");
             new(ARM"dgshirt")->move(this_object());
     force_me("wear shirt");
                  new(WEP"mdgwhip")->move(this_object());
     force_me("wield whip");
         set_race("duergar");


}



