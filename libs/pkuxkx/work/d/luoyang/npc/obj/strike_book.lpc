// 掌法入门.c
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(CYN"掌法入门"NOR, ({ "strike book", "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
"这是一本掌法的入门书，适合新手阅读。\n");
                set("value", 10000);
                set("material", "paper");
                set("skill", ([
                        "name":                 "strike",               // name of the skill
                        "exp_required": 1000,                   // minimum combat experience required
                                                                                        // to learn this skill.
                        "jing_cost":            20,                             // jing cost every time study this
                        "difficulty":   20,                             // the base int to learn this skill
                                                                                        // modify is jing_cost's (difficulty - int)*5%
                "max_skill": 50 // the maximum level you can learn
                                                                                        // from this object.
                ]) );
        }
}

