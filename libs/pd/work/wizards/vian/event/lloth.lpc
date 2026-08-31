#include <std.h>
#include <zolenia.h>

inherit MONSTER;

void create() {
::create();
    set_name("Lloth");
    set_short("%^RESET%^%^BLACK%^%^BOLD%^The Goddess, Lloth");
    set_long("Lloth wears the same clothes which she has gifted to the Queen of her Queendom, the Valsharess.  She may be a drow, but glows with an energy unseen of in a mortal.");
    set_id(({"drow", "priest", "lloth", "goddess", "drow lloth", "the goddess of the drow", "goddess of the drow"}));
    set_level(36+random(10));
    set_race("drow");
    set_body_type("drow");
    set("aggressive",30);
    set_alignment(-1500);
    set_gender("female");
    set_class("clergy");
    set_subclass("cleric");
   new(ARM"rubyencrustedrobes")->move(this_object());
     force_me("wear robes");
   new(ARM"rubyencrustedring")->move(this_object());
     force_me("wear ring");
   new(ARM"rubyencrustedbracelet")->move(this_object());
     force_me("wear bracelet");
   new(ARM"rubyencrustedhelm")->move(this_object());
     force_me("wear helm");

    add_money("gold", random(2000));
    set_spell_chance(25);   
    set_spells(({"lifewarp", "pain", "unknit", "shield", "wound"}));   
    
        set_stats("constitution", 1000);
    set_max_hp( 9000000 );
    set_hp( query_max_hp() );
}


