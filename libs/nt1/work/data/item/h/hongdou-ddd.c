// SN:UZ9ZBHjJXn@hJD=^
// ITEM Made by player(红豆:hongdou) /data/item/h/hongdou-ddd.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jul 30 23:23:14 2003
#include <ansi.h>
#include <weapon.h>

inherit DAGGER;
inherit F_ITEMMAKE;

void create()
{
	set_name("啦拉[2;37;0m", ({ "ddd" }));
	set_weight(1350);
	set("item_make", 1);
	set("unit", "支");
	set("long", "这是由[37m精铁[2;37;0m炼制而成的一支短兵。
短兵柄上刻着一行小字：红豆(hongdou)
");
	set("value", 700000);
	set("point", 30);
	set("material", "iron");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一支[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_dagger(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
