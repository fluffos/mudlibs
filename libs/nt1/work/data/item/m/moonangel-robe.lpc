// SN:C<G`M^]mb_<E1bI<
// ITEM Made by player(月天使:moonangel) /data/item/m/moonangel-robe.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat May 29 08:11:44 2004
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[31m暗夜之星辰羽绫[2;37;0m", ({ "robe" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "张");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一张护甲。
护甲缘上刻着一行小字：月天使(moonangel)
");
	set("value", 2100000);
	set("point", 280);
	set("material", "magic stone");
	set("wear_msg", "$n[1;33m的魔力在[1;37m$N[1;33m身上刻划出一条条的[1;37m光之轨迹[1;33m，让奇迹的想像力一点一滴注入[1;37m$N[1;33m体内！[2;37;0m\n");
	set("remove_msg", "[1;33m当[1;37m$N[1;33m卸下$n[1;33m之时，时间的魔力也同告终止．．．[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 15 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
