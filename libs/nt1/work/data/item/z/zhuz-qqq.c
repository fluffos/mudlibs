// SN:T@MHc=l6o8BmPPln
// ITEM Made by player(真天蓬:zhuz) /data/item/z/zhuz-qqq.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Aug 10 17:08:45 2004
#include <ansi.h>
#include <armor.h>

inherit WRISTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("呵呵[2;37;0m", ({ "qqq" }));
	set_weight(2250);
	set("item_make", 1);
	set("unit", "对");
	set("long", "这是由[37m精铁[2;37;0m炼制而成的一对护腕。
护腕缘上刻着一行小字：真天蓬(zhuz)
");
	set("value", 700000);
	set("point", 15);
	set("material", "iron");
	set("wear_msg", "[33m$N[33m装备呵呵[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了呵呵[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/cuff", apply_armor() / 6 + 1);
	set("armor_prop/claw", apply_armor() / 6 + 1);
	set("armor_prop/dagger", apply_armor() / 6 + 1);
	set("armor_prop/strike", apply_armor() / 6 + 1);
	set("armor_prop/blade", apply_armor() / 6 + 1);
	set("armor_prop/unarmed", apply_armor() / 6 + 1);
	set("armor_prop/staff", apply_armor() / 6 + 1);
	set("armor_prop/sword", apply_armor() / 6 + 1);
	set("armor_prop/hammer", apply_armor() / 6 + 1);
	set("armor_prop/whip", apply_armor() / 6 + 1);
	set("armor_prop/club", apply_armor() / 6 + 1);
	set("armor_prop/parry", apply_armor() / 6 + 1);
	set("armor_prop/hand", apply_armor() / 6 + 1);
	set("armor_prop/stick", apply_armor() / 6 + 1);
	set("armor_prop/finger", apply_armor() / 6 + 1);
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
