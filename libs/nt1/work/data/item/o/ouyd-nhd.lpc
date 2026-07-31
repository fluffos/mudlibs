// SN:WOD]PT^4UUT^N?nR
// ITEM Made by player(欧阳毒:ouyd) /data/item/o/ouyd-nhd.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Feb  8 15:43:44 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m你好毒[2;37;0m", ({ "nhd" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
铁掌缘上刻着一行小字：欧阳毒(ouyd)
");
	set("value", 2100000);
	set("point", 234);
	set("material", "magic stone");
	set("wear_msg", "$N掏出一些碧青色的药丸在手掌上涂涂抹抹。\n$N似乎觉得分量不够，又掏出一些碧青色的药丸在手掌上涂涂抹抹。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;32m你好毒[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/strike", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/hand", 10);

	setup();
}

string long() { return query("long") + item_long(); }
