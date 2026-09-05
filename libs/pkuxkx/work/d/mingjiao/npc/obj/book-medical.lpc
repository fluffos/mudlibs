// book-medical.c

#include <ansi.h>

inherit ITEM;

void create()
{

        set_name(GRN "医 书" NOR, ({ "medical book", "book" }));
         set("no_get",1);
         set("no_drop",1);
        set_weight(200);
        set("unit", "本");
        set("long", "这是胡青牛的毕生所著。\n");
        set("value", 500);
        set("material", "paper");
        set("skill", ([
                        "name": "medical-skill",      	// name of the skill
                        "exp_required": 20000,  	// minimum combat experience required
                        "jing_cost": 30+random(20),	// jing cost every time study this skill
                        "difficulty":   40,     	// the base int to learn this skill
                        "max_skill":    300      // the maximum level you can learn
        ]) );
}

