// SN:L_1\5B8n61=O;=;7
// ITEM Made by player(圣火令:delphi) /data/item/d/delphi-shoes.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Apr  2 09:20:16 2004
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m青翼蝠王[2;37;0m", ({ "shoes" }));
	set_weight(3600);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双靴子。
[1;36m这是明教传说中的魔靴，是四大护法中青翼蝠王的化身！[2;37;0m
靴子缘上刻着一行小字：圣火令(delphi)
");
	set("value", 2100000);
	set("point", 70);
	set("material", "magic stone");
	set("wear_msg", "[33m$N[33m装备[1;36m青翼蝠王[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;36m青翼蝠王[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
