// book3.c

#include <ansi.h>

inherit ITEM;

void create()
{

        set_name(GRN "鞭法秘籍" NOR, ({ "whip book","book", "shu" }));
        set_weight(200);
        set("unit", "本");
        set("long", "这是古墓派的鞭法密笈。\n");
        set("value", 500);
        set("material", "paper");
        set("skill", ([
                        "name": "whip",	// name of the skill
                        "exp_required": 10000,  	// minimum combat experience required
                        "jing_cost": 10,	// jing cost every time study this skill
                        "difficulty":   25,     	// the base int to learn this skill
                        "max_skill":    100,      // the maximum level you can learn
        ]) );
}
