// yunu-xinjing2.c

#include <ansi.h>

inherit ITEM;

void create()
{

        set_name(GRN "玉女心经「下」" NOR, ({ "yunu xinjing", "xinjing" }));
        set_weight(200);
        set("unit", "本");
         set("long", "这是一册玉女心经「下」，记着古墓的内功心法。\n");
        set("value", 500);
        set("material", "paper");
        set("skill", ([
                         "name": "yunu-xinjing",          // name of the skill
                        "exp_required": 10000,  	// minimum combat experience required
                       "jing_cost": 30+random(20),     // jing cost every time study this skill
                        "difficulty":   25,     	// the base int to learn this skill
                        "max_skill":    99      // the maximum level you can learn
        ]) );
}
