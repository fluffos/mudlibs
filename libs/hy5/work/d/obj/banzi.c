#include <ansi.h>
#include <weapon.h>
inherit RING;
void create()
{
        set_name(HIR"寒铁板指"NOR, ({ "banzi" }) );
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "这是用寒铁铸成的板指。\n");
                	set("value", 1000000);
                             set("rigidity",50);
	        set("wield_msg", "$N从怀中摸出一个$n戴在手上。\n");
        	set("unwield_msg", "$N将手上的$n藏入怀中。\n");
	}
	init_ring(200);
	setup();
}
