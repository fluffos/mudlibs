// fangtianji.c 方天画戟

#include <weapon.h>
#include <ansi.h>
inherit PESTLE;

void create()
{
	set_name(BLK "降魔杵" NOR, ({ "xiangmo chu", "chu" }));
	set_weight(40000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "杆");
		set("long", "这是一把降魔杵。\n");
                set("value", 100);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声拎起$n握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
	init_pestle(50);
        setup();
}
