#include <armor.h>
inherit FINGER;
void create()
{
        set_name( "合金板指", ({ "banzi" }) );
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "这是一个合金板指。\n");
                set("no_drop",1);
		set("value", 2);
                set("no_get",1);
                set("rigidity",50);
                set("armor_prop/damage", 150);
	        set("wield_msg", "$N从怀中摸出一个$n戴在手上。\n");
        	set("unwield_msg", "$N将手上的$n藏入怀中。\n");
	}
	//init_ring(150);
	setup();
}
