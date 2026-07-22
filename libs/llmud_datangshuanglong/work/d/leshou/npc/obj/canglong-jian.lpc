
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name(HIG"苍龙剑"NOR, ({ "canglong jian", "jian" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄长剑，剑身上刻着「苍龙」二字。\n");
		set("value", 1500);
		set("life",20);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
	}
	init_sword(20,50,50);
	setup();
}
