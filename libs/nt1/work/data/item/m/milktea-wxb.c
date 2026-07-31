// SN:mlAJgYALI`kKn06T
// ITEM Made by player(奶茶:milktea) /data/item/m/milktea-wxb.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Jan 26 11:01:27 2004
#include <ansi.h>
#include <weapon.h>

inherit XSWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;35m天下无双[2;37;0m", ({ "wxb" }));
	set_weight(1350);
	set("item_make", 1);
	set("unit", "支");
	set("long", "这是由[37m精铁[2;37;0m炼制而成的一支箫。
箫柄上刻着一行小字：奶茶(milktea)
");
	set("value", 700000);
	set("point", 30);
	set("material", "iron");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一支[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_xsword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
