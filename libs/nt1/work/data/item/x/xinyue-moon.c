// SN:7`T=CDm`HgJ^8=Dm
// ITEM Made by player(慕容新月:xinyue) /data/item/x/xinyue-moon.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Apr  3 16:29:45 2004
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[37m月神战衣[2;37;0m", ({ "moon" }));
	set_weight(1400);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一件战衣。
[37m一件白色的战衣，衣裳上冰霜之光隐隐流动，触手生凉。[2;37;0m
战衣缘上刻着一行小字：慕容新月(xinyue)
");
	set("value", 2100000);
	set("point", 333);
	set("material", "silk");
	set("wear_msg", "[37m突然间你眼前一片白茫茫的冷光映来，$N已经穿上一件无风自舞的白色战衣，在月光的影映之下，飘摇若仙。[2;37;0m\n");
	set("remove_msg", "[37m蓦然间你的眼前茫茫的冷光消失殆尽，$N的身影在茫茫中显现出来，神情冰冷如霜，凛然不可侵犯。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
