// longsword.c 长鞭
#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create()
{
	set_name(WHT"缠魂索"NOR, ({ "chanhunsuo", "bian" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", WHT"这是一柄缠魂索。\n"NOR);
		set("value", 10000);
		set("material", "leather");
		set("wield_msg", "$N「唰」的一声抖出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n卷回腰间。\n");
	}
	init_whip(999);
	setup();
}
