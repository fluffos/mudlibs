// /u/beyond/mr/obj/force_book.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("内功心法", ({"force book", "shu", "book" }));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","这是一本书页发黄的书，里面密密麻麻的画了不少打坐吐呐的姿势。\n");
                set("unique", 1);
                set("treasure", 1);
                set("material", "paper");
                set("skill", ([
                        "name": "force",        // name of the skill
                        "exp_required": 5000,      // minimum combat experience required
                        "jing_cost":    20,     // jing cost every time study this
                        "difficulty":   20,     // the base int to learn this skill
                        "min_skill":    30,
                        "max_skill":    40,      // the maximum level you can learn

                ]) );
        }
}

