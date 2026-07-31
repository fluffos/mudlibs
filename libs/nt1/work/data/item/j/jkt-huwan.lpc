// SN:PC\ngnd4CRkBQ@EX
// ITEM Made by player(渡独:jkt) /data/item/j/jkt-huwan.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun May  9 05:00:14 2004
#include <ansi.h>
#include <armor.h>

inherit WRISTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m大[1;33m金刚[1;32m护腕[2;37;0m", ({ "huwan" }));
	set_weight(3000);
	set("item_make", 1);
	set("unit", "对");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一对护腕。
[1;31m这是当年广力罗汉用来降魔的护腕传说，有着神奇的力量。[2;37;0m
护腕缘上刻着一行小字：渡独(jkt)
");
	set("value", 2100000);
	set("point", 112);
	set("material", "magic stone");
	set("wear_msg", "[33m$N[33m装备[1;36m大[1;33m金刚[1;32m护腕[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;36m大[1;33m金刚[1;32m护腕[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/sword", apply_armor() / 6 + 1);
	set("armor_prop/whip", apply_armor() / 6 + 1);
	set("armor_prop/parry", apply_armor() / 6 + 1);
	set("armor_prop/cuff", apply_armor() / 6 + 1);
	set("armor_prop/armor", apply_armor());
	set("armor_prop/club", apply_armor() / 6 + 1);
	set("armor_prop/blade", apply_armor() / 6 + 1);
	set("armor_prop/hand", apply_armor() / 6 + 1);
	set("armor_prop/hammer", apply_armor() / 6 + 1);
	set("armor_prop/strike", apply_armor() / 6 + 1);
	set("armor_prop/finger", apply_armor() / 6 + 1);
	set("armor_prop/claw", apply_armor() / 6 + 1);
	set("armor_prop/unarmed", apply_armor() / 6 + 1);
	set("armor_prop/stick", apply_armor() / 6 + 1);
	set("armor_prop/dagger", apply_armor() / 6 + 1);
	set("armor_prop/staff", apply_armor() / 6 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
