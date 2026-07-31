// SN:C3gJO^I`Mi1o9REk
// ITEM Made by player(血莲使者:shadowredl) /data/item/s/shadowredl-dsae.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat May  8 02:52:15 2004
#include <ansi.h>
#include <armor.h>

inherit WRISTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m毒手[1;33m腕[2;37;0m", ({ "dsae" }));
	set_weight(3000);
	set("item_make", 1);
	set("unit", "对");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一对护腕。
护腕缘上刻着一行小字：血莲使者(shadowredl)
");
	set("value", 2100000);
	set("point", 85);
	set("material", "magic stone");
	set("wear_msg", "[33m$N[33m装备[1;32m毒手[1;33m腕[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;32m毒手[1;33m腕[2;37;0m[33m。[2;37;0m\n");
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
