// SN:danh\mfBNY`Ya;dF
// ITEM Made by player(一灯:aaron) /data/item/a/aaron-zhujian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jun  9 13:35:42 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("竹剑[2;37;0m", ({ "zhujian" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
这是一把练习剑法用的竹剑。[2;37;0m
剑柄上刻着一行小字：一灯(aaron)
");
	set("value", 2100000);
	set("point", 142);
	set("material", "magic stone");
	set("wield_msg", "∮你拿出一把竹剑，握在手中。[2;37;0m\n");
	set("unwield_msg", "∮你放下手中的竹剑。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
