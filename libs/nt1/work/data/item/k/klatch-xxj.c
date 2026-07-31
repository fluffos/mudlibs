// SN:n6V<FmkNK@QD2ZbB
// ITEM Made by player(闲聊:klatch) /data/item/k/klatch-xxj.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Nov 12 19:33:13 2003
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("闲甲[2;37;0m", ({ "xxj" }));
	set_weight(1050);
	set("item_make", 1);
	set("unit", "张");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一张护甲。
护甲缘上刻着一行小字：闲聊(klatch)
");
	set("value", 2100000);
	set("point", 176);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备闲甲[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了闲甲[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 15 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
