// changqiang.c 长枪

#include <weapon.h>
#include <ansi.h>
inherit SPEAR;

void create()
{
        set_name(HIW "长枪" NOR, ({ "chang qiang", "qiang" }));
	set_weight(20000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "杆");
		set("long", "这是一根普通的长枪。\n");
                set("value", 100);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声拎起$n握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
	init_spear(30);
        setup();
}
