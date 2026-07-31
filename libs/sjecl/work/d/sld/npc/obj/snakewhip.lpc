// snakewhip.c 金蛇鞭

#include <weapon.h>
inherit WHIP;

void create()
{
        set_name("金蛇", ({ "jin she", "snake","she","bian", "whip" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("long", "这是条金光闪闪的小蛇。\n");
                set("value", 30);
                set("material", "fur");
                set("wield_msg", "$N「唰」的一声拿出一条$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n放回了腰间。\n");
                set("no_sell",1);
	        set("no_get",1);
	        set("no_steal",1);
                set("no_give",1);
                set("no_drop",1);
		set("no_return",1);
        }
        init_whip(30);
        setup();
}

