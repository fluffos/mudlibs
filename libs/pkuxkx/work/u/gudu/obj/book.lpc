// book-zixia.c

#include <ansi.h>

inherit ITEM;

void create()
{

        set_name(HIY "金蛇秘籍" NOR, ({ "jinshe miji", "miji" }));
        set_weight(200);
        set("unit", "本");
        set("long", "这是金蛇郎君夏雪宜的剑法秘籍「金蛇秘籍」\n");
        set("value", 500);
        set("material", "paper");
        set("skill", ([
                        "name": "jinshe-jian",       // name of the skill
                        "exp_required": 10000,  	// minimum combat experience required
                        "jing_cost": 15+random(30),	// jing cost every time study this skill
                        "difficulty":   25,     	// the base int to learn this skill
                        "max_skill":    99      // the maximum level you can learn
        ]) );
}
