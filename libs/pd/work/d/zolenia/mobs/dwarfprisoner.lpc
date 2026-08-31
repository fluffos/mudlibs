#include <std.h>
#include <zolenia.h>

inherit MONSTER;

void create() {
::create();
    set_name("dwarf prisoner");
    set_short("a Dwarven prisoner");
    set_long("This dwarven prisoner appears to have been beaten fairly badly.  His clothes appear to have been nice, once upon a time, before constant attacks and being trapped in a cell.  He has a sort of powerful aura to him.");
    set_id(({"dwarf", "prisoner", "dwarfprisoner", "dwarven prisoner"}));
    set_level(59+random(6));
    set_race("dwarf");
    set_body_type("dwarf");
    set("aggressive",30);
    set_gender("male");
    set_class("wanderer");
    set_subclass("jester");
    add_money("gold", random(1100));
    set_spell_chance(25);   
    set_spells(({"flick", "jab"}));   
}

