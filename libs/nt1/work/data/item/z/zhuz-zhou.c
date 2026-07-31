// SN:U?3aN88gKf6hMU3o
// ITEM Made by player(真天蓬:zhuz) /data/item/z/zhuz-zhou.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Aug  6 15:52:05 2004
#include <ansi.h>
#include <armor.h>

inherit WRISTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m猪肘[2;37;0m", ({ "zhou" }));
	set_weight(2500);
	set("item_make", 1);
	set("unit", "对");
	set("long", "这是由[37m上古寒铁[2;37;0m炼制而成的一对护腕。
护腕缘上刻着一行小字：真天蓬(zhuz)
");
	set("value", 1500000);
	set("point", 37);
	set("material", "steel");
	set("wear_msg", "[33m$N[33m装备[1;32m猪肘[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;32m猪肘[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/whip", apply_armor() / 6 + 1);
	set("armor_prop/armor", apply_armor());
	set("armor_prop/club", apply_armor() / 6 + 1);
	set("armor_prop/hand", apply_armor() / 6 + 1);
	set("armor_prop/parry", apply_armor() / 6 + 1);
	set("armor_prop/stick", apply_armor() / 6 + 1);
	set("armor_prop/finger", apply_armor() / 6 + 1);
	set("armor_prop/dagger", apply_armor() / 6 + 1);
	set("armor_prop/cuff", apply_armor() / 6 + 1);
	set("armor_prop/claw", apply_armor() / 6 + 1);
	set("armor_prop/strike", apply_armor() / 6 + 1);
	set("armor_prop/blade", apply_armor() / 6 + 1);
	set("armor_prop/unarmed", apply_armor() / 6 + 1);
	set("armor_prop/staff", apply_armor() / 6 + 1);
	set("armor_prop/sword", apply_armor() / 6 + 1);
	set("armor_prop/hammer", apply_armor() / 6 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
