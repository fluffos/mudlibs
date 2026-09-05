// dagger book.c

#include <ansi.h>

inherit ITEM;

void create()
{

        set_name(HIY "古刺客秘籍" NOR, ({ "dagger book","book", "shu" }));
        set_weight(200);
        set("unit", "本");
        set("long", "这是一本古刺客秘籍，记录了古代刺客的匕首武功套路！\n");
        set("value", 100);
        set("material", "paper");
        set("skill", ([
                        "name": "dagger", // name of the skill
                        "exp_required": 10000,          // minimum combat experience required
                        "jing_cost": 10,        // jing cost every time study this skill
                        "difficulty":   25,             // the base int to learn this skill
                        "max_skill":    100,      // the maximum level you can learn
        ]) );
}
