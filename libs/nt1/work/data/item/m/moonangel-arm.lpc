// SN:SRKi\VK\^bWBikX4
// ITEM Made by player(月天使:moonangel) /data/item/m/moonangel-arm.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat May 29 08:16:47 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[31m暗夜之珠玉掌链[2;37;0m", ({ "arm" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
铁掌缘上刻着一行小字：月天使(moonangel)
");
	set("value", 2100000);
	set("point", 350);
	set("material", "magic stone");
	set("wear_msg", "$n[1;33m的魔力在[1;37m$N[1;33m身上刻划出一条条的[1;37m光之轨迹[1;33m，让奇迹的想像力一点一滴注入[1;37m$N[1;33m体内！[2;37;0m\n");
	set("remove_msg", "[1;33m当[1;37m$N[1;33m卸下$n[1;33m之时，时间的魔力也同告终止．．．[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/hand", 10);
	set("armor_prop/strike", 10);

	setup();
}

string long() { return query("long") + item_long(); }
