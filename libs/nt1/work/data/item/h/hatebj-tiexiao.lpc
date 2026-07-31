// SN:\hJjhkJ>7LPgCQha
// ITEM Made by player(王从阳:hatebj) /data/item/h/hatebj-tiexiao.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Oct 11 02:30:14 2004
#include <ansi.h>
#include <weapon.h>

inherit XSWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m玄铁箫[2;37;0m", ({ "tiexiao" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "支");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一支箫。
箫柄上刻着一行小字：王从阳(hatebj)
");
	set("value", 2100000);
	set("point", 100);
	set("material", "magic stone");
	set("wield_msg", "$N取出一支$n，怔怔地发了一会儿呆。[2;37;0m\n");
	set("unwield_msg", "$N将$n收回怀里。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_xsword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
