//LUCAS 2000-6-18
// feixue-book.c  
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC"飞雪掌谱"NOR, ({ "feixue-book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
//                set("no_drop",1);
                set("long",
                        "这是一本学飞雪映梅掌的书。\n");
                set("value", 1000);
                set("material", "paper");
                set("skill", ([
                        "name":         "snow-zhang",       // name of the skill
                        "exp_required": 10000,                  // minimum combat experience required
                                                                // to learn this skill.
                        "jing_cost" :   20,
                        "difficulty":   20,                     // the base int to learn this skill
                                                                // modify is gin_cost's (difficulty - int)*5%
                        "max_skill":    80,                     // the maximum level you can learn
                        "min_skill":    20                       // the maximum level you can learn
                                                                // from this object.
                ]) );
        }
}

