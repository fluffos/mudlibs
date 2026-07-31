// SN:H^hRIgnD]G5_fJ?=
// ITEM Made by player(雷斯魔:lsm) /data/item/l/lsm-dark.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Apr  9 18:27:28 2004
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
[37m是由黑暗邪恶力量合成的一把邪恶之剑[2;37;0m
剑柄上刻着一行小字：雷斯魔(lsm)
");
	set("value", 2100000);
	set("point", 330);
	set("material", "magic stone");
	set("wield_msg", "[1;36m天空忽然传来了几声冷笑，霎时间乌云密布！一道[1;33m闪电[1;36m从天而降！[2;37;0m\n");
	set("unwield_msg", "[1;31m刹那间只见$n[1;31m全身顿时浮现出一层刚猛的劲气，将你全全笼罩。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
