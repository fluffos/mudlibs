// SN:E@^\UaQ5NoIFjf[V
// ITEM Made by player(段子羽:windsmile) /data/item/w/windsmile-dark.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Apr  3 17:36:30 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[37m黑夜魔咒[2;37;0m", ({ "dark" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
剑柄上刻着一行小字：段子羽(windsmile)
");
	set("value", 2100000);
	set("point", 780);
	set("material", "magic stone");
	set("wield_msg", "[1;36m天空忽然传来了几声冷笑，霎时间乌云密布！一道[1;33m闪电[1;36m从天而降！[2;37;0m\n");
	set("unwield_msg", "[1;31m刹那间只见$N全身顿时浮现出一层刚猛的劲气，将你全全笼罩。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
