// SN:16G`@]X;7D;ZS7T0
// ITEM Made by player(洛神:lshen) /data/item/l/lshen-cash.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Nov 12 00:42:14 2003
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("二十八张银票[2;37;0m", ({ "cash" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
不能兑现的银票。[2;37;0m
剑柄上刻着一行小字：洛神(lshen)
");
	set("value", 2100000);
	set("point", 220);
	set("material", "magic stone");
	set("wield_msg", "\n$N从皮包里抽出二十八张银票。\n[2;37;0m\n");
	set("unwield_msg", "\n$N将二十八张银票放回皮夹里。\n[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
