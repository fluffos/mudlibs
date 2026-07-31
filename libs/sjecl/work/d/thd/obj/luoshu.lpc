#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIY"洛书"NOR, ({ "luo shu", "luo", "shu" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("value", 5000);
                set("treasure",1);
                set("unique",1);
                set("newbie", 1);
                set("material", "paper");
                set("skill", ([
			"name": "qimen-bagua",  
			"jing_cost":    45,
			"exp_required":	100000,	// minimum combat experience required
                        "difficulty":   20,
			"min_skill":    100,
                        "max_skill":    120,
                ]) );
        }
}

