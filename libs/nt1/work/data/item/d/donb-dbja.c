// SN:2GV1UUHVD7KV\f;n
// ITEM Made by player(呆老二:donb) /data/item/d/donb-dbja.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Aug  7 21:20:47 2003
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("长剑[2;37;0m", ({ "dbja" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
剑柄上刻着一行小字：呆老二(donb)
");
	set("value", 2100000);
	set("point", 190);
	set("material", "magic stone");
	set("wield_msg", "「唰」的一声抽出一柄长剑握在手中。[2;37;0m\n");
	set("unwield_msg", "将手中的长剑插回剑鞘。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
