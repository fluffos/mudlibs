// 欧冶子的锤子 hammer

#include <weapon.h>
#include <ansi.h>
inherit HAMMER;

void create()
{
        set_name(HIW "欧冶子的锤子" NOR, ({ "hammer", "chui zi","ouyezi's hammer" }));
	    set_weight(20000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
		set("long", "这是一柄兵器大师欧冶子用过的铁锤。\n");
                set("value", 100);
                set("material", "steel");
                set("wield_msg", "$N拎起$n握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
	init_hammer(10);
        setup();
}
