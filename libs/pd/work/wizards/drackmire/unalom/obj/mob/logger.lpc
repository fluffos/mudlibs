#include <std.h>
#include "unalom.h"
inherit MONSTER;

void create()
{
 ::create();

        set_name("dwarven logger");
        set_id(({"dwarf", "logger", "dwarf logger" }));
        set_short("a dwarven logger");
        set_long("This dwarf is here out logging for the "
        "outpost, carefully assessing which trees are the "
        "hardest and best woods for the fortifications and "
        "tools that the outpost needs.");
        set_alignment(300);
        set_race("dwarf");
        if(random(10) < 5){
        set_gender("male");
        } else {
        set_gender("female");
        }
        set_body_type("human");
        set_level(40);
        set_spell_chance(20);
        set_spells(({ "whirl" }));
        
        new(UNAWEAP"logaxe")->move(this_object());
          command("wield axe");
          
        new(UNAARM"dwatunic")->move(this_object());
          command("wear tunic");
        new(UNAARM"dwarmor")->move(this_object());
          command("wear armor");
}
