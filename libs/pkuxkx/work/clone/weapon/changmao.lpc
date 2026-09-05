// longdagger.c 长矛

#include <weapon.h>
inherit SPEAR;

void create()
{
        set_name("长矛", ({ "changmao", "mao" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "杆");
                set("long", "这是一杆普通的长矛。\n");
                set("value", 100);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声拎起$n握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
	init_spear(30);
        setup();
}
