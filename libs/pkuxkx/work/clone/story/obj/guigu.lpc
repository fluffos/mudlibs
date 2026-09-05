// guigu.c 鬼谷神算

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(WHT "鬼谷神算" NOR, ({ "guigu book", "book", "shu" }));
        set_weight(300);

        if (clonep())
                set_default_object(__FILE__);
        else
        {
                set("unit", "本");
                set("long", "传说是当年鬼谷子所著的奇书。\n");
                set("value", 10);
                set("material", "silk");
                set("skill", ([
                        "name": "literate", // name of the skill
                        "jing_cost":   100,    // jing cost every time study this
                        "difficulty":   40,    // the base int to learn this skill
                        "max_skill":   180,    // the maximum level you can learn to
                ]));
        }
}
