// 破势刀 pishidao.c
// Cracked by 凌惊雪 12-15-2002

#include <weapon.h>
#include <ansi.h>
inherit BLADE;
//inherit F_UNIQUE;

void create()
{
	set_name(HIB"破势刀"NOR, ({"poshi dao", "poshi blade", "poshi", "dao", "blade", }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 0);
		set("is_monitored", 1);
		set("no_sell", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_put", 1);
		set("material", "bone");
		set("name_recognized", "破势刀");
		set("long", "此刀能镇邪驱魔，削铁如泥。\n");
		set("wield_msg", "$N「刷」地一声抽出一柄闪亮的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
	}
	init_blade(100);
	setup();
}
