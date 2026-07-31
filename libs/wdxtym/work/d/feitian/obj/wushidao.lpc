// wushidao.c 武士刀

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("武士刀", ({ "wushi dao", "dao", "wushidao" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把东洋武士刀，东洋武士都爱佩带。\n");
		set("value", 100);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n收回鞘。\n");
	}
	init_blade(125);
	setup();
}
