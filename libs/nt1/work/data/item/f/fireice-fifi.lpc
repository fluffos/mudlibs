// SN:41C7K]=j6F5ZO`6o
// ITEM Made by player(水灵:fireice) /data/item/f/fireice-fifi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Nov 24 09:35:53 2003
#include <ansi.h>
#include <armor.h>

inherit WRISTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("爱情神剑[2;37;0m", ({ "fifi" }));
	set_weight(3000);
	set("item_make", 1);
	set("unit", "对");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一对护腕。
[1;36m它充满了神的力量[2;37;0m
护腕缘上刻着一行小字：水灵(fireice)
");
	set("value", 2100000);
	set("point", 25);
	set("material", "magic stone");
	set("wear_msg", "[1;36m轻轻一舞，神龙出鞘[2;37;0m\n");
	set("remove_msg", "[1;36m轻轻一舞，神龙回鞘[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/strike", apply_armor() / 6 + 1);
	set("armor_prop/armor", apply_armor());
	set("armor_prop/staff", apply_armor() / 6 + 1);
	set("armor_prop/hand", apply_armor() / 6 + 1);
	set("armor_prop/whip", apply_armor() / 6 + 1);
	set("armor_prop/hammer", apply_armor() / 6 + 1);
	set("armor_prop/claw", apply_armor() / 6 + 1);
	set("armor_prop/sword", apply_armor() / 6 + 1);
	set("armor_prop/stick", apply_armor() / 6 + 1);
	set("armor_prop/club", apply_armor() / 6 + 1);
	set("armor_prop/cuff", apply_armor() / 6 + 1);
	set("armor_prop/parry", apply_armor() / 6 + 1);
	set("armor_prop/finger", apply_armor() / 6 + 1);
	set("armor_prop/unarmed", apply_armor() / 6 + 1);
	set("armor_prop/dagger", apply_armor() / 6 + 1);
	set("armor_prop/blade", apply_armor() / 6 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
