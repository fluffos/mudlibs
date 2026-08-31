#include <std.h>
#include "unalom.h"
inherit MONSTER;

void create()
{
 ::create();

        set_name("dwarven guard");
        set_id(({"dwarf", "guard", "dwarf guard" }));
        set_short("a dwarven guard");
        set_long("One of the guards of the mining camp.  He "
        "looks like your average dwarf, about 1.5 meters "
        "tall with nearly a meter long red beard.  His squinty "
        "eyes peer out from behind his large nose, looking for "
        "signs of trouble.");
        set_alignment(300);
        set_race("dwarf");
        set_property("transformed", 0);
        set_gender("male");
        set_body_type("human");
        set_level(35);
        set_spell_chance(40);
        set_spells(({ "whirl" }));
        set_says(8, ({ "Be on guard, strange things happen here.",
             "Sometimes I swear the shadows move here.",
             "The other day I saw one of my brothers, but he wouldn't "
             "talk to me, these mines have a strange effect on people." }),0);
        
        new(UNAWEAP"dwbaxe")->move(this_object());
          command("wield axe");
        new(UNAWEAP"dwbaxe")->move(this_object());
          command("wield axe");
          
        new(UNAARM"dwatunic")->move(this_object());
          command("wear tunic");
        new(UNAARM"dwarmor")->move(this_object());
          command("wear armor");
}
