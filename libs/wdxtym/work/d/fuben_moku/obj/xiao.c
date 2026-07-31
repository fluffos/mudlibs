#include <weapon.h>
inherit XSWORD;

void create()
{
	set_name("影箫", ({ "xiao" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "支");
		set("long", "无数邪气凝聚而成的一支箫。\n");
	    set("no_get", 1);
		set("material", "邪气");
		set("wield_msg", "$N「唰」的一声抽出一支$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
	}
	
	init_xsword(10);
	setup();
}