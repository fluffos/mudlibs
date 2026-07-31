// SN:85CK1CM:I9A0Wn5Q
// ITEM Made by player(圣火令:delphi) /data/item/d/delphi-armor.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Apr  2 09:10:10 2004
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[35m紫衫龙王[2;37;0m", ({ "armor" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "张");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一张护甲。
[35m这是明教传说中的圣衣，是四大护法中紫杉龙王的化身！[2;37;0m
护甲缘上刻着一行小字：圣火令(delphi)
");
	set("value", 2100000);
	set("point", 140);
	set("material", "magic stone");
	set("wear_msg", "[33m$N[33m装备[2;37;0m[35m紫衫龙王[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[2;37;0m[35m紫衫龙王[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/parry", apply_armor() / 15 + 1);
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
