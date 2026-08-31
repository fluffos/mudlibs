#include <std.h>
#include <zolenia.h>

inherit MONSTER;

void create() {
::create();
    set_name("KenjiRu");
    set_short("%^RESET%^%^BLACK%^%^BOLD%^KenjiRu,%^RESET%^ beggar of the drow");
    set_long("This drow is weak and obviously approaching his death bed.  He may not even be a real drow, as his skin isn't black enough, and his hair isn't white enough.  He appears to not fit in anywhere.");
    set_id(({"drow", "beggar", "drowbeggar", "drow beggar", "Kenjiru", "KenjiRu", "kenjiru"}));
    set_level(65+random(6));
    set_race("drow");
    set_body_type("drow");
    set_alignment(-500);
    set("aggressive",30);
    set_gender("male");
    set_class("rogue");
    set_subclass("assassin");
   new(WEP"darkknife")->move(this_object());
     force_me("wield knife");
   new(WEP"darkknife")->move(this_object());
     force_me("wield knife");
   new(ARM"tatteredrags")->move(this_object());
     force_me("wear rags");


    add_money("gold", random(40));
    set_spell_chance(25);   
    set_spells(({"circle", "pin", "dodge", "stab"}));   
}

