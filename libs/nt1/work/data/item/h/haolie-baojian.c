// SN:kalhDRZG[aBOa<@Z
// ITEM Made by player(段星:haolie) /data/item/h/haolie-baojian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Nov  2 19:04:22 2003
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m雷荧[2;37;0m", ({ "baojian" }));
	set_weight(45000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[36m玄铁[2;37;0m炼制而成的一柄剑。
[1;34m听说拔出它的时候，能隐隐的听到雷声[2;37;0m
剑柄上刻着一行小字：段星(haolie)
");
	set("value", 1500000);
	set("point", 122);
	set("material", "steel");
	set("wield_msg", "[1;34m只见$N[1;37m把雷荧[1;34m拿到手中。唼时，天地变色，日月无光，天际隐隐传来隆隆的雷声[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
