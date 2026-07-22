// quanpu.c

#include <armor.h>

inherit ITEM;

void create()
{
        set_name("拳谱", ({ "quan pu", "quanpu", "shu", "book" }));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
                        "这是一本太祖长拳拳谱。\n");
                set("value", 500);
                set("material", "steel");
                set("skill", ([
                        "name": "taizu-quan",      // name of the skill
                        "exp_required": 500,  // minimum combat experience required
                        "jing_cost":    10,     // jing cost every time study this
                        "difficulty":   10,     // the base int to learn this skill
                        "max_skill":    31      // the maximum level you can learn
                ]) );
        }
}