// SN::kH=N2]XbHGBi@P5
// ITEM Made by player(狐战四野:ydzzjz) /data/item/y/ydzzjz-zdao.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Nov  7 23:31:39 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m钢刀[2;37;0m", ({ "zdao" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
剑柄上刻着一行小字：狐战四野(ydzzjz)
");
	set("value", 2100000);
	set("point", 145);
	set("material", "magic stone");
	set("wield_msg", "[1;36m$N双臂轻轻一展，一股劲气登时笼罩全身！[2;37;0m\n");
	set("unwield_msg", "[1;33m$N纵声长笑，丹田中内力激荡，衣角悄然扬起，似乎要乘风而去，飘飘欲仙！[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
